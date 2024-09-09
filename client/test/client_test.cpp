// Run with:
//      g++ -std=c++11 -I /usr/local/include -L /usr/local/lib test/client_test.cpp -lgtest -lgtest_main -pthread -o client_test
//      ./client_test

#include "Client.h"
#include "UI.h"
#include "Encryption.h"
#include <gtest/gtest.h>
#include <thread>
#include <iostream>

// Mock server setup to simulate server behavior for testing
class MockServer {
public:
    void startServer(int port) {
        serverSockfd = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in serverAddress;
        serverAddress.sin_family = AF_INET;
        serverAddress.sin_port = htons(port);
        serverAddress.sin_addr.s_addr = INADDR_ANY;

        bind(serverSockfd, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
        listen(serverSockfd, 5);
    }

    int acceptClient() {
        struct sockaddr_in clientAddress;
        socklen_t clientLen = sizeof(clientAddress);
        return accept(serverSockfd, (struct sockaddr *)&clientAddress, &clientLen);
    }

    void stopServer() {
        close(serverSockfd);
    }

private:
    int serverSockfd;
};

// Test: Check if client can connect to a mock server
TEST(ClientTest, ConnectToServer) {
    MockServer server;
    std::thread serverThread([&]() {
        server.startServer(12345);
    });

    // Allow time for server to start
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    ChatClient client("127.0.0.1", 12345);
    ASSERT_TRUE(client.connectToServer()) << "Client should successfully connect to the server";

    server.stopServer();
    serverThread.join();
}

// Test: Encryption and decryption functionality
TEST(EncryptionTest, EncryptDecrypt) {
    std::string originalMessage = "Hello, World!";
    std::string encryptedMessage = Encryption::encryptMessage(originalMessage);
    std::string decryptedMessage = Encryption::decryptMessage(encryptedMessage);

    ASSERT_EQ(decryptedMessage, originalMessage) << "Decrypted message should match the original message";
}

// Test: UI functionality for user input
TEST(UITest, GetUserInput) {
    // Simulate user input
    std::istringstream input("Test message");
    std::cin.rdbuf(input.rdbuf()); // Redirect std::cin to simulate input

    std::string userInput = ChatUI::getUserInput();
    ASSERT_EQ(userInput, "Test message") << "User input should match the simulated input";
}

// Test: Client message sending (simulated by intercepting send() calls)
TEST(ClientTest, SendMessage) {
    MockServer server;
    std::thread serverThread([&]() {
        server.startServer(12345);
        int clientSockfd = server.acceptClient(); // Simulate server accepting client
        char buffer[1024];
        int bytesReceived = recv(clientSockfd, buffer, sizeof(buffer), 0);
        ASSERT_GT(bytesReceived, 0) << "Server should receive message";
        std::string receivedMessage(buffer, bytesReceived);
        ASSERT_EQ(Encryption::decryptMessage(receivedMessage), "Test message") << "Server should receive decrypted message";
    });

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    ChatClient client("127.0.0.1", 12345);
    ASSERT_TRUE(client.connectToServer()) << "Client should successfully connect to the server";
    client.sendMessage("Test message");

    serverThread.join();
    server.stopServer();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

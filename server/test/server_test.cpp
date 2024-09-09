// Run with:
//      g++ -std=c++11 -I /usr/local/include -L /usr/local/lib test/server_test.cpp -lgtest -lgtest_main -pthread -o server_test
//      ./server_test

#include "Server.h"
#include "ClientHandler.h"
#include "Encryption.h"
#include "Logger.h"
#include "FaultTolerance.h"
#include "LoadBalancer.h"
#include <gtest/gtest.h>
#include <thread>
#include <vector>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Mock client to test server functionality
class MockClient {
public:
    int connectToServer(const std::string& serverIP, int port) {
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            return -1;
        }

        struct sockaddr_in serverAddress;
        serverAddress.sin_family = AF_INET;
        serverAddress.sin_port = htons(port);
        inet_pton(AF_INET, serverIP.c_str(), &serverAddress.sin_addr);

        if (connect(sockfd, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
            return -1;
        }

        return sockfd;
    }

    void sendMessage(int sockfd, const std::string& message) {
        send(sockfd, message.c_str(), message.size(), 0);
    }

    std::string receiveMessage(int sockfd) {
        char buffer[1024];
        int bytesReceived = recv(sockfd, buffer, sizeof(buffer), 0);
        return std::string(buffer, bytesReceived);
    }

    void closeConnection(int sockfd) {
        close(sockfd);
    }
};

// Test: Check if the server starts successfully
TEST(ServerTest, StartServer) {
    ChatServer server(12345);
    ASSERT_TRUE(server.start()) << "Server should start successfully";

    // Shutdown the server
    server.shutdown();
}

// Test: Client connects to the server and receives a welcome message
TEST(ServerTest, ClientConnectAndSendMessage) {
    // Start the server
    ChatServer server(12345);
    ASSERT_TRUE(server.start());

    std::thread serverThread([&]() {
        server.acceptClients();
    });

    // Allow time for server to start
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    // Mock client connects to the server
    MockClient client;
    int sockfd = client.connectToServer("127.0.0.1", 12345);
    ASSERT_GT(sockfd, 0) << "Client should connect successfully";

    // Client sends a message
    client.sendMessage(sockfd, "Hello, Server!");

    // Client should receive an echo message from the server
    std::string response = client.receiveMessage(sockfd);
    ASSERT_EQ(Encryption::decryptMessage(response), "Hello, Server!") << "Client should receive an echoed message";

    // Clean up
    client.closeConnection(sockfd);
    server.shutdown();
    serverThread.join();
}

// Test: Encryption and decryption functionality
TEST(EncryptionTest, EncryptDecrypt) {
    std::string originalMessage = "Test Message";
    std::string encryptedMessage = Encryption::encryptMessage(originalMessage);
    std::string decryptedMessage = Encryption::decryptMessage(encryptedMessage);

    ASSERT_EQ(decryptedMessage, originalMessage) << "Decrypted message should match the original";
}

// Test: Logger writes messages to log file
TEST(LoggerTest, LogMessage) {
    // Clear previous logs
    std::ofstream logFile("logs/server.log", std::ios::trunc);
    logFile.close();

    // Log a test message
    Logger::log("Test log message");

    // Read the log file
    std::ifstream logFileIn("logs/server.log");
    std::string logContent;
    std::getline(logFileIn, logContent);

    ASSERT_EQ(logContent, "Test log message") << "Log file should contain the logged message";
}

// Test: Fault tolerance health check
TEST(FaultToleranceTest, ServerHealthCheck) {
    FaultTolerance::checkServerHealth();
    // We can't easily test the output of a health check, but we can assert the function runs successfully
    ASSERT_NO_THROW(FaultTolerance::checkServerHealth()) << "Fault tolerance health check should run without errors";
}

// Test: Load balancer selects a server
TEST(LoadBalancerTest, ChooseServer) {
    std::vector<int> serverList = { 1, 2, 3 };
    int chosenServer = LoadBalancer::chooseServer(serverList);
    ASSERT_TRUE(chosenServer >= 1 && chosenServer <= 3) << "Load balancer should select a valid server from the list";
}

// Test: Server handles multiple clients (stress test)
TEST(ServerTest, MultipleClients) {
    // Start the server
    ChatServer server(12345);
    ASSERT_TRUE(server.start());

    std::thread serverThread([&]() {
        server.acceptClients();
    });

    // Allow time for server to start
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    const int clientCount = 5;
    std::vector<int> clientSockets(clientCount);
    MockClient clients[clientCount];

    // Connect multiple clients to the server
    for (int i = 0; i < clientCount; i++) {
        clientSockets[i] = clients[i].connectToServer("127.0.0.1", 12345);
        ASSERT_GT(clientSockets[i], 0) << "Client " << i + 1 << " should connect successfully";
    }

    // Send and receive messages for each client
    for (int i = 0; i < clientCount; i++) {
        clients[i].sendMessage(clientSockets[i], "Client " + std::to_string(i + 1) + " message");
        std::string response = clients[i].receiveMessage(clientSockets[i]);
        ASSERT_EQ(Encryption::decryptMessage(response), "Client " + std::to_string(i + 1) + " message") << "Client " << i + 1 << " should receive its own message";
        clients[i].closeConnection(clientSockets[i]);
    }

    // Shutdown the server
    server.shutdown();
    serverThread.join();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

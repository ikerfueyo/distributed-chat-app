#include "Client.h"
#include "UI.h"
#include "Encryption.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

ChatClient::ChatClient(const std::string& serverIP, int port) : serverIP(serverIP), serverPort(port), sockfd(-1) {}

bool ChatClient::connectToServer() {
    std::ofstream logFile("logs/client.log", std::ios::app);  // Open log file in append mode
    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        logFile << "Error creating socket" << std::endl;
        std::cerr << "Error creating socket" << std::endl;
        return false;
    }

    // Define server address
    struct sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(serverPort);

    // Convert IP from text to binary
    if (inet_pton(AF_INET, serverIP.c_str(), &serverAddress.sin_addr) <= 0) {
        logFile << "Invalid server IP address" << std::endl;
        std::cerr << "Invalid server IP address" << std::endl;
        return false;
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        logFile << "Failed to connect to server" << std::endl;
        std::cerr << "Failed to connect to server" << std::endl;
        return false;
    }

    logFile << "Connected to server at " << serverIP << ":" << serverPort << std::endl;
    std::cout << "Connected to server" << std::endl;
    logFile.close();
    return true;
}

void ChatClient::sendMessage(const std::string& message) {
    std::ofstream logFile("logs/client.log", std::ios::app);
    std::string encryptedMessage = ClientEncryption::encryptMessage(message);
    send(sockfd, encryptedMessage.c_str(), encryptedMessage.size(), 0);
    logFile << "Sent message: " << message << std::endl;
    logFile.close();
}

void ChatClient::receiveMessages() {
    char buffer[1024];
    while (true) {
        memset(buffer, 0, sizeof(buffer));
        int bytesReceived = recv(sockfd, buffer, sizeof(buffer), 0);
        if (bytesReceived > 0) {
            std::string decryptedMessage = ClientEncryption::decryptMessage(std::string(buffer, bytesReceived));
            ChatUI::displayMessage(decryptedMessage);
        }
    }
}

void ChatClient::start() {
    if (!connectToServer()) {
        return;
    }

    // Launch a thread to receive messages
    std::thread receiveThread(&ChatClient::receiveMessages, this);
    receiveThread.detach();

    // Main loop to send messages
    while (true) {
        std::string message = ChatUI::getUserInput();
        if (message == "/quit") {
            break;
        }
        sendMessage(message);
    }

    // Close socket before exiting
    close(sockfd);
}

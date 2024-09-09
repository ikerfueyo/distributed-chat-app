#include "Server.h"
#include "ClientHandler.h"
#include "Logger.h"
#include "FaultTolerance.h"
#include "LoadBalancer.h"
#include <iostream>
#include <thread>
#include <vector>
#include <netinet/in.h>
#include <unistd.h>

ChatServer::ChatServer(int port) : serverPort(port), serverSockfd(-1) {}

bool ChatServer::start() {
    Logger::log("Starting server...");

    // Create a socket
    serverSockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSockfd < 0) {
        Logger::log("Error creating socket");
        return false;
    }

    // Set up server address structure
    struct sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(serverPort);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the port
    if (bind(serverSockfd, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0) {
        Logger::log("Error binding socket");
        return false;
    }

    // Start listening for connections
    if (listen(serverSockfd, 5) < 0) {
        Logger::log("Error listening on socket");
        return false;
    }

    Logger::log("Server started successfully on port " + std::to_string(serverPort));
    return true;
}

void ChatServer::acceptClients() {
    while (true) {
        struct sockaddr_in clientAddress;
        socklen_t clientLen = sizeof(clientAddress);
        int clientSockfd = accept(serverSockfd, (struct sockaddr *)&clientAddress, &clientLen);
        
        if (clientSockfd >= 0) {
            Logger::log("Client connected");
            // Spawn a new thread to handle the client
            std::thread clientThread(&ClientHandler::handleClient, ClientHandler(), clientSockfd);
            clientThread.detach(); // Detach the thread to let it run independently
        }
    }
}

void ChatServer::shutdown() {
    close(serverSockfd);
    Logger::log("Server shutdown");
}

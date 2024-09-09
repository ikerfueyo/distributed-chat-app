#include "ClientHandler.h"
#include "Logger.h"
#include "Encryption.h"
#include <unistd.h>
#include <cstring>
#include <iostream>

void ClientHandler::handleClient(int clientSockfd) {
    char buffer[1024];
    while (true) {
        memset(buffer, 0, sizeof(buffer));
        int bytesReceived = recv(clientSockfd, buffer, sizeof(buffer), 0);
        if (bytesReceived > 0) {
            std::string message = Encryption::decryptMessage(std::string(buffer, bytesReceived));
            Logger::log("Received message: " + message);
            // Echo message back to client
            std::string encryptedMessage = Encryption::encryptMessage(message);
            send(clientSockfd, encryptedMessage.c_str(), encryptedMessage.size(), 0);
        } else {
            Logger::log("Client disconnected");
            close(clientSockfd);
            break;
        }
    }
}

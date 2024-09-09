#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <thread>

class ChatClient {
public:
    ChatClient(const std::string& serverIP, int port);
    
    // Connect to the chat server
    bool connectToServer();

    // Send a message to the server
    void sendMessage(const std::string& message);

    // Receive messages from the server
    void receiveMessages();

    // Start the client to handle messaging
    void start();

private:
    std::string serverIP;
    int serverPort;
    int sockfd;
};

#endif // CLIENT_H

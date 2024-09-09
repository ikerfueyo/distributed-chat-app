#ifndef SERVER_H
#define SERVER_H

#include <string>

class ChatServer {
public:
    ChatServer(int port);

    // Start the server and begin listening for connections
    bool start();

    // Accept client connections and assign them to client handlers
    void acceptClients();

    // Shutdown the server
    void shutdown();

private:
    int serverPort;
    int serverSockfd; // Server socket descriptor
};

#endif // SERVER_H

#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H

class ClientHandler {
public:
    // Handle client connection, receive and send messages
    void handleClient(int clientSockfd);
};

#endif // CLIENTHANDLER_H

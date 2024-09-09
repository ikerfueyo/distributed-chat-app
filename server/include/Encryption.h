#ifndef SERVER_ENCRYPTION_H
#define SERVER_ENCRYPTION_H

#include <string>
#include <openssl/rsa.h>
#include "Encryption.h"  // Include the shared encryption functions

class ServerEncryption {
public:
    // Load the server's private RSA key from a PEM file
    static RSA* loadServerPrivateKey(const std::string &privateKeyFile);
    
    // Decrypt the AES key sent by the client using the server's RSA private key (Key Exchange)
    static std::string decryptAESKeyFromClient(const std::string &encryptedAESKey, RSA *serverPrivateKey);
    
    // AES Encryption for messages
    static std::string encryptMessage(const std::string &message, const std::string &aesKey);
    
    // AES Decryption for messages
    static std::string decryptMessage(const std::string &encryptedMessage, const std::string &aesKey);
};

#endif // SERVER_ENCRYPTION_H

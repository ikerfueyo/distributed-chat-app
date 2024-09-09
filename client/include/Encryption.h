#ifndef CLIENT_ENCRYPTION_H
#define CLIENT_ENCRYPTION_H

#include <string>
#include <openssl/rsa.h>
#include "Encryption.h"  // Include the shared encryption functions

class ClientEncryption {
public:
    // Load the server's public RSA key from a PEM file
    static RSA* loadServerPublicKey(const std::string &publicKeyFile);
    
    // Encrypt the AES key with the server's RSA public key (Key Exchange)
    static std::string exchangeAESKeyWithServer(const std::string &aesKey, RSA *serverPublicKey);
    
    // AES Encryption for messages
    static std::string encryptMessage(const std::string &message, const std::string &aesKey);
    
    // AES Decryption for messages
    static std::string decryptMessage(const std::string &encryptedMessage, const std::string &aesKey);
};

#endif // CLIENT_ENCRYPTION_H

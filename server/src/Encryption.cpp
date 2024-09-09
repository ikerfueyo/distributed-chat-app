#include "Encryption.h"
#include <openssl/pem.h>
#include <iostream>
#include <fstream>

// Load the server's RSA private key from a PEM file
RSA* ServerEncryption::loadServerPrivateKey(const std::string &privateKeyFile) {
    BIO* bio = BIO_new_file(privateKeyFile.c_str(), "r");
    RSA* rsaPrivateKey = PEM_read_bio_RSAPrivateKey(bio, NULL, NULL, NULL);
    BIO_free(bio);

    if (!rsaPrivateKey) {
        throw std::runtime_error("Failed to load server's private key");
    }
    return rsaPrivateKey;
}

// Key exchange: Decrypt AES key sent by the client using the server's RSA private key
std::string ServerEncryption::decryptAESKeyFromClient(const std::string &encryptedAESKey, RSA *serverPrivateKey) {
    return Encryption::decryptRSA(encryptedAESKey, serverPrivateKey);
}

// AES Encryption for messages
std::string ServerEncryption::encryptMessage(const std::string &message, const std::string &aesKey) {
    return Encryption::encryptAES(message, aesKey);
}

// AES Decryption for messages
std::string ServerEncryption::decryptMessage(const std::string &encryptedMessage, const std::string &aesKey) {
    return Encryption::decryptAES(encryptedMessage, aesKey);
}

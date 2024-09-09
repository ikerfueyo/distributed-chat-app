#include "Encryption.h"
#include <openssl/pem.h>
#include <iostream>
#include <fstream>

// Load the server's RSA public key from a PEM file
RSA* ClientEncryption::loadServerPublicKey(const std::string &publicKeyFile) {
    BIO* bio = BIO_new_file(publicKeyFile.c_str(), "r");
    RSA* rsaPublicKey = PEM_read_bio_RSA_PUBKEY(bio, NULL, NULL, NULL);
    BIO_free(bio);

    if (!rsaPublicKey) {
        throw std::runtime_error("Failed to load server's public key");
    }
    return rsaPublicKey;
}

// Key exchange: Encrypt AES key with the server's RSA public key
std::string ClientEncryption::exchangeAESKeyWithServer(const std::string &aesKey, RSA *serverPublicKey) {
    return Encryption::encryptRSA(aesKey, serverPublicKey);
}

// AES Encryption for messages
std::string ClientEncryption::encryptMessage(const std::string &message, const std::string &aesKey) {
    return Encryption::encryptAES(message, aesKey);
}

// AES Decryption for messages
std::string ClientEncryption::decryptMessage(const std::string &encryptedMessage, const std::string &aesKey) {
    return Encryption::decryptAES(encryptedMessage, aesKey);
}

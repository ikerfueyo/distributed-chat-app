#include "Encryption.h"
#include <openssl/aes.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/rand.h>
#include <openssl/err.h>
#include <iostream>
#include <cstring>
#include <stdexcept>

// AES key size (256-bit)
#define AES_KEY_SIZE 32
#define AES_BLOCK_SIZE 16

// Helper function to handle OpenSSL errors
void handleOpenSSLErrors() {
    ERR_print_errors_fp(stderr);
    abort();
}

// AES Encryption: Encrypt using AES-256-CBC
std::string Encryption::encryptAES(const std::string &plainText, const std::string &key) {
    if (key.size() != AES_KEY_SIZE) {
        throw std::invalid_argument("Invalid AES key size");
    }

    // Generate a random IV
    AES_KEY aesKey;
    unsigned char iv[AES_BLOCK_SIZE];
    if (!RAND_bytes(iv, AES_BLOCK_SIZE)) {
        throw std::runtime_error("Error generating IV");
    }

    // Set up AES encryption
    if (AES_set_encrypt_key(reinterpret_cast<const unsigned char*>(key.c_str()), 256, &aesKey) < 0) {
        handleOpenSSLErrors();
    }

    // Prepare ciphertext buffer
    int inputLength = plainText.size();
    int encryptedLength = ((inputLength + AES_BLOCK_SIZE) / AES_BLOCK_SIZE) * AES_BLOCK_SIZE;
    std::string encryptedData(encryptedLength + AES_BLOCK_SIZE, '\0');

    // Store IV at the beginning of the encrypted data
    memcpy(&encryptedData[0], iv, AES_BLOCK_SIZE);

    // Encrypt the plaintext
    AES_cbc_encrypt(reinterpret_cast<const unsigned char*>(plainText.c_str()),
                    reinterpret_cast<unsigned char*>(&encryptedData[AES_BLOCK_SIZE]),
                    inputLength, &aesKey, iv, AES_ENCRYPT);

    return encryptedData;
}

// AES Decryption: Decrypt using AES-256-CBC
std::string Encryption::decryptAES(const std::string &cipherText, const std::string &key) {
    if (key.size() != AES_KEY_SIZE) {
        throw std::invalid_argument("Invalid AES key size");
    }

    // Extract the IV from the cipherText
    unsigned char iv[AES_BLOCK_SIZE];
    memcpy(iv, cipherText.c_str(), AES_BLOCK_SIZE);

    // Set up AES decryption
    AES_KEY aesKey;
    if (AES_set_decrypt_key(reinterpret_cast<const unsigned char*>(key.c_str()), 256, &aesKey) < 0) {
        handleOpenSSLErrors();
    }

    // Prepare plaintext buffer
    int encryptedLength = cipherText.size() - AES_BLOCK_SIZE;
    std::string decryptedData(encryptedLength, '\0');

    // Decrypt the ciphertext
    AES_cbc_encrypt(reinterpret_cast<const unsigned char*>(cipherText.c_str() + AES_BLOCK_SIZE),
                    reinterpret_cast<unsigned char*>(&decryptedData[0]),
                    encryptedLength, &aesKey, iv, AES_DECRYPT);

    return decryptedData;
}

// RSA Encryption (Public Key): Encrypt using RSA public key
std::string Encryption::encryptRSA(const std::string &data, RSA *publicKey) {
    std::string encryptedData(RSA_size(publicKey), '\0');
    if (RSA_public_encrypt(data.size(),
                           reinterpret_cast<const unsigned char*>(data.c_str()),
                           reinterpret_cast<unsigned char*>(&encryptedData[0]),
                           publicKey, RSA_PKCS1_OAEP_PADDING) == -1) {
        handleOpenSSLErrors();
    }
    return encryptedData;
}

// RSA Decryption (Private Key): Decrypt using RSA private key
std::string Encryption::decryptRSA(const std::string &encryptedData, RSA *privateKey) {
    std::string decryptedData(RSA_size(privateKey), '\0');
    if (RSA_private_decrypt(encryptedData.size(),
                            reinterpret_cast<const unsigned char*>(encryptedData.c_str()),
                            reinterpret_cast<unsigned char*>(&decryptedData[0]),
                            privateKey, RSA_PKCS1_OAEP_PADDING) == -1) {
        handleOpenSSLErrors();
    }
    return decryptedData;
}

// Generate RSA key pair (for testing or initialization purposes)
RSA* Encryption::generateRSAKeyPair() {
    RSA* rsa = RSA_new();
    BIGNUM* bne = BN_new();
    if (!BN_set_word(bne, RSA_F4)) {
        handleOpenSSLErrors();
    }

    if (!RSA_generate_key_ex(rsa, 2048, bne, NULL)) {
        handleOpenSSLErrors();
    }
    BN_free(bne);
    return rsa;
}

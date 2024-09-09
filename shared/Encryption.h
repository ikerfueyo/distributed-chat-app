#ifndef SHARED_ENCRYPTION_H
#define SHARED_ENCRYPTION_H

#include <string>
#include <openssl/rsa.h>

class Encryption {
public:
    // AES Encryption and Decryption
    static std::string encryptAES(const std::string &plainText, const std::string &key);
    static std::string decryptAES(const std::string &cipherText, const std::string &key);
    
    // RSA Encryption (Public Key)
    static std::string encryptRSA(const std::string &data, RSA *publicKey);
    
    // RSA Decryption (Private Key)
    static std::string decryptRSA(const std::string &encryptedData, RSA *privateKey);
    
    // RSA Key Generation (for testing or initial key generation)
    static RSA* generateRSAKeyPair();
};

#endif // SHARED_ENCRYPTION_H

#ifndef WALLET_H
#define WALLET_H

#include <string>

class Wallet {
private:
    std::string privateKey;
    std::string publicKey;
    std::string address;

public:
    Wallet();
    Wallet(const std::string& privateKey);
    ~Wallet();
    
    std::string getAddress() const;
    std::string getPublicKey() const;
    std::string getPrivateKey() const;
    
    void generateKeyPair();
    std::string calculateAddress(const std::string& publicKey) const;
    std::string sign(const std::string& hash) const;
    static bool verifySignature(const std::string& hash, const std::string& signature, const std::string& publicKey);
    bool saveToFile(const std::string& filename) const;
    static Wallet loadFromFile(const std::string& filename);
};

#endif // WALLET_H


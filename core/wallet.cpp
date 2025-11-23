#include "wallet.h"
#include <fstream>
#include <openssl/ec.h>
#include <openssl/ecdsa.h>
#include <openssl/pem.h>
#include <openssl/sha.h>
#include <random>
#include <sstream>

Wallet::Wallet() {
    generateKeyPair();
}

Wallet::Wallet(const std::string& privateKey) {
    this->privateKey = privateKey;
}

Wallet::~Wallet() {
}

std::string Wallet::getAddress() const {
    return address;
}

std::string Wallet::getPublicKey() const {
    return publicKey;
}

std::string Wallet::getPrivateKey() const {
    return privateKey;
}

void Wallet::generateKeyPair() {
}

std::string Wallet::calculateAddress(const std::string& publicKey) const {
    return "";
}

std::string Wallet::sign(const std::string& hash) const {
    return "";
}

bool Wallet::verifySignature(const std::string& hash, const std::string& signature, const std::string& publicKey) {
    return false;
}

bool Wallet::saveToFile(const std::string& filename) const {
    return false;
}

Wallet Wallet::loadFromFile(const std::string& filename) {
    return Wallet();
}


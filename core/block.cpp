#include "block.h"
#include <sstream>
#include <iomanip>
#include <openssl/evp.h>
#include <openssl/opensslv.h>

Block::Block() {
    index = 0;
    previousHash = "";
    timestamp = "";
    transactions = {};
    nonce = 0;
    hash = "";
}

Block::Block(int index, const std::string& previousHash, const std::string& timestamp, const std::vector<Transaction>& transactions) {
    this->index = index;
    this->previousHash = previousHash;
    this->timestamp = timestamp;
    this->transactions = transactions;
    this->nonce = 0;
    this->hash = calculateHash();
}

Block::~Block() {
}

int Block::getIndex() const {
    return index;
}

std::string Block::getPreviousHash() const {
    return previousHash;
}

std::string Block::getTimestamp() const {
    return timestamp;
}

std::vector<Transaction> Block::getTransactions() const {
    return transactions;
}

std::string Block::getHash() const {
    return hash;
}

int Block::getNonce() const {
    return nonce;
}

void Block::setTransactions(const std::vector<Transaction>& transactions) {
    this->transactions = transactions;
}

void Block::setNonce(int nonce) {
    this->nonce = nonce;
    this->hash = calculateHash();
}

void Block::setHash(const std::string& hash) {
    this->hash = hash;
}

std::string Block::calculateHash() const {
    std::stringstream chaine_complete;
    
    chaine_complete << index << previousHash << timestamp << nonce;
    
    for (const auto& transaction : transactions) {
        chaine_complete << transaction.calculateHash();
    }
    
    std::string texte_a_hasher = chaine_complete.str();
    
    unsigned char hash_bytes[EVP_MAX_MD_SIZE];
    unsigned int hash_length = 0;

    EVP_MD_CTX* mdctx = EVP_MD_CTX_new();
    if (mdctx == nullptr) {
        return "";
    }
    
    if (EVP_DigestInit_ex(mdctx, EVP_sha256(), nullptr) != 1) {
        EVP_MD_CTX_free(mdctx);
        return "";
    }
    
    EVP_DigestUpdate(mdctx, texte_a_hasher.c_str(), texte_a_hasher.length());
    EVP_DigestFinal_ex(mdctx, hash_bytes, &hash_length);
    EVP_MD_CTX_free(mdctx);
    
    std::stringstream hexStream;
    hexStream << std::hex << std::setfill('0');
    for (unsigned int i = 0; i < hash_length; i++) {
        hexStream << std::setw(2) << static_cast<unsigned>(hash_bytes[i]);
    }
    
    return hexStream.str();
}

bool Block::isValidHash(int difficulty) const {
    if (hash.empty()) {
        return false;
    }
    
    if (hash.length() < static_cast<size_t>(difficulty)) {
        return false;
    }
    
    for (int i = 0; i < difficulty; i++) {
        if (hash[i] != '0') {
            return false;
        }
    }
    
    return true;
}


#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <string>
#include <cstdint>
#include "transaction.h"

class Block {
private:
    int index;
    std::string previousHash;
    std::string timestamp;
    std::vector<Transaction> transactions; 
    int nonce;
    std::string hash;

public:
    Block();
    Block(int index, const std::string& previousHash, const std::string& timestamp, const std::vector<Transaction>& transactions);
    ~Block();

    int getIndex() const;
    std::string getPreviousHash() const;
    std::string getTimestamp() const;
    std::vector<Transaction> getTransactions() const;
    std::string getHash() const;
    int getNonce() const;

    void setTransactions(const std::vector<Transaction>& transactions);
    void setNonce(int nonce);
    void setHash(const std::string& hash);   
  
    std::string calculateHash() const;  
    std::string serialize() const;
    bool isValidHash(int difficulty) const;
};

#endif // BLOCK_H


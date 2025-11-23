#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include <string>
#include "block.h"
#include "transaction.h"

class Blockchain {
private:
    std::vector<Block> blocks;
    std::vector<Transaction> pendingTransactions;
    int difficulty;
    std::string lastHash;

public:
    Blockchain();
    ~Blockchain();
    
    void createGenesisBlock();
    bool addBlock(const Block& block);
    Block getLastBlock() const;
    bool addTransaction(const Transaction& transaction);
    Block mineBlock();
    bool isValid() const;
    size_t getChainLength() const;
    std::vector<Transaction> getPendingTransactions() const;
};

#endif // BLOCKCHAIN_H


#include "blockchain.h"
#include "pow.h"
#include <algorithm>

Blockchain::Blockchain() {
    difficulty = 4;
    lastHash = "";
    createGenesisBlock();
}

Blockchain::~Blockchain() {
}

void Blockchain::createGenesisBlock() {
}

bool Blockchain::addBlock(const Block& block) {
    return false;
}

Block Blockchain::getLastBlock() const {
    if (blocks.empty()) {
        return Block();
    }
    return blocks.back();
}

bool Blockchain::addTransaction(const Transaction& transaction) {
    return false;
}

Block Blockchain::mineBlock() {
    return Block();
}

bool Blockchain::isValid() const {
    return false;
}

size_t Blockchain::getChainLength() const {
    return blocks.size();
}

std::vector<Transaction> Blockchain::getPendingTransactions() const {
    return pendingTransactions;
}


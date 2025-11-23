#include "pow.h"
#include "block.h"
#include <string>

bool Pow::mineBlock(Block& block, int difficulty) {
    block.setNonce(0);  
    while (true) {
        std::string hash = block.calculateHash();
        if (isValidHash(hash, difficulty)) {
            block.setHash(hash);
            return true;
        }
        block.setNonce(block.getNonce() + 1);
    }
    return false;
}

bool Pow::isValidHash(const std::string& hash, int difficulty) {
    if (hash.length() < difficulty) return false;
    return hash.substr(0, difficulty) == std::string(difficulty, '0');
}

int Pow::calculateDifficulty(size_t chainLength) {
    return 4;
}


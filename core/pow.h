#ifndef POW_H
#define POW_H

#include "block.h"
#include <string>
#include <cstdint>
#include <algorithm>

class Pow {
public:
    static bool mineBlock(Block& block, int difficulty);
    static bool isValidHash(const std::string& hash, int difficulty);
    static int calculateDifficulty(size_t chainLength);
};

#endif // POW_H


#include "block.h"
// TODO: Inclure les headers nécessaires
// - <sstream> pour la concaténation de strings
// - <iomanip> pour le formatage
// - Bibliothèque crypto pour SHA256 (OpenSSL, Crypto++, etc.)
//   Exemple: #include <openssl/sha.h>

// TODO: Implémenter le constructeur par défaut
Block::Block() {
    // TODO: Initialiser tous les membres à des valeurs par défaut
    // - index = 0
    // - previousHash = ""
    // - timestamp = temps actuel
    // - transactions = vecteur vide
    // - nonce = 0
    // - hash = ""
    // - difficulty = 0
}

// TODO: Implémenter le constructeur avec paramètres
Block::Block(uint32_t index, const std::string& previousHash, const std::vector<Transaction>& transactions) {
    // TODO: Assigner les paramètres aux membres
    // - this->index = index
    // - this->previousHash = previousHash
    // - this->transactions = transactions
    // - timestamp = temps actuel (utiliser time(nullptr) ou std::chrono)
    // - nonce = 0
    // - hash = "" (sera calculé plus tard)
    // - difficulty = 0 ou valeur par défaut
}

// TODO: Implémenter le destructeur si nécessaire
Block::~Block() {
    // TODO: Code ici (généralement vide)
}

// TODO: Implémenter tous les getters
// Exemple:
// uint32_t Block::getIndex() const {
//     return index;
// }

// TODO: Implémenter setNonce()
void Block::setNonce(uint32_t nonce) {
    // TODO: this->nonce = nonce
}

// TODO: Implémenter setHash()
void Block::setHash(const std::string& hash) {
    // TODO: this->hash = hash
}

// TODO: Implémenter calculateHash()
// Cette fonction est CRITIQUE pour la sécurité
std::string Block::calculateHash() const {
    // TODO: Créer une chaîne avec toutes les données du bloc
    // Format suggéré: index + previousHash + timestamp + transactions + nonce
    // 
    // Pour les transactions, vous pouvez:
    // 1. Sérialiser chaque transaction et les concaténer
    // 2. Calculer un hash Merkle des transactions
    // 
    // Exemple de concaténation:
    // std::stringstream ss;
    // ss << index << previousHash << timestamp << nonce;
    // for (const auto& tx : transactions) {
    //     ss << tx.serialize();
    // }
    
    // TODO: Appliquer SHA256 à cette chaîne
    // Avec OpenSSL:
    // - Créer un buffer SHA256_CTX
    // - SHA256_Init(&ctx)
    // - SHA256_Update(&ctx, data.c_str(), data.length())
    // - SHA256_Final(hash, &ctx)
    // - Convertir le hash en hexadécimal
    
    // TODO: Retourner le hash en hexadécimal
    return ""; // Placeholder
}

// TODO: Implémenter serialize()
// Format JSON ou format personnalisé
std::string Block::serialize() const {
    // TODO: Option 1 - JSON (nécessite une bibliothèque JSON)
    // {
    //   "index": 1,
    //   "previousHash": "...",
    //   "timestamp": 1234567890,
    //   "transactions": [...],
    //   "nonce": 12345,
    //   "hash": "..."
    // }
    
    // TODO: Option 2 - Format personnalisé simple
    // std::stringstream ss;
    // ss << "Block #" << index << "\n"
    //    << "Previous: " << previousHash << "\n"
    //    << "Hash: " << hash << "\n"
    //    << "Nonce: " << nonce << "\n"
    //    << "Transactions: " << transactions.size() << "\n";
    
    return ""; // Placeholder
}

// TODO: Implémenter isValidHash()
bool Block::isValidHash(int difficulty) const {
    // TODO: Vérifier que le hash commence par 'difficulty' zéros
    // Exemple avec difficulté 4:
    // if (hash.substr(0, 4) != "0000") return false;
    
    // TODO: Alternative: vérifier que le hash est inférieur à une valeur cible
    // Convertir le hash en nombre et comparer
    
    return false; // Placeholder
}


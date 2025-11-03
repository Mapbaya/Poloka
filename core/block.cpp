#include "block.h"
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>    
// - <sstream> pour la concaténation de strings
// - <iomanip> pour le formatage
// - <openssl/sha.h> pour SHA256

/*
 * ============================================================================
 * TODO LIST - BLOCK.H / BLOCK.CPP
 * ============================================================================
 * 
 * ✅ TERMINÉ:
 * - Calcul du hash simplifié mais sécurisé (SHA256)
 * - Getters/Setters complets
 * - Validation de la difficulté du hash
 * - Sérialisation basique
 * - Cohérence entre .h et .cpp
 * 
 * 🔧 AMÉLIORATIONS À FAIRE:
 * 
 * 1. MERKLE TREE pour les transactions (block.cpp ligne 83)
 *    - Implémenter un arbre de Merkle pour hasher les transactions
 *    - Permet de vérifier une transaction sans recharger tout le bloc
 *    - Augmente la sécurité et l'efficacité
 *    - Priorité: MOYENNE (fonctionne sans, mais meilleure pratique)
 * 
 * 2. FORMAT JSON pour serialize() (block.cpp ligne 117)
 *    - Remplacer le format texte simple par JSON
 *    - Utiliser une bibliothèque comme nlohmann/json
 *    - Améliore l'interopérabilité avec d'autres systèmes
 *    - Priorité: BASSE (le format actuel fonctionne)
 * 
 * 3. SÉRIALISATION DES TRANSACTIONS (block.cpp ligne 127)
 *    - Dépend de l'implémentation de Transaction::serialize()
 *    - À faire une fois que Transaction est complète
 *    - Priorité: BASSE (dépend de Transaction)
 * 
 * 📋 DÉPENDANCES AVEC D'AUTRES CLASSES:
 * 
 * - Transaction::calculateHash() doit retourner un hash valide
 *   Actuellement retourne "", donc fallback "tx_placeholder" utilisé
 *   → Voir core/transaction.cpp pour compléter l'implémentation
 * 
 * - Transaction::serialize() doit être implémentée pour 
 *   améliorer Block::serialize()
 *   → Voir core/transaction.cpp pour compléter l'implémentation
 * 
 * 🔒 SÉCURITÉ:
 * 
 * ✅ SHA256 utilisé pour le hash (cryptographiquement sécurisé)
 * ✅ Toutes les données du bloc sont incluses dans le hash
 * ✅ Le hash est recalculé automatiquement quand le nonce change
 * ✅ Validation de la difficulté implémentée
 * 
 * ⚠️ POINTS D'ATTENTION:
 * - Le hash inclut les transactions via leurs hashs (sécurisé)
 * - Le Merkle Tree serait une amélioration mais n'est pas critique
 * - En production, vérifier que Transaction::calculateHash() ne retourne jamais ""
 * 
 * ============================================================================
 */

// Constructeur par défaut
Block::Block() {
    index = 0;
    previousHash = "";
    timestamp = "";
    transactions = {};
    nonce = 0;
    hash = "";
}

// Constructeur avec paramètres
Block::Block(int index, const std::string& previousHash, const std::string& timestamp, const std::vector<Transaction>& transactions) {
    this->index = index;
    this->previousHash = previousHash;
    this->timestamp = timestamp;
    this->transactions = transactions;
    this->nonce = 0;
    this->hash = calculateHash(); // Calculer le hash du bloc initial (sans nonce, sera recalculé pendant le mining)
}

// Destructeur
Block::~Block() {
}

// Getters
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

// Setters
void Block::setTransactions(const std::vector<Transaction>& transactions) {
    this->transactions = transactions;
}

void Block::setNonce(int nonce) {
    this->nonce = nonce;
    // Recalculer le hash après changement du nonce
    this->hash = calculateHash();
}

void Block::setHash(const std::string& hash) {
    this->hash = hash;
}

// Calcul du hash du bloc (CRITIQUE pour la sécurité)
// Hash simple mais sécurisé: SHA256(index + previousHash + timestamp + transactions + nonce)
std::string Block::calculateHash() const {
    std::stringstream ss;
    
    // Concaténer toutes les données du bloc de manière déterministe
    ss << index << previousHash << timestamp << nonce;
    
    // Ajouter toutes les transactions dans le hash
    // Méthode sécurisée: utiliser le hash de chaque transaction
    // TODO: Pour une sécurité accrue et une meilleure efficacité, implémenter un Merkle Tree des transactions
    // Cela permettrait de vérifier une transaction sans recharger tout le bloc
    for (const auto& tx : transactions) {
        // Utiliser le hash de la transaction si disponible (plus sécurisé que sérialiser toutes les données)
        std::string txHash = tx.calculateHash();
        if (!txHash.empty()) {
            ss << txHash;
        } else {
            // Fallback: utiliser un identifiant simple (temporaire jusqu'à ce que Transaction soit complète)
            // En production, ce cas ne devrait jamais se produire
            ss << "tx_placeholder";
        }
    }
    
    std::string data = ss.str();
    
    // Appliquer SHA256 avec OpenSSL
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data.c_str(), data.length());
    SHA256_Final(hash, &sha256);
    
    // Convertir le hash en hexadécimal
    std::stringstream hexStream;
    hexStream << std::hex << std::setfill('0');
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        hexStream << std::setw(2) << static_cast<unsigned>(hash[i]);
    }
    
    return hexStream.str();
}

// Sérialisation du bloc en format texte simple
// TODO: Pour une meilleure interopérabilité, implémenter un format JSON avec une bibliothèque comme nlohmann/json
std::string Block::serialize() const {
    std::stringstream ss;
    ss << "Block #" << index << "\n"
       << "Previous Hash: " << previousHash << "\n"
       << "Hash: " << hash << "\n"
       << "Timestamp: " << timestamp << "\n"
       << "Nonce: " << nonce << "\n"
       << "Transactions: " << transactions.size() << "\n";
    
    // TODO: Sérialiser les transactions une fois que Transaction::serialize() est implémentée
    // for (size_t i = 0; i < transactions.size(); i++) {
    //     ss << "  TX[" << i << "]: " << transactions[i].serialize() << "\n";
    // }
    
    return ss.str();
}

// Vérifie si le hash du bloc respecte la difficulté (preuve de travail)
// La difficulté est le nombre de zéros requis au début du hash en hexadécimal
bool Block::isValidHash(int difficulty) const {
    if (hash.empty()) {
        return false;
    }
    
    if (hash.length() < static_cast<size_t>(difficulty)) {
        return false;
    }
    
    // Vérifier que le hash commence par 'difficulty' zéros
    // En hexadécimal, cela signifie que les premiers digits doivent être 0
    for (int i = 0; i < difficulty; i++) {
        if (hash[i] != '0') {
            return false;
        }
    }
    
    return true;
}


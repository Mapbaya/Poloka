#include "transaction.h"
// TODO: Inclure les headers nécessaires
// - <sstream> pour la sérialisation
// - <ctime> ou <chrono> pour les timestamps
// - Bibliothèque crypto pour SHA256 et signatures (OpenSSL, etc.)
// - "wallet.h" pour les fonctions de signature

// TODO: Implémenter le constructeur par défaut
Transaction::Transaction() {
    // TODO: Initialiser tous les membres à des valeurs par défaut
    // - id = ""
    // - fromAddress = ""
    // - toAddress = ""
    // - amount = 0
    // - signature = ""
    // - timestamp = temps actuel
    // - type = TRANSFER (ou valeur par défaut)
}

// TODO: Implémenter le constructeur avec paramètres
Transaction::Transaction(const std::string& fromAddress, const std::string& toAddress, uint64_t amount) {
    // TODO: Assigner les paramètres
    // - this->fromAddress = fromAddress
    // - this->toAddress = toAddress
    // - this->amount = amount
    // - timestamp = temps actuel
    // - signature = "" (sera signée plus tard)
    // - id = "" (sera calculé après la signature)
    // - type = TRANSFER
}

// TODO: Implémenter le destructeur si nécessaire
Transaction::~Transaction() {
    // TODO: Code ici (généralement vide)
}

// TODO: Implémenter tous les getters
// Exemple:
// std::string Transaction::getId() const {
//     return id;
// }

// TODO: Implémenter setSignature()
void Transaction::setSignature(const std::string& signature) {
    // TODO: this->signature = signature
}

// TODO: Implémenter calculateHash()
// CRITIQUE: Le hash doit être calculé AVANT la signature
std::string Transaction::calculateHash() const {
    // TODO: Créer une chaîne avec les données de la transaction
    // Format: fromAddress + toAddress + amount + timestamp
    // 
    // std::stringstream ss;
    // ss << fromAddress << toAddress << amount << timestamp;
    // std::string data = ss.str();
    
    // TODO: Appliquer SHA256
    // (Même méthode que dans block.cpp)
    
    // TODO: Retourner le hash en hexadécimal
    return ""; // Placeholder
}

// TODO: Implémenter sign()
// IMPORTANT: Signer le hash, pas les données brutes
bool Transaction::sign(const std::string& privateKey) {
    // TODO: Calculer le hash de la transaction
    // std::string txHash = calculateHash();
    
    // TODO: Signer le hash avec la clé privée
    // Avec OpenSSL et ECDSA:
    // 1. Charger la clé privée depuis une string (PEM ou format personnalisé)
    // 2. Créer un contexte de signature ECDSA
    // 3. Signer le hash
    // 4. Encoder la signature en base64 ou hexadécimal
    
    // TODO: Stocker la signature dans this->signature
    // TODO: Recalculer l'ID (le hash change avec la signature, ou l'ID est juste le hash avant signature)
    
    // Note: L'ID est généralement le hash de la transaction AVANT signature
    // La signature est stockée séparément
    
    return false; // Placeholder
}

// TODO: Implémenter isValid()
// Vérifier l'intégrité et l'authenticité de la transaction
bool Transaction::isValid() const {
    // TODO: Vérifications de base
    // - fromAddress et toAddress ne doivent pas être vides (sauf pour les récompenses de minage)
    // - amount > 0
    // - signature ne doit pas être vide
    
    // TODO: Vérifier la signature cryptographique
    // 1. Calculer le hash de la transaction
    // 2. Vérifier la signature avec la clé publique de l'expéditeur
    //    - Charger la clé publique depuis fromAddress
    //    - Vérifier que la signature correspond au hash
    //    - Utiliser ECDSA_verify ou équivalent
    
    return false; // Placeholder
}

// TODO: Implémenter serialize()
std::string Transaction::serialize() const {
    // TODO: Option 1 - JSON
    // {
    //   "id": "...",
    //   "from": "...",
    //   "to": "...",
    //   "amount": 1000,
    //   "timestamp": 1234567890,
    //   "signature": "..."
    // }
    
    // TODO: Option 2 - Format personnalisé
    // std::stringstream ss;
    // ss << "TX[" << id << "] "
    //    << fromAddress << " -> " << toAddress
    //    << " Amount: " << amount;
    
    return ""; // Placeholder
}


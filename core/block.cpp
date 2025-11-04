#include "block.h"
#include <sstream>
#include <iomanip>
#include <openssl/evp.h>
#include <openssl/opensslv.h>
// - <sstream> pour la concaténation de strings
// - <iomanip> pour le formatage
// - <openssl/evp.h> pour l'API EVP moderne (SHA256)


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
    std::stringstream chaine_complete;
    
    // Concaténer toutes les données du bloc de manière déterministe
    chaine_complete << index << previousHash << timestamp << nonce;
    
    // Ajouter toutes les transactions dans le hash
    //Pour chaque transaction dans la liste des transactions
    // auto permet de deviner le type de la variable transaction
    for (const auto& transaction : transactions) {
        chaine_complete << transaction.calculateHash();
    }
    
    std::string texte_a_hasher = chaine_complete.str();
    
    // Calcul du hash avec l'API EVP moderne (non dépréciée)
    //hash_bytes est un tableau de bytes (8 bits) où on va stocker le hash
    unsigned char hash_bytes[EVP_MAX_MD_SIZE];
    //hash_length est le nombre de bytes dans le hash (donc 32 octets pour SHA256)
    unsigned int hash_length = 0;

    //On créer un contexte de hash, comme une feuille où on garde les données à hasher
    EVP_MD_CTX* mdctx = EVP_MD_CTX_new();
    //mdctx == nullptr signifie que le contexte de hashage n'a pas été créé
    if (mdctx == nullptr) {
        return ""; // Erreur d'allocation
    }
    
    // Initialiser avec SHA256
    // On dit "je veux utiliser SHA256" et nullptr signifie que l'on ne veut pas utiliser de données supplémentaires
    if (EVP_DigestInit_ex(mdctx, EVP_sha256(), nullptr) != 1) {
        EVP_MD_CTX_free(mdctx);
        return ""; // Erreur d'initialisation, on renvoie une chaine vide
    }
    
    // Mettre à jour avec les données
    if (EVP_DigestUpdate(mdctx, texte_a_hasher.c_str(), texte_a_hasher.length()) != 1) {
        EVP_MD_CTX_free(mdctx);
        return ""; // Erreur de mise à jour
    }
    
    // Finaliser le hash
    if (EVP_DigestFinal_ex(mdctx, hash_bytes, &hash_length) != 1) {
        EVP_MD_CTX_free(mdctx);
        return ""; // Erreur de finalisation
    }
    
    EVP_MD_CTX_free(mdctx);
    
    // Conversion du hash en hexadécimal
    std::stringstream hexStream;
    hexStream << std::hex << std::setfill('0');
    for (unsigned int i = 0; i < hash_length; i++) {
        hexStream << std::setw(2) << static_cast<unsigned>(hash_bytes[i]);
    }
    
    return hexStream.str();





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


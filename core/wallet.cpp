#include "wallet.h"
// TODO: Inclure les headers nécessaires
// - <fstream> pour la sauvegarde/chargement de fichiers
// - <openssl/ec.h>, <openssl/ecdsa.h>, <openssl/pem.h> pour ECDSA
// - <openssl/sha.h> pour les hashs
// - <random> pour la génération aléatoire
// - <sstream> pour la conversion

// TODO: Implémenter le constructeur par défaut
Wallet::Wallet() {
    // TODO: Générer une nouvelle paire de clés
    generateKeyPair();
    
    // TODO: Calculer l'adresse depuis la clé publique
    // this->address = calculateAddress(this->publicKey);
}

// TODO: Implémenter le constructeur depuis une clé privée
Wallet::Wallet(const std::string& privateKey) {
    // TODO: Stocker la clé privée
    // this->privateKey = privateKey;
    
    // TODO: Dériver la clé publique depuis la clé privée
    // Avec OpenSSL:
    // 1. Charger la clé privée (EC_KEY_new_by_curve_name, PEM_read_ECPrivateKey)
    // 2. Extraire la clé publique (EC_KEY_get0_public_key)
    // 3. Encoder la clé publique en format string (PEM ou hex)
    
    // TODO: Calculer l'adresse
    // this->address = calculateAddress(this->publicKey);
}

// TODO: Implémenter le destructeur
Wallet::~Wallet() {
    // TODO: Optionnel: effacer la clé privée de la mémoire
    // Pour la sécurité, vous pouvez overwrite la mémoire avec des zéros
    // Attention: cela peut être optimisé par le compilateur
}

// TODO: Implémenter getAddress()
std::string Wallet::getAddress() const {
    // TODO: return address;
}

// TODO: Implémenter getPublicKey()
std::string Wallet::getPublicKey() const {
    // TODO: return publicKey;
}

// TODO: Implémenter getPrivateKey()
// ATTENTION: Cette fonction expose la clé privée
std::string Wallet::getPrivateKey() const {
    // TODO: return privateKey;
}

// TODO: Implémenter generateKeyPair()
// Cette fonction est CRITIQUE pour la sécurité
void Wallet::generateKeyPair() {
    // TODO: Option 1 - ECDSA avec OpenSSL (recommandé pour blockchain)
    // 1. Créer une courbe elliptique (secp256k1 est utilisé par Bitcoin)
    //    EC_KEY* key = EC_KEY_new_by_curve_name(NID_secp256k1);
    // 2. Générer la paire de clés
    //    EC_KEY_generate_key(key);
    // 3. Extraire la clé privée et l'encoder (PEM ou format personnalisé)
    // 4. Extraire la clé publique et l'encoder
    // 5. Nettoyer les ressources OpenSSL
    
    // TODO: Option 2 - RSA (plus simple mais moins efficace)
    // RSA_generate_key(2048, RSA_F4, nullptr, nullptr)
    
    // TODO: Stocker les clés dans les membres de la classe
}

// TODO: Implémenter calculateAddress()
std::string Wallet::calculateAddress(const std::string& publicKey) const {
    // TODO: Option 1 - Simple hash (SHA256)
    // - Appliquer SHA256 à la clé publique
    // - Encoder en hexadécimal
    
    // TODO: Option 2 - Double hash avec checksum (comme Bitcoin)
    // 1. SHA256(publicKey)
    // 2. RIPEMD160(resultat)
    // 3. Ajouter un préfixe (version byte)
    // 4. Calculer un checksum (SHA256(SHA256(version + hash)))
    // 5. Encoder en base58
    // C'est plus complexe mais plus robuste
    
    return ""; // Placeholder
}

// TODO: Implémenter sign()
std::string Wallet::sign(const std::string& hash) const {
    // TODO: Charger la clé privée depuis le format string
    // (PEM_read_ECPrivateKey ou format personnalisé)
    
    // TODO: Créer un contexte de signature ECDSA
    // ECDSA_SIG* sig = ECDSA_do_sign((unsigned char*)hash.c_str(), hash.length(), privateKey);
    
    // TODO: Encoder la signature en format string (DER, base64, ou hex)
    // std::string signature = encodeSignature(sig);
    
    // TODO: Nettoyer les ressources
    
    return ""; // Placeholder
}

// TODO: Implémenter verifySignature()
bool Wallet::verifySignature(const std::string& hash, const std::string& signature, const std::string& publicKey) {
    // TODO: Charger la clé publique depuis le format string
    
    // TODO: Décoder la signature depuis le format string
    
    // TODO: Vérifier la signature avec ECDSA
    // int result = ECDSA_do_verify((unsigned char*)hash.c_str(), hash.length(), decodedSig, publicKey);
    // return (result == 1);
    
    return false; // Placeholder
}

// TODO: Implémenter saveToFile()
bool Wallet::saveToFile(const std::string& filename) const {
    // TODO: Option 1 - Sauvegarde simple (NON SÉCURISÉ)
    // std::ofstream file(filename);
    // file << privateKey << "\n" << publicKey << "\n" << address;
    
    // TODO: Option 2 - Sauvegarde chiffrée (RECOMMANDÉ)
    // - Demander un mot de passe à l'utilisateur
    // - Chiffrer la clé privée avec AES-256
    // - Sauvegarder le fichier chiffré
    
    return false; // Placeholder
}

// TODO: Implémenter loadFromFile()
Wallet Wallet::loadFromFile(const std::string& filename) {
    // TODO: Lire le fichier
    
    // TODO: Si chiffré, demander le mot de passe et déchiffrer
    
    // TODO: Extraire la clé privée
    
    // TODO: Créer un Wallet avec cette clé privée
    // return Wallet(privateKey);
    
    return Wallet(); // Placeholder
}


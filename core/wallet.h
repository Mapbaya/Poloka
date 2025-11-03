#ifndef WALLET_H
#define WALLET_H

// TODO: Inclure les headers nécessaires
// - <string> pour les clés et adresses
// - <memory> pour les pointeurs si nécessaire

// TODO: Déclarer des structures ou classes pour les clés
// Option 1: Utiliser des strings pour stocker les clés (format PEM ou hex)
// Option 2: Créer des structures spécialisées

// TODO: Définir la classe Wallet
// Cette classe représente un portefeuille avec une paire de clés publique/privée

class Wallet {
private:
    // TODO: Déclarer la clé privée (std::string)
    // Stocker la clé privée en format PEM, hex, ou format personnalisé
    // ATTENTION: La clé privée doit être sécurisée et jamais exposée
    
    // TODO: Déclarer la clé publique (std::string)
    // Clé publique correspondante
    
    // TODO: Déclarer l'adresse du portefeuille (std::string)
    // Généralement un hash de la clé publique (ou la clé publique elle-même)
    // Cette adresse est utilisée pour recevoir des fonds

public:
    // TODO: Constructeur par défaut qui génère une nouvelle paire de clés
    // - Générer une paire de clés aléatoire
    // - Calculer l'adresse depuis la clé publique
    Wallet();
    
    // TODO: Constructeur depuis une clé privée existante
    // - Charger la clé privée
    // - Dériver la clé publique
    // - Calculer l'adresse
    Wallet(const std::string& privateKey);
    
    // TODO: Destructeur
    // - Effacer la clé privée de la mémoire si nécessaire (sécurité)
    ~Wallet();
    
    // TODO: Getter pour l'adresse (clé publique visible)
    std::string getAddress() const;
    
    // TODO: Getter pour la clé publique
    std::string getPublicKey() const;
    
    // TODO: Getter pour la clé privée (utiliser avec PRÉCAUTION)
    // Cette fonction doit être utilisée uniquement pour sauvegarder le portefeuille
    std::string getPrivateKey() const;
    
    // TODO: Fonction pour générer une nouvelle paire de clés
    // - Utiliser ECDSA ou RSA pour générer la paire
    // - Avec OpenSSL: EC_KEY_generate_key() ou RSA_generate_key()
    // - Stocker les clés dans les membres
    void generateKeyPair();
    
    // TODO: Fonction pour calculer l'adresse depuis la clé publique
    // - Prendre la clé publique
    // - Appliquer SHA256 (ou plusieurs hashs pour sécurité)
    // - Encoder en base58 ou hexadécimal
    // - Optionnel: ajouter un checksum
    std::string calculateAddress(const std::string& publicKey) const;
    
    // TODO: Fonction pour signer des données (hash)
    // - Prendre un hash (std::string) en paramètre
    // - Signer le hash avec la clé privée
    // - Retourner la signature en base64 ou hexadécimal
    std::string sign(const std::string& hash) const;
    
    // TODO: Fonction statique pour vérifier une signature
    // - Prendre: hash, signature, clé publique
    // - Vérifier que la signature correspond au hash avec cette clé publique
    // - Retourner true si valide
    static bool verifySignature(const std::string& hash, const std::string& signature, const std::string& publicKey);
    
    // TODO: Fonction pour sauvegarder le portefeuille dans un fichier
    // - Sauvegarder la clé privée de manière sécurisée (chiffrée de préférence)
    // - Format: JSON, PEM, ou format personnalisé
    bool saveToFile(const std::string& filename) const;
    
    // TODO: Fonction statique pour charger un portefeuille depuis un fichier
    // - Lire le fichier
    // - Décrypter si nécessaire
    // - Créer un Wallet avec la clé privée chargée
    static Wallet loadFromFile(const std::string& filename);
};

#endif // WALLET_H


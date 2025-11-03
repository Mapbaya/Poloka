#ifndef TRANSACTION_H
#define TRANSACTION_H

// TODO: Inclure les headers nécessaires
// - <string> pour les adresses et signatures
// - <cstdint> pour les montants (ou utiliser une classe Money)

// TODO: Définir la classe Transaction
// Cette classe représente une transaction entre deux portefeuilles

class Transaction {
private:
    // TODO: Déclarer l'identifiant de la transaction (std::string)
    // Hash unique de la transaction (ID unique)
    
    // TODO: Déclarer l'adresse de l'expéditeur (std::string)
    // Clé publique de l'expéditeur (adresse du portefeuille)
    
    // TODO: Déclarer l'adresse du destinataire (std::string)
    // Clé publique du destinataire
    
    // TODO: Déclarer le montant (uint64_t ou double)
    // Montant à transférer (en unités de base, ex: satoshis)
    // Attention: éviter les floats pour la précision financière
    
    // TODO: Déclarer la signature (std::string)
    // Signature cryptographique de la transaction par la clé privée de l'expéditeur
    
    // TODO: Déclarer le timestamp (uint64_t)
    // Moment de création de la transaction
    
    // TODO: Déclarer le type de transaction (enum ou int)
    // Ex: TRANSFER, REWARD (pour les récompenses de minage), etc.

public:
    // TODO: Constructeur par défaut
    Transaction();
    
    // TODO: Constructeur avec paramètres essentiels
    // - fromAddress: adresse de l'expéditeur
    // - toAddress: adresse du destinataire
    // - amount: montant à transférer
    Transaction(const std::string& fromAddress, const std::string& toAddress, uint64_t amount);
    
    // TODO: Destructeur si nécessaire
    ~Transaction();
    
    // TODO: Getters pour tous les attributs
    // Exemple: std::string getId() const;
    
    // TODO: Setters pour les attributs modifiables
    // - setSignature() pour définir la signature après la création
    
    // TODO: Fonction pour calculer le hash de la transaction
    // - Concaténer: fromAddress + toAddress + amount + timestamp
    // - Appliquer SHA256
    // - Stocker le résultat dans l'ID
    std::string calculateHash() const;
    
    // TODO: Fonction pour signer la transaction
    // - Prendre la clé privée en paramètre
    // - Calculer le hash de la transaction
    // - Signer le hash avec la clé privée (ECDSA ou RSA)
    // - Stocker la signature
    // - Retourner true si succès
    bool sign(const std::string& privateKey);
    
    // TODO: Fonction pour vérifier la signature
    // - Calculer le hash de la transaction
    // - Vérifier la signature avec la clé publique de l'expéditeur
    // - Retourner true si la signature est valide
    bool isValid() const;
    
    // TODO: Fonction pour sérialiser la transaction
    // - Convertir en JSON ou format string
    // - Utile pour le réseau et le stockage
    std::string serialize() const;
};

#endif // TRANSACTION_H


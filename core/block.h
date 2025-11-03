#ifndef BLOCK_H
#define BLOCK_H

// TODO: Inclure les headers nécessaires
// - <vector> pour les transactions
// - <string> pour les hashs et timestamps
// - <cstdint> pour les types entiers
// - "transaction.h" pour la définition d'une transaction

// TODO: Définir la classe Block
// Cette classe représente un bloc dans la blockchain

class Block {
private:
    // TODO: Déclarer l'index du bloc (uint32_t ou int)
    // Numéro séquentiel du bloc dans la chaîne
    
    // TODO: Déclarer le hash du bloc précédent (std::string)
    // Référence au bloc parent dans la chaîne
    
    // TODO: Déclarer le timestamp (uint64_t ou std::string)
    // Moment de création du bloc (Unix timestamp ou string ISO)
    
    // TODO: Déclarer la liste des transactions (std::vector<Transaction>)
    // Les transactions contenues dans ce bloc
    
    // TODO: Déclarer le nonce (uint32_t ou uint64_t)
    // Valeur utilisée pour la preuve de travail
    
    // TODO: Déclarer le hash du bloc actuel (std::string)
    // Hash calculé à partir de toutes les données du bloc
    
    // TODO: Déclarer la difficulté (int)
    // Nombre de zéros requis au début du hash (ou valeur de difficulté)

public:
    // TODO: Constructeur par défaut
    Block();
    
    // TODO: Constructeur avec paramètres
    // - index: numéro du bloc
    // - previousHash: hash du bloc précédent
    // - transactions: liste des transactions
    Block(uint32_t index, const std::string& previousHash, const std::vector<Transaction>& transactions);
    
    // TODO: Destructeur si nécessaire
    ~Block();
    
    // TODO: Getters pour tous les attributs privés
    // Exemple: uint32_t getIndex() const;
    
    // TODO: Setters pour les attributs qui doivent être modifiables
    // - setNonce() pour la preuve de travail
    // - setHash() pour stocker le hash calculé
    
    // TODO: Fonction pour calculer le hash du bloc
    // - Concaténer toutes les données du bloc en une chaîne
    // - Appliquer SHA256 (utiliser une bibliothèque crypto)
    // - Retourner le hash en hexadécimal
    std::string calculateHash() const;
    
    // TODO: Fonction pour sérialiser le bloc en JSON ou string
    // Utile pour le réseau et le stockage
    // - Convertir toutes les données en format JSON ou string formatée
    std::string serialize() const;
    
    // TODO: Fonction pour vérifier si le hash respecte la difficulté
    // - Vérifier que le hash commence par un certain nombre de zéros
    // - Ou vérifier que le hash est inférieur à une valeur cible
    bool isValidHash(int difficulty) const;
};

#endif // BLOCK_H


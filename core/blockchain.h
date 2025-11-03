#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

// TODO: Inclure les headers nécessaires
// - <vector> pour la liste de blocs
// - <string> pour les identifiants
// - "block.h" pour la définition d'un bloc

// TODO: Définir la classe Blockchain
// Cette classe représente la blockchain principale

class Blockchain {
private:
    // TODO: Déclarer un vecteur de blocs (std::vector<Block>)
    // Cette liste contient tous les blocs de la chaîne
    
    // TODO: Déclarer un pool de transactions en attente (std::vector<Transaction>)
    // Les transactions non confirmées sont stockées ici avant d'être minées
    
    // TODO: Déclarer une difficulté pour la preuve de travail (int ou uint32_t)
    // Cette valeur détermine la difficulté du minage
    
    // TODO: Déclarer le hash du dernier bloc (std::string)
    // Utile pour lier les nouveaux blocs à la chaîne

public:
    // TODO: Constructeur par défaut
    // - Initialiser une blockchain vide ou avec un bloc genesis
    // - Définir la difficulté initiale
    Blockchain();
    
    // TODO: Destructeur si nécessaire
    ~Blockchain();
    
    // TODO: Fonction pour créer le bloc genesis (premier bloc)
    // - Générer un bloc initial avec des transactions vides ou spéciales
    // - Calculer le hash du bloc genesis
    void createGenesisBlock();
    
    // TODO: Fonction pour ajouter un nouveau bloc
    // - Prendre le bloc en paramètre
    // - Vérifier la validité du bloc (hash, référence au bloc précédent)
    // - Ajouter le bloc à la chaîne
    // - Retourner true si succès, false si échec
    bool addBlock(const Block& block);
    
    // TODO: Fonction pour obtenir le dernier bloc
    // - Retourner une référence au dernier bloc de la chaîne
    Block getLastBlock() const;
    
    // TODO: Fonction pour ajouter une transaction au pool
    // - Prendre une transaction en paramètre
    // - Vérifier la validité de la transaction (signature, solde suffisant)
    // - Ajouter au pool de transactions en attente
    bool addTransaction(const Transaction& transaction);
    
    // TODO: Fonction pour miner un nouveau bloc
    // - Créer un nouveau bloc avec les transactions du pool
    // - Effectuer la preuve de travail (Pow::mineBlock)
    // - Ajouter le bloc à la chaîne
    // - Vider le pool de transactions
    Block mineBlock();
    
    // TODO: Fonction pour valider toute la chaîne
    // - Parcourir tous les blocs
    // - Vérifier les hashs et les références entre blocs
    // - Retourner true si la chaîne est valide
    bool isValid() const;
    
    // TODO: Fonction pour obtenir la longueur de la chaîne
    // - Retourner le nombre de blocs dans la chaîne
    size_t getChainLength() const;
    
    // TODO: Fonction pour obtenir le pool de transactions
    // - Retourner les transactions en attente
    std::vector<Transaction> getPendingTransactions() const;
};

#endif // BLOCKCHAIN_H


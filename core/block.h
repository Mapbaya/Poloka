#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <string>
#include <cstdint>
#include "transaction.h"
// - <vector> pour les transactions
// - <string> pour les hashs et timestamps
// - <cstdint> pour les types entiers

// Définition de la classe Block
// Cette classe représente un bloc dans la blockchain
class Block {
private:
    // Numéro séquentiel du bloc dans la chaîne
    int index;
    
    // Hash du bloc précédent dans la chaîne
    std::string previousHash;
    
    // Moment de création du bloc (Unix timestamp ou string ISO)
    std::string timestamp;   // - index: numéro du bloc
    // - previousHash: hash du bloc précédent
    // - transactions: liste des transactions

    // Les transactions contenues dans ce bloc (liste de transactions)
    std::vector<Transaction> transactions; 

    // Valeur utilisée pour la preuve de travail
    int nonce;
    
    // Hash du bloc (SHA256 de toutes les données du bloc)
    std::string hash;

public:
    // Constructeur par défaut
    Block();

    // Constructeur avec paramètres
    Block(int index, const std::string& previousHash, const std::string& timestamp, const std::vector<Transaction>& transactions);


    // Destructeur
    ~Block();



    //Getters
    int getIndex() const;
    std::string getPreviousHash() const;
    std::string getTimestamp() const;
    std::vector<Transaction> getTransactions() const;
    std::string getHash() const;
    int getNonce() const;

    //Setters
    void setTransactions(const std::vector<Transaction>& transactions);
    void setNonce(int nonce);
    void setHash(const std::string& hash);   
  
    // Fonction pour calculer le hash du bloc
    std::string calculateHash() const;  

    // Fonction pour sérialiser le bloc en JSON ou string   
    std::string serialize() const;

    // Fonction pour vérifier si le hash respecte la difficulté
    bool isValidHash(int difficulty) const;
};

#endif // BLOCK_H


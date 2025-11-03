#include "blockchain.h"
// TODO: Inclure les autres headers nécessaires
// - "pow.h" pour la preuve de travail
// - <algorithm> si besoin

// TODO: Implémenter le constructeur
// - Initialiser le vecteur de blocs
// - Initialiser le pool de transactions
// - Définir la difficulté (par exemple: 4)
// - Créer le bloc genesis
Blockchain::Blockchain() {
    // TODO: Code ici
}

// TODO: Implémenter le destructeur si nécessaire
Blockchain::~Blockchain() {
    // TODO: Code ici (généralement vide pour les conteneurs STL)
}

// TODO: Implémenter createGenesisBlock()
// - Créer un bloc avec index 0
// - Hash précédent = "0000000000000000000000000000000000000000000000000000000000000000"
// - Timestamp = temps actuel
// - Transactions = vide ou avec une transaction spéciale
// - Calculer le hash du bloc
// - Ajouter le bloc à la chaîne
void Blockchain::createGenesisBlock() {
    // TODO: Code ici
}

// TODO: Implémenter addBlock()
// - Vérifier que le hash du bloc précédent correspond
// - Vérifier que le hash du bloc actuel est valide (respecte la difficulté)
// - Vérifier l'index du bloc (doit être chainLength + 1)
// - Ajouter le bloc au vecteur
bool Blockchain::addBlock(const Block& block) {
    // TODO: Code ici
    return false; // Placeholder
}

// TODO: Implémenter getLastBlock()
Block Blockchain::getLastBlock() const {
    // TODO: Code ici
    // Retourner blocks.back() ou un bloc par défaut si vide
}

// TODO: Implémenter addTransaction()
// - Vérifier la signature de la transaction
// - Vérifier que l'expéditeur a suffisamment de fonds
// - Ajouter la transaction au pool
bool Blockchain::addTransaction(const Transaction& transaction) {
    // TODO: Code ici
    return false; // Placeholder
}

// TODO: Implémenter mineBlock()
// - Obtenir le dernier bloc pour récupérer son hash
// - Créer un nouveau bloc avec les transactions du pool
// - Appeler Pow::mineBlock() pour effectuer la preuve de travail
// - Ajouter le bloc à la chaîne
// - Vider le pool de transactions
Block Blockchain::mineBlock() {
    // TODO: Code ici
}

// TODO: Implémenter isValid()
// - Parcourir tous les blocs
// - Pour chaque bloc (sauf le premier):
//     * Vérifier que previousHash == hash du bloc précédent
//     * Vérifier que le hash du bloc respecte la difficulté
//     * Vérifier que le hash est correctement calculé
bool Blockchain::isValid() const {
    // TODO: Code ici
    return false; // Placeholder
}

// TODO: Implémenter getChainLength()
size_t Blockchain::getChainLength() const {
    // TODO: Code ici
    return 0; // Placeholder
}

// TODO: Implémenter getPendingTransactions()
std::vector<Transaction> Blockchain::getPendingTransactions() const {
    // TODO: Code ici
}


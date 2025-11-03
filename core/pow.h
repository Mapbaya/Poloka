#ifndef POW_H
#define POW_H

// TODO: Inclure les headers nécessaires
// - "block.h" pour la définition d'un bloc
// - <string> pour les hashs
// - <cstdint> pour les types entiers

// TODO: Définir la classe Pow (Proof of Work)
// Cette classe gère la preuve de travail pour le minage de blocs

class Pow {
public:
    // TODO: Fonction statique pour miner un bloc
    // - Prendre un bloc en référence (non const car on va modifier le nonce)
    // - Prendre la difficulté en paramètre
    // - Parcourir les nonces jusqu'à trouver un hash valide
    // - Modifier le nonce et le hash du bloc
    // - Retourner true si un hash valide a été trouvé
    static bool mineBlock(Block& block, int difficulty);
    
    // TODO: Fonction statique pour vérifier si un hash respecte la difficulté
    // - Prendre un hash et une difficulté
    // - Vérifier que le hash commence par 'difficulty' zéros
    // - Retourner true si valide
    static bool isValidHash(const std::string& hash, int difficulty);
    
    // TODO: Fonction statique pour calculer la difficulté dynamique
    // - Prendre la longueur de la chaîne actuelle
    // - Ajuster la difficulté selon un algorithme (ex: tous les N blocs)
    // - Retourner la nouvelle difficulté
    // Note: Bitcoin ajuste la difficulté tous les 2016 blocs pour maintenir ~10 min/bloc
    static int calculateDifficulty(size_t chainLength);
};

#endif // POW_H


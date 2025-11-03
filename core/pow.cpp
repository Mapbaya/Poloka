#include "pow.h"
#include "block.h"
// TODO: Inclure les headers nécessaires
// - <string> pour les manipulations
// - <algorithm> si nécessaire

// TODO: Implémenter mineBlock()
// C'est le CŒUR de la preuve de travail
bool Pow::mineBlock(Block& block, int difficulty) {
    // TODO: Initialiser le nonce à 0
    // block.setNonce(0);
    
    // TODO: Boucle de minage (peut être très longue!)
    // while (true) {
    //     // Calculer le hash du bloc avec le nonce actuel
    //     std::string hash = block.calculateHash();
    //     
    //     // Vérifier si le hash respecte la difficulté
    //     if (isValidHash(hash, difficulty)) {
    //         // Hash valide trouvé!
    //         block.setHash(hash);
    //         return true;
    //     }
    //     
    //     // Incrémenter le nonce et réessayer
    //     block.setNonce(block.getNonce() + 1);
    //     
    //     // Optionnel: Limite de sécurité pour éviter les boucles infinies
    //     // if (block.getNonce() > MAX_NONCE) break;
    // }
    
    // TODO: Note sur l'optimisation:
    // Pour améliorer les performances, vous pouvez:
    // 1. Utiliser plusieurs threads (parallélisation)
    // 2. Utiliser des optimisations CPU (SSE, AVX)
    // 3. Utiliser GPU computing (OpenCL, CUDA) pour le minage intensif
    
    return false; // Placeholder
}

// TODO: Implémenter isValidHash()
bool Pow::isValidHash(const std::string& hash, int difficulty) {
    // TODO: Vérifier que le hash commence par 'difficulty' zéros
    // 
    // Exemple avec difficulté 4:
    // if (hash.length() < difficulty) return false;
    // return hash.substr(0, difficulty) == std::string(difficulty, '0');
    
    // TODO: Alternative: Vérifier que le hash est inférieur à une valeur cible
    // Cette approche est plus flexible pour les ajustements de difficulté
    // - Convertir le hash en nombre (big integer)
    // - Comparer avec une valeur cible calculée depuis la difficulté
    
    return false; // Placeholder
}

// TODO: Implémenter calculateDifficulty()
int Pow::calculateDifficulty(size_t chainLength) {
    // TODO: Algorithme simple: difficulté fixe
    // return 4; // Difficulté constante
    
    // TODO: Algorithme dynamique (comme Bitcoin)
    // - Définir un intervalle de blocs (ex: 10 blocs)
    // - Si chainLength % intervalle == 0:
    //     * Mesurer le temps écoulé pour les derniers N blocs
    //     * Ajuster la difficulté pour maintenir un temps moyen cible
    //     * Augmenter si trop rapide, diminuer si trop lent
    // - Sinon: retourner la difficulté actuelle
    
    // TODO: Exemple de calcul:
    // int targetTime = 600; // 10 minutes en secondes
    // int actualTime = getLastNBlocksTime(10); // Temps réel pour les 10 derniers blocs
    // double ratio = (double)targetTime / actualTime;
    // int newDifficulty = currentDifficulty * ratio;
    // return newDifficulty;
    
    return 4; // Placeholder - difficulté fixe
}


#include "peer.h"
// TODO: Inclure les headers nécessaires
// - <sys/socket.h> pour les sockets UDP (si découverte par broadcast)
// - <netinet/in.h> pour les structures réseau
// - <thread> pour les threads
// - <chrono> pour les délais
// - Bibliothèque HTTP pour les requêtes aux pairs

// TODO: Implémenter le constructeur
Peer::Peer() {
    // TODO: Initialiser la liste des pairs (vide au départ)
    // TODO: Définir le port de découverte (ex: 8888)
    // TODO: Optionnel: Démarrer le thread de découverte
}

// TODO: Implémenter le destructeur
Peer::~Peer() {
    // TODO: Arrêter le thread de découverte si actif
    // TODO: Nettoyer les ressources
}

// TODO: Implémenter discoverPeers()
void Peer::discoverPeers() {
    // TODO: Option 1 - UDP Broadcast (réseau local)
    // 1. Créer un socket UDP
    // 2. Configurer pour le broadcast
    // 3. Envoyer un message de découverte sur le réseau local
    // 4. Attendre les réponses des autres nœuds
    // 5. Ajouter les pairs qui répondent
    
    // TODO: Option 2 - Serveur bootstrap (réseau décentralisé)
    // 1. Se connecter à un serveur de découverte connu
    // 2. Demander une liste de pairs actifs
    // 3. Ajouter ces pairs à la liste
    // 4. Échanger des pairs avec les pairs découverts
    
    // TODO: Option 3 - DNS Seed (comme Bitcoin)
    // 1. Résoudre des domaines DNS qui retournent des IPs de nœuds
    // 2. Ajouter ces nœuds comme pairs
}

// TODO: Implémenter addPeer()
bool Peer::addPeer(const std::string& address) {
    // TODO: Vérifier le format (ip:port)
    // TODO: Vérifier que le pair n'est pas déjà dans la liste
    // TODO: Optionnel: Vérifier que le pair est accessible
    // TODO: Ajouter à la liste
    
    return false; // Placeholder
}

// TODO: Implémenter removePeer()
bool Peer::removePeer(const std::string& address) {
    // TODO: Trouver le pair dans la liste
    // TODO: Le retirer de la liste
    // TODO: Retourner true si trouvé et retiré
    
    return false; // Placeholder
}

// TODO: Implémenter getAllPeers()
std::vector<std::string> Peer::getAllPeers() const {
    // TODO: return peers;
}

// TODO: Implémenter isPeerActive()
bool Peer::isPeerActive(const std::string& address) const {
    // TODO: Parser l'adresse (ip:port)
    // TODO: Faire une requête HTTP GET à /blockchain/length
    // TODO: Si la requête réussit (200 OK), le pair est actif
    // TODO: Retourner true/false
    
    // Exemple:
    // try {
    //     int length = httpGet(peerAddress + "/blockchain/length");
    //     return true;
    // } catch (...) {
    //     return false;
    // }
    
    return false; // Placeholder
}

// TODO: Implémenter cleanupInactivePeers()
void Peer::cleanupInactivePeers() {
    // TODO: Parcourir tous les pairs
    // for (auto it = peers.begin(); it != peers.end(); ) {
    //     if (!isPeerActive(*it)) {
    //         // Retirer le pair inactif
    //         it = peers.erase(it);
    //     } else {
    //         ++it;
    //     }
    // }
}

// TODO: Implémenter exchangePeers()
void Peer::exchangePeers(const std::string& peerAddress) {
    // TODO: Faire une requête HTTP GET à /peers
    // TODO: Parser la réponse JSON (liste de pairs)
    // TODO: Pour chaque pair reçu:
    //     - Vérifier qu'il n'est pas déjà dans notre liste
    //     - Ajouter le nouveau pair
    //     - Optionnel: Vérifier qu'il est actif avant d'ajouter
}


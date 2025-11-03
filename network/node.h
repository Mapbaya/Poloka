#ifndef NODE_H
#define NODE_H

// TODO: Inclure les headers nécessaires
// - "blockchain.h" pour la blockchain locale
// - <string> pour les adresses réseau
// - <vector> pour les pairs
// - <thread> pour le multithreading
// - Bibliothèque HTTP (ex: cpp-httplib, crow, ou intégrer FastAPI en C++)

// TODO: Choisir une bibliothèque HTTP pour l'API
// Options:
// - cpp-httplib (simple, header-only)
// - Crow (simple, moderne)
// - Drogon (plus complexe mais puissant)
// - Intégrer un serveur HTTP bas niveau avec sockets

// TODO: Définir la classe Node
// Cette classe représente un nœud dans le réseau blockchain

class Node {
private:
    // TODO: Déclarer la blockchain locale (Blockchain)
    // Chaque nœud maintient sa propre copie de la blockchain
    
    // TODO: Déclarer le port du nœud (int)
    // Port sur lequel le nœud écoute
    
    // TODO: Déclarer l'adresse IP/hostname (std::string)
    // Adresse de ce nœud
    
    // TODO: Déclarer la liste des pairs (std::vector<std::string>)
    // Liste des adresses des autres nœuds dans le réseau
    // Format: "ip:port"
    
    // TODO: Déclarer le serveur HTTP (pointeur vers serveur HTTP)
    // Dépend de la bibliothèque choisie
    
    // TODO: Déclarer un mutex pour la synchronisation (std::mutex)
    // Protéger l'accès concurrent à la blockchain

public:
    // TODO: Constructeur
    // - Initialiser la blockchain
    // - Définir le port
    // - Initialiser le serveur HTTP
    Node(int port);
    
    // TODO: Destructeur
    // - Arrêter le serveur
    // - Nettoyer les ressources
    ~Node();
    
    // TODO: Fonction pour démarrer le nœud
    // - Démarrer le serveur HTTP
    // - Démarrer les threads pour la synchronisation
    // - Mettre le nœud en écoute
    void start();
    
    // TODO: Fonction pour arrêter le nœud
    // - Arrêter le serveur HTTP
    // - Arrêter tous les threads
    void stop();
    
    // TODO: Fonction pour ajouter un pair au réseau
    // - Prendre une adresse (ip:port) en paramètre
    // - Vérifier que le pair est accessible
    // - Ajouter à la liste des pairs
    bool addPeer(const std::string& address);
    
    // TODO: Fonction pour synchroniser avec les pairs
    // - Demander aux pairs leur longueur de chaîne
    // - Si une chaîne plus longue existe, demander les blocs manquants
    // - Vérifier la validité de la chaîne reçue
    // - Remplacer la blockchain locale si la nouvelle est valide et plus longue
    void syncWithPeers();
    
    // TODO: Endpoints HTTP à implémenter:
    // Ces fonctions seront appelées par le serveur HTTP
    
    // GET /blockchain - Retourner toute la blockchain
    std::string getBlockchain();
    
    // GET /blockchain/length - Retourner la longueur de la chaîne
    int getBlockchainLength();
    
    // GET /block/:index - Retourner un bloc spécifique
    std::string getBlock(int index);
    
    // POST /transaction - Recevoir une nouvelle transaction
    // Prendre une transaction en JSON, l'ajouter au pool
    bool receiveTransaction(const std::string& transactionJson);
    
    // POST /block - Recevoir un nouveau bloc miné
    // Prendre un bloc en JSON, l'ajouter à la chaîne si valide
    bool receiveBlock(const std::string& blockJson);
    
    // GET /peers - Retourner la liste des pairs
    std::vector<std::string> getPeers();
    
    // POST /peers - Ajouter un nouveau pair
    bool addPeerEndpoint(const std::string& address);
    
    // GET /mine - Miner un nouveau bloc (pour test)
    std::string mineBlock();
};

#endif // NODE_H


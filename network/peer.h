#ifndef PEER_H
#define PEER_H

// TODO: Inclure les headers nécessaires
// - <string> pour les adresses
// - <vector> pour les listes
// - <thread> pour la découverte en arrière-plan

// TODO: Définir la classe Peer
// Cette classe gère la découverte et la gestion des pairs dans le réseau

class Peer {
private:
    // TODO: Déclarer la liste des pairs connus (std::vector<std::string>)
    // Format: "ip:port"
    
    // TODO: Déclarer le port de découverte (int)
    // Port pour la découverte de pairs (si utilise UDP broadcast)
    
    // TODO: Déclarer un thread de découverte (std::thread)
    // Thread pour la découverte automatique de pairs

public:
    // TODO: Constructeur
    Peer();
    
    // TODO: Destructeur
    ~Peer();
    
    // TODO: Fonction pour découvrir des pairs automatiquement
    // - Utiliser UDP broadcast pour découvrir des pairs sur le réseau local
    // - Ou se connecter à un serveur de découverte (bootstrap node)
    // - Ajouter les pairs découverts à la liste
    void discoverPeers();
    
    // TODO: Fonction pour ajouter un pair manuellement
    // - Prendre une adresse (ip:port) en paramètre
    // - Ajouter à la liste si pas déjà présent
    bool addPeer(const std::string& address);
    
    // TODO: Fonction pour retirer un pair
    // - Retirer un pair qui n'est plus accessible
    bool removePeer(const std::string& address);
    
    // TODO: Fonction pour obtenir tous les pairs
    // - Retourner la liste complète des pairs
    std::vector<std::string> getAllPeers() const;
    
    // TODO: Fonction pour vérifier si un pair est toujours actif
    // - Faire une requête HTTP au pair
    // - Vérifier qu'il répond
    // - Retourner true si actif
    bool isPeerActive(const std::string& address) const;
    
    // TODO: Fonction pour nettoyer les pairs inactifs
    // - Parcourir tous les pairs
    // - Vérifier leur statut
    // - Retirer les pairs inactifs
    void cleanupInactivePeers();
    
    // TODO: Fonction pour échanger des pairs avec un pair
    // - Demander à un pair sa liste de pairs
    // - Ajouter les nouveaux pairs à notre liste
    void exchangePeers(const std::string& peerAddress);
};

#endif // PEER_H


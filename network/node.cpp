#include "node.h"
#include "blockchain.h"
// TODO: Inclure les headers nécessaires selon la bibliothèque HTTP choisie
// Exemple avec cpp-httplib:
// #include <httplib.h>
// 
// Exemple avec Crow:
// #include <crow.h>

// TODO: Inclure pour le parsing JSON
// - Bibliothèque JSON (nlohmann/json, rapidjson, etc.)

// TODO: Implémenter le constructeur
Node::Node(int port) {
    // TODO: Initialiser la blockchain
    // blockchain = Blockchain();
    
    // TODO: Initialiser le port
    // this->port = port;
    
    // TODO: Initialiser le serveur HTTP
    // server = new httplib::Server(); // ou équivalent
}

// TODO: Implémenter le destructeur
Node::~Node() {
    // TODO: Arrêter le serveur si nécessaire
    // TODO: Nettoyer les ressources
}

// TODO: Implémenter start()
void Node::start() {
    // TODO: Définir les routes HTTP
    // 
    // Exemple avec cpp-httplib:
    // server->Get("/blockchain", [this](const httplib::Request& req, httplib::Response& res) {
    //     res.set_content(this->getBlockchain(), "application/json");
    // });
    // 
    // server->Get("/blockchain/length", [this](const httplib::Request& req, httplib::Response& res) {
    //     res.set_content(std::to_string(this->getBlockchainLength()), "text/plain");
    // });
    // 
    // server->Get("/block/:index", [this](const httplib::Request& req, httplib::Response& res) {
    //     int index = std::stoi(req.matches[1]);
    //     res.set_content(this->getBlock(index), "application/json");
    // });
    // 
    // server->Post("/transaction", [this](const httplib::Request& req, httplib::Response& res) {
    //     bool success = this->receiveTransaction(req.body);
    //     res.status = success ? 200 : 400;
    // });
    // 
    // server->Post("/block", [this](const httplib::Request& req, httplib::Response& res) {
    //     bool success = this->receiveBlock(req.body);
    //     res.status = success ? 200 : 400;
    // });
    // 
    // server->Get("/peers", [this](const httplib::Request& req, httplib::Response& res) {
    //     // Retourner la liste des pairs en JSON
    // });
    // 
    // server->Post("/peers", [this](const httplib::Request& req, httplib::Response& res) {
    //     bool success = this->addPeerEndpoint(req.body);
    //     res.status = success ? 200 : 400;
    // });
    // 
    // server->Get("/mine", [this](const httplib::Request& req, httplib::Response& res) {
    //     res.set_content(this->mineBlock(), "application/json");
    // });
    
    // TODO: Démarrer le serveur sur le port
    // server->listen("0.0.0.0", port);
    
    // TODO: Optionnel: Démarrer un thread pour la synchronisation périodique
    // std::thread syncThread([this]() {
    //     while (running) {
    //         std::this_thread::sleep_for(std::chrono::seconds(30));
    //         this->syncWithPeers();
    //     }
    // });
}

// TODO: Implémenter stop()
void Node::stop() {
    // TODO: Arrêter le serveur HTTP
    // server->stop();
}

// TODO: Implémenter addPeer()
bool Node::addPeer(const std::string& address) {
    // TODO: Vérifier le format de l'adresse (ip:port)
    // TODO: Optionnel: Tester la connectivité
    
    // TODO: Ajouter à la liste des pairs si pas déjà présent
    // peers.push_back(address);
    
    return false; // Placeholder
}

// TODO: Implémenter syncWithPeers()
void Node::syncWithPeers() {
    // TODO: Verrouiller la blockchain avec le mutex
    // std::lock_guard<std::mutex> lock(blockchainMutex);
    
    // TODO: Parcourir tous les pairs
    // for (const auto& peer : peers) {
    //     // Faire une requête HTTP GET /blockchain/length
    //     // int peerLength = getPeerChainLength(peer);
    //     
    //     // Si la chaîne du pair est plus longue
    //     // if (peerLength > blockchain.getChainLength()) {
    //     //     // Demander tous les blocs
    //     //     std::string peerChainJson = getPeerBlockchain(peer);
    //     //     
    //     //     // Parser la blockchain reçue
    //     //     Blockchain peerChain = parseBlockchain(peerChainJson);
    //     //     
    //     //     // Vérifier la validité
    //     //     if (peerChain.isValid() && peerChain.getChainLength() > blockchain.getChainLength()) {
    //     //         // Remplacer la blockchain locale
    //     //         blockchain = peerChain;
    //     //     }
    //     // }
    // }
}

// TODO: Implémenter getBlockchain()
std::string Node::getBlockchain() {
    // TODO: Verrouiller avec le mutex
    // std::lock_guard<std::mutex> lock(blockchainMutex);
    
    // TODO: Sérialiser la blockchain en JSON
    // return blockchain.serialize();
    
    return ""; // Placeholder
}

// TODO: Implémenter getBlockchainLength()
int Node::getBlockchainLength() {
    // TODO: Verrouiller avec le mutex
    // return blockchain.getChainLength();
    
    return 0; // Placeholder
}

// TODO: Implémenter getBlock()
std::string Node::getBlock(int index) {
    // TODO: Récupérer le bloc à l'index donné
    // TODO: Sérialiser le bloc en JSON
    // TODO: Retourner une erreur si l'index est invalide
    
    return ""; // Placeholder
}

// TODO: Implémenter receiveTransaction()
bool Node::receiveTransaction(const std::string& transactionJson) {
    // TODO: Parser le JSON de la transaction
    // Transaction tx = parseTransaction(transactionJson);
    
    // TODO: Vérifier la validité de la transaction
    // if (!tx.isValid()) return false;
    
    // TODO: Ajouter la transaction à la blockchain
    // std::lock_guard<std::mutex> lock(blockchainMutex);
    // bool success = blockchain.addTransaction(tx);
    
    // TODO: Si succès, propager la transaction aux autres pairs
    // if (success) {
    //     broadcastTransaction(tx);
    // }
    
    return false; // Placeholder
}

// TODO: Implémenter receiveBlock()
bool Node::receiveBlock(const std::string& blockJson) {
    // TODO: Parser le JSON du bloc
    // Block block = parseBlock(blockJson);
    
    // TODO: Vérifier la validité du bloc
    // if (!block.isValidHash(difficulty)) return false;
    
    // TODO: Ajouter le bloc à la blockchain
    // std::lock_guard<std::mutex> lock(blockchainMutex);
    // bool success = blockchain.addBlock(block);
    
    // TODO: Si succès, propager le bloc aux autres pairs
    // if (success) {
    //     broadcastBlock(block);
    // }
    
    return false; // Placeholder
}

// TODO: Implémenter getPeers()
std::vector<std::string> Node::getPeers() {
    // TODO: return peers;
}

// TODO: Implémenter addPeerEndpoint()
bool Node::addPeerEndpoint(const std::string& address) {
    // TODO: return addPeer(address);
}

// TODO: Implémenter mineBlock()
std::string Node::mineBlock() {
    // TODO: Verrouiller avec le mutex
    // std::lock_guard<std::mutex> lock(blockchainMutex);
    
    // TODO: Miner un nouveau bloc
    // Block newBlock = blockchain.mineBlock();
    
    // TODO: Sérialiser le bloc en JSON
    // TODO: Propager le bloc aux pairs
    
    return ""; // Placeholder
}


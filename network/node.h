#ifndef NODE_H
#define NODE_H

#include "blockchain.h"
#include <string>
#include <vector>
#include <thread>
#include <mutex>

class Node {
private:
    Blockchain blockchain;
    int port;
    std::string address;
    std::vector<std::string> peers;
    std::mutex blockchainMutex;

public:
    Node(int port);
    ~Node();
    
    void start();
    void stop();
    bool addPeer(const std::string& address);
    void syncWithPeers();
    
    std::string getBlockchain();
    int getBlockchainLength();
    std::string getBlock(int index);
    bool receiveTransaction(const std::string& transactionJson);
    bool receiveBlock(const std::string& blockJson);
    std::vector<std::string> getPeers();
    bool addPeerEndpoint(const std::string& address);
    std::string mineBlock();
};

#endif // NODE_H


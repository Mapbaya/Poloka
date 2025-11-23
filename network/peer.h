#ifndef PEER_H
#define PEER_H

#include <string>
#include <vector>
#include <thread>

class Peer {
private:
    std::vector<std::string> peers;
    int discoveryPort;
    std::thread discoveryThread;

public:
    Peer();
    ~Peer();
    
    void discoverPeers();
    bool addPeer(const std::string& address);
    bool removePeer(const std::string& address);
    std::vector<std::string> getAllPeers() const;
    bool isPeerActive(const std::string& address) const;
    void cleanupInactivePeers();
    void exchangePeers(const std::string& peerAddress);
};

#endif // PEER_H


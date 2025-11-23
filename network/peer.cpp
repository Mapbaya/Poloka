#include "peer.h"
#include <string>
#include <vector>
#include <thread>
#include <chrono>

Peer::Peer() {
    discoveryPort = 8888;
}

Peer::~Peer() {
}

void Peer::discoverPeers() {
}

bool Peer::addPeer(const std::string& address) {
    return false;
}

bool Peer::removePeer(const std::string& address) {
    return false;
}

std::vector<std::string> Peer::getAllPeers() const {
    return peers;
}

bool Peer::isPeerActive(const std::string& address) const {
    return false;
}

void Peer::cleanupInactivePeers() {
}

void Peer::exchangePeers(const std::string& peerAddress) {
}


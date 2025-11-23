#include "node.h"
#include "blockchain.h"
#include <string>
#include <vector>
#include <thread>
#include <mutex>

Node::Node(int port) {
    this->port = port;
    blockchain = Blockchain();
}

Node::~Node() {
}

void Node::start() {
}

void Node::stop() {
}

bool Node::addPeer(const std::string& address) {
    return false;
}

void Node::syncWithPeers() {
}

std::string Node::getBlockchain() {
    return "";
}

int Node::getBlockchainLength() {
    return 0;
}

std::string Node::getBlock(int index) {
    return "";
}

bool Node::receiveTransaction(const std::string& transactionJson) {
    return false;
}

bool Node::receiveBlock(const std::string& blockJson) {
    return false;
}

std::vector<std::string> Node::getPeers() {
    return peers;
}

bool Node::addPeerEndpoint(const std::string& address) {
    return addPeer(address);
}

std::string Node::mineBlock() {
    return "";
}


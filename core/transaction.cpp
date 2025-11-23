#include "transaction.h"
#include <sstream>
#include <iomanip>
#include <chrono>
#include <openssl/evp.h>
#include <openssl/opensslv.h>

Transaction::Transaction() {
    idUniqueHash = "";
    ExpediteurAddress = "";
    DestinataireAddress= "";
    Montant = 0;
    Signature = "";
    Timestamp = std::to_string(std::chrono::system_clock::now().time_since_epoch().count());
    typeTransaction = 0;
}

Transaction::Transaction(const std::string& idUniqueHash, const std::string& ExpediteurAddress, const std::string& DestinataireAddress, double Montant, const std::string& Signature, const std::string& Timestamp, int typeTransaction) {
    this->idUniqueHash = idUniqueHash;
    this->ExpediteurAddress = ExpediteurAddress;
    this->DestinataireAddress = DestinataireAddress;
    this->Montant = Montant;
    this->Timestamp = std::to_string(std::chrono::system_clock::now().time_since_epoch().count());
    this->Signature = Signature;
    this->typeTransaction = typeTransaction;
}

Transaction::~Transaction() {
}

void Transaction::setSignature(const std::string& signature) {
    this->Signature = signature;
}

std::string Transaction::calculateHash() const {
    std::stringstream chaine_complete;
    chaine_complete << ExpediteurAddress << DestinataireAddress << Montant << Timestamp;

    std::string data = chaine_complete.str();
    
    unsigned char hash_bytes[EVP_MAX_MD_SIZE];
    unsigned int hash_length = 0;
    
    EVP_MD_CTX* mdctx = EVP_MD_CTX_new();
    if (mdctx == nullptr) {
        return "";
    }

    if (EVP_DigestInit_ex(mdctx, EVP_sha256(), nullptr) != 1) {
        EVP_MD_CTX_free(mdctx);
        return "";
    }
    
    if (EVP_DigestUpdate(mdctx, data.c_str(), data.length()) != 1) {
        EVP_MD_CTX_free(mdctx);
        return "";
    }
    
    if (EVP_DigestFinal_ex(mdctx, hash_bytes, &hash_length) != 1) {
        EVP_MD_CTX_free(mdctx);
        return "";
    }
    
    EVP_MD_CTX_free(mdctx);
    
    std::stringstream hexStream;
    hexStream << std::hex << std::setfill('0');
    for (unsigned int i = 0; i < hash_length; i++) {
        hexStream << std::setw(2) << static_cast<unsigned>(hash_bytes[i]);
    }
    
    return hexStream.str();
}

bool Transaction::sign(const std::string& privateKey) {
    return false;
}

bool Transaction::isValid() const {
    return false;
}

std::string Transaction::serialize() const {
    return "";
}


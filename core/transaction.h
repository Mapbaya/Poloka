#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>
#include <cstdint>

class Transaction {
private:
    std::string idUniqueHash;
    std::string ExpediteurAddress;
    std::string DestinataireAddress;
    double Montant;
    std::string Signature;
    std::string Timestamp;
    int typeTransaction;

public:
    Transaction();
    Transaction(const std::string& idUniqueHash, const std::string& ExpediteurAddress, const std::string& DestinataireAddress, double Montant, const std::string& Signature, const std::string& Timestamp, int typeTransaction);
    ~Transaction();

    void setSignature(const std::string& Signature);
    std::string calculateHash() const;
    bool sign(const std::string& privateKey);
    bool isValid() const;
    std::string serialize() const;
};

#endif // TRANSACTION_H


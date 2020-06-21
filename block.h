//
// Created by omer on 14.06.2020.
//
#include <string>
#include <vector>
#include "transaction.h"

using namespace std;

#ifndef BLOCKCHAIN_BLOCK_H
#define BLOCKCHAIN_BLOCK_H


class Block {
public:
    Block(const string &prevHash, const vector<Transaction> &transactions);

    const vector<Transaction> &getTransactions() const;

    const string &getPrevHash() const;

    const string &getHash() const;

private:
    string prevHash;
    vector<Transaction> transactions;
    string hash;
};


#endif //BLOCKCHAIN_BLOCK_H

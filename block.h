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
    Block( string &prevHash,  vector<Transaction> &transactions);

     vector<Transaction> &getTransactions();

     string &getPrevHash() ;

     string &getHash() ;

private:
    string prevHash;
    vector<Transaction> transactions;
    string hash;
};


#endif //BLOCKCHAIN_BLOCK_H

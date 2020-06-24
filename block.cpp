//
// Created by omer on 14.06.2020.
//

#include "block.h"

vector<Transaction> &Block::getTransactions() {
    return transactions;
}

string &Block::getPrevHash() {
    return prevHash;
}

string &Block::getHash() {
    return hash;
}

Block::Block(string prevHash, vector<Transaction> transactions, string hash) : prevHash(prevHash),
                                                                                transactions(transactions), hash(hash) {}

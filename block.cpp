//
// Created by omer on 14.06.2020.
//

#include "block.h"

const vector<Transaction> &Block::getTransactions() const {
    return transactions;
}

const string &Block::getPrevHash() const {
    return prevHash;
}

const string &Block::getHash() const {
    return hash;
}

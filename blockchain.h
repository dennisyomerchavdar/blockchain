//
// Created by omer on 15.06.2020.
//

#ifndef BLOCKCHAIN_BLOCKCHAIN_H
#define BLOCKCHAIN_BLOCKCHAIN_H


#include "block.h"
#include "miner.h"

class Blockchain {
    vector<User> users;
    vector<Miner> miners;
};


#endif //BLOCKCHAIN_BLOCKCHAIN_H

//
// Created by omer on 21.06.2020.
//

#include "miner.h"


long Miner::getId() {
    return id;
}


string &Miner::getName() {
    return name;
}



Miner::Miner(long id, const string &name) : id(id), name(name) {}

//
// Created by omer on 21.06.2020.
//

#ifndef BLOCKCHAIN_MINER_H
#define BLOCKCHAIN_MINER_H

#include <string>
using namespace std;
class Miner {
public:
    Miner(long id, const string &name);
    long getId();
    string &getName();
private:
    long id;
    string name;
};


#endif //BLOCKCHAIN_MINER_H

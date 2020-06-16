//
// Created by omer on 15.06.2020.
//

#ifndef BLOCKCHAIN_HASH_H
#define BLOCKCHAIN_HASH_H

#include <string>


using namespace std;

class Hash {
public:
    Hash(void);
    Hash(string s);
    string getHash();

private:
    string hash;
};


#endif //BLOCKCHAIN_HASH_H

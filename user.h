//
// Created by omer on 16.06.2020.
//

#ifndef BLOCKCHAIN_USER_H
#define BLOCKCHAIN_USER_H
#include <string>
#include <math.h>
#include <vector>
using namespace std;
class User {
public:
    User(long id, const string& name, long prime1, long prime2);
    long getId();
    string getName();
    long getPublicKey();
    long getPublicExp();
    bool verify(vector<long> plainText, vector<long> cipherText);

private:
    long id;
    string name;
    long publicKey;
    long publicExp;
    long privateExp;
};


#endif //BLOCKCHAIN_USER_H

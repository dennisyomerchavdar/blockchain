//
// Created by omer on 16.06.2020.
//

#ifndef BLOCKCHAIN_USER_H
#define BLOCKCHAIN_USER_H
#include <string>
#include <math.h>
using namespace std;
class User {
public:
    User(long id, string name, long prime1, long prime2);

    long getId();

    string getName();

    long getPublicKey();

    long getPublicExp();

    long getPrivateExp(); // for debug. REMOVE LATER!

    bool verify(string plainText, string cipherText);

private:
    long id;
    string name;
    long publicKey;
    long publicExp;
    long privateExp;
};


#endif //BLOCKCHAIN_USER_H

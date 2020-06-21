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
<<<<<<< HEAD
    long publicKey;
    long publicExp;
    long privateExp;
=======
>>>>>>> 5aa2d2710407047c96e17c2490b5a956b9ba2a6f
};


#endif //BLOCKCHAIN_USER_H

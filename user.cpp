//
// Created by omer on 16.06.2020.
//

#include "user.h"

long User::getId() {
    return id;
}


string &User::getName() {
    return name;
}

long User::getPublicKey(){
    return publicKey;
}

long User::getPublicExp(){
    return publicExp;
}

long User::getPrivateExp(){
    return privateExp;
}

bool User::verify(string plainText, string cipherText){
    for(int i=0;i<plainText.length();i++){
        long p = (long)plainText[i];
        long c = (long)cipherText[i];
        if(p != ((long)pow(c,privateExp) % publicKey)){
            return false;
        }
    }
    return true;
}

User::User(long id, string name, long prime1, long prime2) : id(id), name(name) {
    this->publicKey = prime1 * prime2;
    
    long lcm = prime1 - 1;
    while((lcm % (prime1 - 1) != 0) || (lcm % (prime2 - 1) != 0)){
        lcm++;
    }

    long publicExp = 3;
    while(lcm % publicExp == 0){
        publicExp += 2;
    }
    this->publicExp = publicExp;

    long privateExp = 1;
    while((privateExp * publicExp) % lcm != 1){
        privateExp++;
    }
    this->privateExp = privateExp;
}

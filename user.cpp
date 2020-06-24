//
// Created by omer on 16.06.2020.
//

#include "user.h"
#include <vector>
#include <iostream>
using namespace std;

long User::getId(){
    return id;
}


string User::getName(){
    return name;
}

long User::getPublicKey(){
    return publicKey;
}

long User::getPublicExp(){
    return publicExp;
}


bool User::verify(vector<long> plainText, vector<long> cipherText){
    for(int i=0;i<plainText.size();i++){
        long p = plainText[i];
        long c = cipherText[i];
        long exp = 1;
        for(int j=0;j<privateExp;j++){
            exp = exp * c;
            exp = exp % publicKey;
        }
        if(p != exp){
            return false;
        }
        /*
        if(p != ((long)pow(c,privateExp) % publicKey)){
            return false;
        }*/
    }
    return true;
}

User::User(long id, const string& name, long prime1, long prime2 ) : id(id), name(name){
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

//
// Created by omer on 15.06.2020.
//

#include "hash.h"
#include <openssl/sha.h>
#include <iostream>

Hash::Hash() {}


Hash::Hash(string s) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, s.c_str(), s.size());
    SHA256_Final(hash, &sha256);

    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        std::cout << (int)hash[i];
    }

    this->hash = "asd";
}

string Hash::getHash() {
    return this->hash;
}
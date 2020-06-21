#include <iostream>
#include "blockchain.h"
#include "block.h"
//#include "hash.h"
#include "transaction.h"
#include <string>
#include <vector>
int main() {
    //std::vector<Transaction> t = { Transaction( User(0,"omar"), User(1,"sam") , 300)};
    //Block firstBlock( "123123" ,t);
    //std::cout << firstBlock.getTransactions()[0].getAmount() << std::endl;
    User aa(31, "asd", 61, 53);
    std::cout << "pubKey: " << aa.getPublicKey() << " pubExp: " << aa.getPublicExp() << " priExp: " << aa.getPrivateExp() << std::endl;
    return 0;
}
#include <iostream>
#include "blockchain.h"
#include "block.h"
#include "hash.h"
#include "transaction.h"
#include <string>
#include <vector>
int main() {
    std::vector<Transaction> t = { Transaction( User(0,"omar"), User(1,"sam") , 300)};
    Block firstBlock( "123123" ,t);
    std::cout << firstBlock.getTransactions()[0].getAmount() << std::endl;
    return 0;
}
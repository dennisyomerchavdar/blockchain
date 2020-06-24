//
// Created by omer on 15.06.2020.
//

#ifndef BLOCKCHAIN_BLOCKCHAIN_H
#define BLOCKCHAIN_BLOCKCHAIN_H


#include "block.h"
#include "miner.h"
#include "user.h"
#include "semaphore.h"
#include <mutex>
class Blockchain {
public:
    Semaphore semaphore;
    std::mutex mut;
    Blockchain();

    void addToTransactionPool(User paymentFrom, User paymentTo, long amount);



    void addBlock( vector<Transaction> transactions, string hash , long id, string name);

    void addUser(User newUser);

    void addMiner(Miner newMiner);

    const vector<User> &getUsers() const;

    const vector<Miner> &getMiners() const;

    const vector<Transaction> &getTransactions() const;

    string getLastHash(){
        return this->blockchainBlocks[this->blockchainBlocks.size()-1].getHash();
    }


private:
    void removeFromTransactionPool(vector<Transaction> transactions);
    vector<Block> blockchainBlocks;
    vector<User> users;
    vector<Miner> miners;
    vector<Transaction> transactions;
    int transactionCounter;
};


#endif //BLOCKCHAIN_BLOCKCHAIN_H

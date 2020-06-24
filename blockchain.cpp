//
// Created by omer on 15.06.2020.
//

#include "blockchain.h"
#include "hash.h"
#include <iostream>
#define MAX_SIZE 50
Blockchain::Blockchain() : transactionCounter(0), semaphore(MAX_SIZE){
    Block genesisBlock("00000000", {}, "6445f75a");
    this->blockchainBlocks.push_back(genesisBlock);
}

void Blockchain::addToTransactionPool(User paymentFrom, User paymentTo, long amount){
    Transaction newTransaction(transactionCounter,paymentFrom,paymentTo,amount);
    if(newTransaction.getValid()){
        transactions.push_back(newTransaction);
    }
    transactionCounter++;
}

void Blockchain::addBlock(vector<Transaction> transactions, string hash, long minerid, string minerName) {
    string blockstring = "";
    string prevHash = this->getLastHash();

    blockstring = blockstring + prevHash;
    for (int i=0; i<transactions.size(); i++){
        blockstring = blockstring + transactions[i].toString();
    }

    blockstring = blockstring + hash;

    string check = Hash::getHash(blockstring);
    if(check[0] =='0' && check[1] =='0' && check[2] =='0' && check[3] == '0'){
        std::cout << '\n' << "BLOCK FOUND BY MINER: "<< minerName <<" found hash: " << hash << " hash of whole block(must start with 5 zeros): " << check <<std::endl;
        this->removeFromTransactionPool(transactions);
        Block newBlock(this->getLastHash() , transactions, hash);
        this->blockchainBlocks.push_back(newBlock);
    }

}

void Blockchain::removeFromTransactionPool(vector<Transaction> transactions){
    for (int i=0; i< transactions.size() ; i++){
        for (int j=0; j < this->transactions.size() ; j++){
            if(this->transactions[j].toString() == transactions[i].toString()){
                this->transactions.erase(this->transactions.begin() + j);
                this->semaphore.notify();
            }
        }
    }
}

void Blockchain::addUser(User newUser){
    users.push_back(newUser);
}

void Blockchain::addMiner(Miner newMiner){
    miners.push_back(newMiner);
}

const vector<User> &Blockchain::getUsers() const {
    return users;
}

const vector<Miner> &Blockchain::getMiners() const {
    return miners;
}

const vector<Transaction> &Blockchain::getTransactions() const {
    return transactions;
}

#include <iostream>
#include "blockchain.h"
#include "block.h"
//#include "hash.h"
#include "transaction.h"
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include "hash.h"
#include <unistd.h>

#define NUM_USERS 5
#define NUM_MINERS 2

using namespace std;


struct UserThreadInput{
    long id;
    char* name;
    long prime1;
    long prime2;
    Blockchain* blockchain;
};

struct MinerThreadInput{
    long id;
    char* name;
    Blockchain* blockchain;
};


void *userThread(void *threadInput){
    long id = ((struct UserThreadInput *)threadInput)->id;
    string name = ((struct UserThreadInput *)threadInput)->name;
    long prime1 = ((struct UserThreadInput *)threadInput)->prime1;
    long prime2 = ((struct UserThreadInput *)threadInput)->prime2;
    Blockchain* blockchain = ((struct UserThreadInput *)threadInput)->blockchain;
    User user(id,name,prime1,prime2);
    std::stringstream msg;
    msg << id << "," << name << "," << prime1 << "," << prime2 << endl;
    std::cout<< msg.str();
    while(1){
        int randomAmount = rand() % 900 + 100;
        int randomUser = rand() % blockchain->getUsers().size();
        blockchain->mut.lock();
        User tempUser = blockchain->getUsers()[randomUser];
        blockchain->mut.unlock();
        if(tempUser.getId() != id){
            blockchain->semaphore.wait();
            blockchain->mut.lock();
            blockchain->addToTransactionPool(user,tempUser,randomAmount);
            blockchain->mut.unlock();

        }
    }
}

void *minerThread(void *threadInput){
    long id = ((struct MinerThreadInput *)threadInput)->id;
    string name = ((struct MinerThreadInput *)threadInput)->name;
    Blockchain* blockchain = ((struct MinerThreadInput *)threadInput)->blockchain;
    std::stringstream msg;
    msg << id << "," << name << endl;
    std::cout<< msg.str();
    while(1){
        blockchain->mut.lock();
        std::vector<Transaction> transactions = blockchain->getTransactions();
        string blockstring = blockchain->getLastHash();
        blockchain->mut.unlock();
        for (int i=0; i<transactions.size(); i++){
            blockstring = blockstring + transactions[i].toString();
        }

        string hash= "";
        for (int i =0 ; i < 8 ; i++){
            int v = rand() % 16;
            if (v < 10){
                hash = hash + to_string(v);
            }
            else{
                hash = hash + (char)(97+v-10);
            }
        }

        blockstring = blockstring + hash;

        string check = Hash::getHash(blockstring);
        if (check[0]=='0' && check[1]=='0'&& check[2]=='0' && check[3] =='0'){
            std::cout << '\n' << "BLOCK FOUND BY MINER: "<< " found hash: " << hash << " hash of whole block(must start with 5 zeros): " << check <<std::endl;
            blockchain->mut.lock();
            blockchain->addBlock( transactions , hash, id, name);
            blockchain->mut.unlock();
        }

    }
}

int main() {
    Blockchain* bc = new Blockchain();
    vector<UserThreadInput> users = { {0,"omer" ,3,5, bc} , {1,"bora", 5,7,bc} , {2,"berat" , 7,11,bc}, {3,"ahmet", 11,13,bc}, {4,"yaman", 13,17,bc}};
    vector<MinerThreadInput> miners = {{-1,"fatih", bc} , {-2,"mert",bc} };

    pthread_t uthreads[users.size()];
    pthread_t mthreads[miners.size()];

    for( int i = 0; i < users.size(); i++ ) {
        User newUser(users[i].id,users[i].name,users[i].prime1,users[i].prime2);
        bc->addUser(newUser);
    }

    for( int i = 0; i < miners.size(); i++ ) {
        Miner newMiner(miners[i].id,miners[i].name);
        bc->addMiner(newMiner);
    }

    srand (time(NULL));

    for( int i = 0; i < users.size(); i++ ) {
        UserThreadInput *user = (UserThreadInput *) malloc(sizeof(struct UserThreadInput));
        *user =  {users[i].id, users[i].name , users[i].prime1, users[i].prime2, users[i].blockchain} ;

        int rc = pthread_create(&uthreads[i], NULL, userThread, (void *)(user));
        if (rc) {
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
    }


    for( int i = 0; i < miners.size(); i++ ) {
        MinerThreadInput *miner = (MinerThreadInput *) malloc(sizeof(struct MinerThreadInput));
        *miner =  {miners[i].id , miners[i].name, miners[i].blockchain} ;

        int rc = pthread_create(&mthreads[i], NULL, minerThread, (void *)(miner));
        if (rc) {
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
    }
    for (int i=0; i < users.size();i++){
        pthread_join(uthreads[i], NULL);
    }
    for (int i=0; i < miners.size();i++){
        pthread_join(mthreads[i], NULL);
    }
    Transaction T(0, User(0,"omer" ,61,53) , User(1,"huseyin" ,5,7),100 );

    pthread_exit(NULL);
    return 0;
}
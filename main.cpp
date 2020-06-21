#include <iostream>
#include "blockchain.h"
#include "block.h"
#include "hash.h"
#include "transaction.h"
#include <string>
#include <vector>
#include <sstream>

#define NUM_USERS 5
#define NUM_MINERS 2

using namespace std;


struct UserThreadInput{
    long id;
    char* name;
};

struct MinerThreadInput{
    long id;
    char* name;
};


void *userThread(void *user){
    long id = ((struct UserThreadInput *)user)->id;
    string name = ((struct UserThreadInput *)user)->name;
    std::stringstream msg;
    msg << id << "," << name << endl;
    std::cout<< msg.str();
    pthread_exit(NULL);
}

void *minerThread(void *miner){
    long id = ((struct MinerThreadInput *)miner)->id;
    string name = ((struct MinerThreadInput *)miner)->name;
    std::stringstream msg;
    msg << id << "," << name << endl;
    std::cout<< msg.str();
    pthread_exit(NULL);
}

int main() {
    vector<User> users = {User(0,"omer") , User(1,"bora") , User(2,"berat"), User(3,"ahmet"), User(4,"yaman")};
    vector<Miner> miners = {Miner(-1,"fatih") , Miner(-2,"mert")};

    pthread_t uthreads[users.size()];
    pthread_t mthreads[miners.size()];


    for( int i = 0; i < users.size(); i++ ) {
        UserThreadInput *user = (UserThreadInput *) malloc(sizeof(struct UserThreadInput));
        *user =  {users[i].getId() , (char*)(users[i].getName().c_str())} ;

        int rc = pthread_create(&uthreads[i], NULL, userThread, (void *)(user));
        if (rc) {
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
    }


    for( int i = 0; i < miners.size(); i++ ) {
        MinerThreadInput *miner = (MinerThreadInput *) malloc(sizeof(struct MinerThreadInput));
        *miner =  {miners[i].getId() , (char*)(miners[i].getName().c_str())} ;

        int rc = pthread_create(&mthreads[i], NULL, minerThread, (void *)(miner));
        if (rc) {
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
    }

    pthread_exit(NULL);
    return 0;
}
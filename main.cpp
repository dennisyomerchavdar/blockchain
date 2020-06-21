#include <iostream>
#include "blockchain.h"
#include "block.h"
//#include "hash.h"
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
    long prime1;
    long prime2;
};

struct MinerThreadInput{
    long id;
    char* name;
};


void *userThread(void *user){
    long id = ((struct UserThreadInput *)user)->id;
    string name = ((struct UserThreadInput *)user)->name;
    long prime1 = ((struct UserThreadInput *)user)->prime1;
    long prime2 = ((struct UserThreadInput *)user)->prime2;
    std::stringstream msg;
    msg << id << "," << name << "," << prime1 << "," << prime2 << endl;
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
    vector<UserThreadInput> users = { {0,"omer" ,3,5} , {1,"bora", 5,7} , {2,"berat" , 7,11}, {3,"ahmet", 11,13}, {4,"yaman", 13,17}};
    vector<MinerThreadInput> miners = {{-1,"fatih"} , {-2,"mert"} };

    pthread_t uthreads[users.size()];
    pthread_t mthreads[miners.size()];


    for( int i = 0; i < users.size(); i++ ) {
        UserThreadInput *user = (UserThreadInput *) malloc(sizeof(struct UserThreadInput));
        *user =  {users[i].id, users[i].name , users[i].prime1, users[i].prime2} ;

        int rc = pthread_create(&uthreads[i], NULL, userThread, (void *)(user));
        if (rc) {
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
    }


    for( int i = 0; i < miners.size(); i++ ) {
        MinerThreadInput *miner = (MinerThreadInput *) malloc(sizeof(struct MinerThreadInput));
        *miner =  {miners[i].id , miners[i].name} ;

        int rc = pthread_create(&mthreads[i], NULL, minerThread, (void *)(miner));
        if (rc) {
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
    }
    for (int i=0; i < users.size();i++){
        pthread_join(uthreads[i], NULL);
    }
    Transaction T(0, User(0,"omer" ,61,53) , User(1,"huseyin" ,5,7),100 );

    pthread_exit(NULL);
    return 0;
}
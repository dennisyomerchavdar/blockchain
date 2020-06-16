//
// Created by omer on 16.06.2020.
//

#ifndef BLOCKCHAIN_USER_H
#define BLOCKCHAIN_USER_H
#include <string>
using namespace std;
class User {
public:
    User(long id, const string &name);

    const long getId() const;


    const string &getName() const;


private:
    const long id;
    const string name;
};


#endif //BLOCKCHAIN_USER_H

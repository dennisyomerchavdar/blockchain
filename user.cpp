//
// Created by omer on 16.06.2020.
//

#include "user.h"

long User::getId() {
    return id;
}


string &User::getName() {
    return name;
}



User::User(long id, const string &name) : id(id), name(name) {}

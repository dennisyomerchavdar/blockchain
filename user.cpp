//
// Created by omer on 16.06.2020.
//

#include "user.h"

const long User::getId() const {
    return id;
}


const string &User::getName() const {
    return name;
}



User::User(long id, const string &name) : id(id), name(name) {}

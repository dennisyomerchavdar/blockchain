//
// Created by omer on 16.06.2020.
//

#ifndef BLOCKCHAIN_TRANSACTION_H
#define BLOCKCHAIN_TRANSACTION_H

#include "user.h"
#include "string"
class Transaction {
public:
    User &getPaymentFrom();

    User &getPaymentTo();

    long getAmount();

    Transaction(User &paymentFrom, User &paymentTo, long amount);

private:
    User paymentFrom;
    User paymentTo;
    long amount;
    string toString(){
        return this->paymentFrom.getName() + ' ' + this->paymentTo.getName() + ' ' + to_string(this->amount);
    }
};


#endif //BLOCKCHAIN_TRANSACTION_H

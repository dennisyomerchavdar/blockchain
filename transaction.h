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

    bool getValid();

    Transaction(long id, User paymentFrom, User paymentTo, long amount);

    string toString(){
        return to_string(this->id) + ' ' + this->paymentFrom.getName() + ' ' + this->paymentTo.getName() + ' ' + to_string(this->amount) + ' ';
    }
private:
    long id;
    User paymentFrom;
    User paymentTo;
    long payerSignature;
    long amount;
    bool valid;

};


#endif //BLOCKCHAIN_TRANSACTION_H

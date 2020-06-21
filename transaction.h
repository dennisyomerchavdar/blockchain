//
// Created by omer on 16.06.2020.
//

#ifndef BLOCKCHAIN_TRANSACTION_H
#define BLOCKCHAIN_TRANSACTION_H

#include "user.h"
#include "string"
class Transaction {
public:
    const User &getPaymentFrom() const;

    const User &getPaymentTo() const;

    long getAmount() const;

    Transaction(const User &paymentFrom, const User &paymentTo, long amount);

private:
    const User paymentFrom;
    const User paymentTo;
    const long amount;
    string toString(){
        return this->paymentFrom.getName() + ' ' + this->paymentTo.getName() + ' ' + to_string(this->amount);
    }
};


#endif //BLOCKCHAIN_TRANSACTION_H

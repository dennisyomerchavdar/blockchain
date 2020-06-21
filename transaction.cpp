//
// Created by omer on 16.06.2020.
//

#include "transaction.h"

Transaction::Transaction(User &paymentFrom, User &paymentTo, long amount) : paymentFrom(paymentFrom),
                                                                                        paymentTo(paymentTo),
                                                                                        amount(amount) {}

 User &Transaction::getPaymentFrom(){
    return paymentFrom;
}

 User &Transaction::getPaymentTo(){
    return paymentTo;
}


long Transaction::getAmount() {
    return amount;
}


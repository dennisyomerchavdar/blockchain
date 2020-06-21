//
// Created by omer on 16.06.2020.
//

#include "transaction.h"

Transaction::Transaction(const User &paymentFrom, const User &paymentTo, long amount) : paymentFrom(paymentFrom),
                                                                                        paymentTo(paymentTo),
                                                                                        amount(amount) {}

const User &Transaction::getPaymentFrom() const {
    return paymentFrom;
}

const User &Transaction::getPaymentTo() const {
    return paymentTo;
}


long Transaction::getAmount() const {
    return amount;
}


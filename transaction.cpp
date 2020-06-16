//
// Created by omer on 16.06.2020.
//

#include "transaction.h"

Transaction::Transaction(const User &paymentFrom, const User &paymentTo, long amount) : paymentFrom(paymentFrom),
                                                                                        paymentTo(paymentTo),
                                                                                        amount(amount) {}

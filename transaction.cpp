//
// Created by omer on 16.06.2020.
//

#include "transaction.h"

Transaction::Transaction(User &paymentFrom, User &paymentTo, long amount) : paymentFrom(paymentFrom),
                                                                                        paymentTo(paymentTo),
                                                                                        amount(amount) {}

<<<<<<< HEAD
User &Transaction::getPaymentFrom(){
    return paymentFrom;
}

User &Transaction::getPaymentTo(){
=======
 User &Transaction::getPaymentFrom(){
    return paymentFrom;
}

 User &Transaction::getPaymentTo(){
>>>>>>> 5aa2d2710407047c96e17c2490b5a956b9ba2a6f
    return paymentTo;
}


<<<<<<< HEAD
long Transaction::getAmount(){
=======
long Transaction::getAmount() {
>>>>>>> 5aa2d2710407047c96e17c2490b5a956b9ba2a6f
    return amount;
}


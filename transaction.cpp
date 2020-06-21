//
// Created by omer on 16.06.2020.
//

#include "transaction.h"
#include <math.h>
#include <iostream>

using namespace std;
Transaction::Transaction(long id , User paymentFrom, User paymentTo, long amount) : id(id), paymentFrom(paymentFrom),
                                                                                        paymentTo(paymentTo),
                                                                                        amount(amount) {
    string transactionText = this->toString();
    long senderPublicKey = paymentFrom.getPublicKey();
    long senderPublicExp = paymentFrom.getPublicExp();

    vector<long> plainText;
    vector<long> cipherText;
    for(int i=0; i<transactionText.length(); i++){
        long c = (long)transactionText[i];
        long exp = 1;
        plainText.push_back(c);
        for(int j=0;j<senderPublicExp;j++){
            exp = exp * c;
            exp = exp % senderPublicKey;
        }
        cipherText.push_back(exp);
        //cipherText += to_string((long)pow((long)transactionText[i],senderPublicExp)%senderPublicKey);
    }
    cout << paymentFrom.getPublicExp() << endl;
    cout << paymentFrom.getPublicKey() << endl;
    cout << paymentFrom.getPrivateExp() << endl;
    cout << transactionText << endl;
    for(int i=0;i<plainText.size();i++){
        cout << plainText[i] << " ";
    }
    cout << endl;
    for(int i=0;i<cipherText.size();i++){
        cout << cipherText[i] << " ";
    }
    cout << endl;
    //cout << transactionText << endl;
    //cout << cipherText << endl;
    valid = paymentFrom.verify(plainText,cipherText) ? true : false;
    cout << valid ;

}

 User &Transaction::getPaymentFrom(){
    return paymentFrom;
}

User &Transaction::getPaymentTo(){
    return paymentTo;
}


long Transaction::getAmount() {
    return amount;
}


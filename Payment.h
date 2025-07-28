#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>
using namespace std;

class Payment {
public:
    static void makePayment(string clientID);
    static void viewPayments(string freelancerID);
};

#endif
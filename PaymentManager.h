#ifndef PAYMENTMANAGER_H
#define PAYMENTMANAGER_H

#include <string>
using namespace std;

class PaymentManager {
public:
    static void updatePaymentStatus(const string& freelancerID);
};

#endif
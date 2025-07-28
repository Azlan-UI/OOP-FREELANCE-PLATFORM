#ifndef FREELANCER_H
#define FREELANCER_H
#include "user.h"

class Freelancer : public User {
public:
    Freelancer(string n, string i);
    void displayMenu() override;
};

#endif

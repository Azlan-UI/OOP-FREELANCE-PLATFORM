#ifndef CLIENT_H
#define CLIENT_H
#include "user.h"

class Client : public User {
public:
    Client(string n, string i);
    void displayMenu() override;
};

#endif

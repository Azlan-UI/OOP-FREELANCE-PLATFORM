#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

class User {
protected:
    string name, id;
public:
    User(string n, string i) : name(n), id(i) {}
    virtual void displayMenu() = 0;
    string getID() const { return id; }
    virtual ~User() {}
};
#endif

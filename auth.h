#ifndef AUTH_H
#define AUTH_H
#include <string>
using namespace std;

class Auth {
public:
    static bool login(string& name, string& userID);
    static void registerUser();
};

#endif

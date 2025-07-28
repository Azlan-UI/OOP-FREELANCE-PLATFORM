#include "client.h"
#include <iostream>
using namespace std;

Client::Client(string n, string i) : User(n, i) {}

void Client::displayMenu() {
    cout << "\nClient Menu (" << name << ")\n";
    // Placeholder for client actions
}


#include "auth.h"
#include <iostream>
using namespace std;

int main() {
    int mainChoice;
    do {
        cout << "===============================\n";
        cout << " Welcome to Freelance Platform \n";
        cout << "===============================\n";
        cout << "1. Register\n2. Login\n0. Exit\nChoice: ";
        cin >> mainChoice;

        if (mainChoice == 1) {
            Auth::registerUser();
        } else if (mainChoice == 2) {
            string name, id;
            if (Auth::login(name, id)) {
                cout << "\nWelcome, " << name << " (" << id << ")!\n";
                // Role-based logic would go here
            } else {
                cout << "Login failed. Invalid credentials.\n";
            }
        } else if (mainChoice == 0) {
            cout << "Goodbye!\n";
        } else {
            cout << "Invalid option.\n";
        }
    } while (mainChoice != 0);

    return 0;
}

#include "freelancer.h"
#include <iostream>
using namespace std;

Freelancer::Freelancer(string n, string i) : User(n, i) {}

void Freelancer::displayMenu() {
    cout << "\nFreelancer Menu (" << name << ")\n";
    // Placeholder for freelancer actions
}

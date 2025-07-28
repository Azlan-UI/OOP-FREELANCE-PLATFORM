#include "chat.h"
#include <iostream>
using namespace std;

void Chat::startChat(const string& freelancerID, const string& gigID) {
    string answer;
    cout << "\nChat with Client (Gig ID: " << gigID << ")\n";
    cout << freelancerID << " is asking:\n";
    cout << "1. Can you please describe your expectations for this gig?\n";
    cout << "Client: "; getline(cin, answer);
    cout << "2. What is the deadline for this project?\n";
    cout << "Client: "; getline(cin, answer);
    cout << "3. Will there be any reference files or materials provided?\n";
    cout << "Client: "; getline(cin, answer);
    cout << "\nThanks! Freelancer will review your responses.\n";
}

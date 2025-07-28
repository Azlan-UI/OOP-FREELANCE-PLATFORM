#include "Payment.h"
#include <iostream>
#include <fstream>
#include <sstream>

void Payment::makePayment(string clientID) {
    string freelancerID, gigID;
    double amount;
    cin.ignore();
    cout << "Enter Freelancer ID to pay: ";
    getline(cin, freelancerID);
    cout << "Enter Gig ID: ";
    getline(cin, gigID);
    cout << "Enter amount to pay: ";
    cin >> amount;

    ofstream fout("payments.txt", ios::app);
    fout << freelancerID << "|" << clientID << "|" << gigID << "|" << amount << "|paid\n";
    fout.close();

    cout << " Payment recorded successfully!\n";
}

void Payment::viewPayments(string freelancerID) {
    ifstream fin("payments.txt");
    string line;
    double total = 0;
    cout << "\n Payment History for Freelancer ID: " << freelancerID << "\n";
    while (getline(fin, line)) {
        stringstream ss(line);
        string fID, cID, gID, amountStr, status;
        getline(ss, fID, '|');
        getline(ss, cID, '|');
        getline(ss, gID, '|');
        getline(ss, amountStr, '|');
        getline(ss, status, '|');

        if (fID == freelancerID) {
            double amount = stod(amountStr);
            cout << "Gig: " << gID << ", Amount: $" << amount << ", Status: " << status << "\n";
            total += amount;
        }
    }
    fin.close();

    cout << "Total Earnings: $" << total << "\n";
}
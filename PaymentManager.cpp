#include "PaymentManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

void PaymentManager::updatePaymentStatus(const string& freelancerID) {
    string gigID, newStatus;
    cout << "Enter Gig ID to update payment status: ";
    cin >> gigID;
    cout << "Enter new status (pending/paid/refunded): ";
    cin >> newStatus;

    ifstream fin("payments.txt");
    ofstream fout("temp.txt");
    string line;
    bool updated = false;

    while (getline(fin, line)) {
        stringstream ss(line);
        string fID, cID, gID, amount, status;
        getline(ss, fID, '|');
        getline(ss, cID, '|');
        getline(ss, gID, '|');
        getline(ss, amount, '|');
        getline(ss, status, '|');

        if (fID == freelancerID && gID == gigID) {
            fout << fID << '|' << cID << '|' << gID << '|' << amount << '|' << newStatus << "\n";
            updated = true;
        } else {
            fout << line << "\n";
        }
    }
    fin.close(); 
    fout.close();
    remove("payments.txt");
    rename("temp.txt", "payments.txt");

    if (updated) cout << "Payment status updated.\n";
    else cout << "No matching payment found.\n";
}
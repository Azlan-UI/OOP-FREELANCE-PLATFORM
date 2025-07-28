#include "ApplicationManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

void ApplicationManager::viewApplicationsForGig(const string& gigID) {
    ifstream fin("applications.txt");
    string line;
    bool found = false;

    cout << "\nApplications for Gig ID: " << gigID << "\n";
    while (getline(fin, line)) {
        stringstream ss(line);
        string clientID, appGigID, title, niche, price;
        getline(ss, clientID, '|');
        getline(ss, appGigID, '|');
        getline(ss, title, '|');
        getline(ss, niche, '|');
        getline(ss, price, '|');

        if (appGigID == gigID) {
            found = true;
            cout << "Client ID: " << clientID << ", Title: " << title 
                 << ", Niche: " << niche << ", Price: $" << price << "\n";
        }
    }
    if (!found) cout << "No applications found for this Gig.\n";
}
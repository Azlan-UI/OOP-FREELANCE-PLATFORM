#include "gig.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "chat.h"
using namespace std;

void Gig::postGig() {
    string gigID, title, desc, niche;
    double price;
    cin.ignore();
    cout << "\nEnter Gig ID: "; getline(cin, gigID);
    cout << "Enter Title: "; getline(cin, title);
    cout << "Enter Description: "; getline(cin, desc);
    cout << "Enter Niche: "; getline(cin, niche);
    cout << "Enter Price: "; cin >> price;

    ofstream fout("gigs.txt", ios::app);
    fout << gigID << "|" << title << "|" << desc << "|" << niche << "|" << price << "\n";
    fout.close();

    cout << "Gig Posted Successfully!\n";
}

void Gig::viewGigs() {
    ifstream fin("gigs.txt");
    string line;
    cout << "\nAvailable Gigs:\n";
    while (getline(fin, line)) {
        stringstream ss(line);
        string gigID, title, desc, niche, price;
        getline(ss, gigID, '|');
        getline(ss, title, '|');
        getline(ss, desc, '|');
        getline(ss, niche, '|');
        getline(ss, price, '|');
        cout << "ID: " << gigID << ", Title: " << title << ", Price: $" << price << "\n";
    }
}

void Gig::searchByGigID() {
    string searchGigID;
    cout << "Enter Gig ID to search: ";
    cin >> searchGigID;
    ifstream fin("gigs.txt");
    string line;
    bool found = false;
    while (getline(fin, line)) {
        stringstream ss(line);
        string gigID, title, desc, niche, price;
        getline(ss, gigID, '|');
        getline(ss, title, '|');
        getline(ss, desc, '|');
        getline(ss, niche, '|');
        getline(ss, price, '|');
        if (gigID == searchGigID) {
            found = true;
            cout << "ID: " << gigID << ", Title: " << title << ", Price: $" << price << "\n";
        }
    }
    if (!found) cout << "No gigs found.\n";
}

void Gig:: searchByNiche() {
    string searchNiche;
    
    cout << "Enter niche to search (case-insensitive)(Logo Design,Blog Writing,Website Development,Social Media Marketing,Video Editing are available): ";
    getline(cin >> ws, searchNiche);  
    
    ifstream fin("gigs.txt");
    string line;
    bool found = false;

    cout << "\n Matching Gigs:\n";
    while (getline(fin, line)) {
        stringstream ss(line);
        string gigID, title, desc, niche, price;
        getline(ss, gigID, '|');
        getline(ss, title, '|');
        getline(ss, desc, '|');
        getline(ss, niche, '|');
        getline(ss, price, '|');

        if (niche == searchNiche) {
            found = true;
            cout << "---------------------------------\n";
            cout << "ID: " << gigID << "\nTitle: " << title << "\nPrice: $" << price << "\n";
        }
    }
    if (!found) cout << "No gigs found for niche: " << searchNiche << "\n";
    
}
void Gig::applyToGig(string ClientID) {
    string gigID;
    cout << "Enter Gig ID to apply: ";
    cin >> gigID;

    ifstream fin("gigs.txt");
    string line, title, desc, niche;
    double price = 0;
    bool found = false;

    while (getline(fin, line)) {
        stringstream ss(line);
        string currentGigID, currentTitle, currentDesc, currentNiche, currentPriceStr;
        getline(ss, currentGigID, '|');
        getline(ss, currentTitle, '|');
        getline(ss, currentDesc, '|');
        getline(ss, currentNiche, '|');
        getline(ss, currentPriceStr, '|');
        if (currentGigID == gigID) {
            title = currentTitle;
            desc = currentDesc;
            niche = currentNiche;
            found = true;
            break;
        }
    }
    fin.close();
    if (!found) {
        cout << "Gig ID not found!\n";
        return;
    }

    ofstream fout("applications.txt", ios::app);
    fout << ClientID << "|" << gigID << "|" << title << "|" << niche << "|" << price << "\n";
    fout.close();

    cout << "Application Submitted!\n";
    Chat::startChat(ClientID, gigID);
}

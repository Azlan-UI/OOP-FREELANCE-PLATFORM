#include "Review.h"
#include <iostream>
#include <fstream>
#include <sstream>

void Review::leaveReview(string clientID) {
    string freelancerID, gigID, comment;
    int rating;

    cin.ignore();
    cout << "Enter Freelancer ID to review: ";
    getline(cin, freelancerID);
    cout << "Enter Gig ID: ";
    getline(cin, gigID);
    cout << "Enter rating (1-5): ";
    cin >> rating;
    cin.ignore();
    cout << "Enter comment: ";
    getline(cin, comment);

    ofstream fout("reviews.txt", ios::app);
    fout << freelancerID << "|" << clientID << "|" << gigID << "|" 
         << rating << "|" << comment << "\n";
    fout.close();

    cout << " Review submitted successfully!\n";
}

void Review::viewReviews(string freelancerID) {
    ifstream fin("reviews.txt");
    string line;
    int count = 0, sum = 0;

    cout << "\n Reviews for Freelancer ID: " << freelancerID << "\n";
    while (getline(fin, line)) {
        stringstream ss(line);
        string fID, cID, gID, ratingStr, comment;
        getline(ss, fID, '|');
        getline(ss, cID, '|');
        getline(ss, gID, '|');
        getline(ss, ratingStr, '|');
        getline(ss, comment, '|');

        if (fID == freelancerID) {
            int rating = stoi(ratingStr);
            cout << "Gig: " << gID << ", Rating: " << rating 
                 << ", Comment: " << comment << "\n";
            sum += rating;
            count++;
        }
    }
    
   
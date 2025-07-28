#ifndef GIG_H
#define GIG_H
#include <string>
using namespace std;

class Gig {
public:
    static void postGig();
    static void viewGigs();
    static void searchByGigID();
    static void searchByNiche();
    static void applyToGig(string ClientID);
};

#endif

#ifndef REVIEW_H
#define REVIEW_H

#include <string>
using namespace std;

class Review {
public:
    static void leaveReview(string clientID);
    static void viewReviews(string freelancerID);
};

#endif
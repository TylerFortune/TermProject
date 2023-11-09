#ifndef TEST_TERM_PROJECT_RAINBOW_H
#define TEST_TERM_PROJECT_RAINBOW_H

#endif //TEST_TERM_PROJECT_RAINBOW_H
// Term Project-Phase 1
// Professor Kardaras
// Authors: Tyler, Briggs, Pete
// Due: 9/19/23
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*
* This functions generates the object of a rainbow trible order.
*/
class rainbow {
private:
    string customerid; // Stores the customers ID
public:
    // Default constructor for rainbow trible
    rainbow() {
        this->customerid = "";
    }
    // Constructor that decalares the customers ID who registered for the trible
    rainbow(string id) {
        this->customerid = id;
    }

    // --------- GET FUNCTIONS ---------
    string getCustomerid() const {
        return this->customerid; // returns the customer ID's
    }
};
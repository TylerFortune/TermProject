#pragma once
#include <string>
using namespace std;

/******************
 *
 * Manager class - inherits from the Supervisor class
 *
 ******************/

class Manager : public Supervisor
{

private:
    // no private data members

public:

    // constructor that takes parameters
    Manager(string t, string n, string i, string b) : Supervisor(t, n, i, b)
    { }

    // that's really it.  The getCommission() method in the Supervisor class
    // will work fine here.  There's no need to introduce any new data fields
    // or member methods

};  // end class Manager


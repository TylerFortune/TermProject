#pragma once
#include <string>
using namespace std;
/******************
*
* SuperSales class - inherits from the Sales class
*
******************/

class SuperSales : public Sales
{
    // no data members, they're all declared in the base class

public:

    // constructor that takes parameters
    SuperSales(string t, string n, string i, string b) : Sales(t, n, i, b)
    { } // note that all of the work here is done in the base class.  All
    // of the parameters are passed to the parent class
    // constructor, which then passes them to the base class constructor.

// override the getCommission() method

    virtual double getCommission()
    {
        return 0.065 * get_total_sales();
    }

};  // End class SuperSales
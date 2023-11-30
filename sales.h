#include <string>

using namespace std;

/****************************
 *
 * Classes of salespersons
 *
 * CSCE 160 Fall 2023
 *
 ***************************/



/******************
 *
 * Sales class - inherits from absSales class
 *
 ******************/

class Sales : public absSales
{
    // no data members, they're all declared in the parent class

public:

    // constructor that takes parameters
    Sales(string t, string n, string i, string b) : absSales(t, n, i, b)
    { } // note that all of the work here is done in the base class.  All
    // of the parameters are passed to the base class constructor.

// override the getCommission() method

    virtual double getCommission()
    {
        return 0.05 * get_total_sales();
    }

};  // end class Sales





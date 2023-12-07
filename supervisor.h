#pragma once
#include <string>
using namespace std;

/******************
*
* Supervisor class - inherits from the SuperSales class
*
******************/

class Supervisor : public SuperSales
{

private:

    // declare a private data member for subordinate sales,
    // the sales made by people who report to this supervisor
    double sub_sales;

public:

    // constructor that takes parameters
    Supervisor(string t, string n, string i, string b) : SuperSales(t, n, i, b)
    {
        sub_sales = 0;
    }

    double get_sub_sales() {
        return sub_sales;
    }

    // increment method
    void inc_sub_sales(double amount)
    {
        sub_sales += amount;
    }

    // override the getCommission() method

    double getCommission()
    {
        return 0.065 * get_total_sales() + 0.03 * sub_sales;
    }

};  // end class Supervisor

#pragma once
#include <string>
using namespace std;

class absSales
{
private:

    string title, name, ID, bossID;
    double total_sales;  // needed to calculate commissions

public:

    // constructors
    absSales(string t, string n, string i, string b)
    {
        title = t;
        name = n;
        ID = i;
        bossID = b;
        total_sales = 0;
    }

    // default constructor
    absSales()
    {
        title = "";
        name = "";
        ID = "";
        bossID = "";
        total_sales = 0;
    }

    // The constructor sets all of the 
    // string fields.  We need a set method
    // (actually an increment method) for total_sales,
    // and get methods for the string fields

    void inc_total_sales(double amount)
    {
        total_sales += amount;
    }

    string getTitle() {
        return title;
    }

    string getName() {
        return name;
    }

    string getID() {
        return ID;
    }

    string getBossID() {
        return bossID;
    }

    double get_total_sales() {
        return total_sales;
    }

    // pure virtual function - makes this an abstract base class

    virtual double getCommission() = 0;

};  // end class absSales








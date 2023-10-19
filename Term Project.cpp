// Term Project-Phase 1
// Professor Kardaras
// Authors: Tyler, Briggs, Pete
// Due: 9/19/23

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include "customers.h"   // Includes calls from customer object class
#include "transaction.h" // Includes calls from transaction object class
#include "orders.h" // Includes calls from orders object class

using namespace std;
//------------Call Functions-------------



//------------Main Function-------------
int main()
{
    /*------------Necessary Variables-------------*/
    ifstream CFile; // Customer file
    ifstream TFile; // Transaction file
    string content; // Temp variable to store contents from files
    string CFileName = "customers.txt"; // Customer filename
    string TFileName = "transactions.txt"; // Transaction filename

    // Identifiers of a customer
    string FName, LName, address, city, state, zip;
    int ID;

    vector<customer> customers; // Vector that stores customer objects


    // Customer data file is opened
    CFile.open(CFileName);
    if (CFile.is_open()) {
        while (getline(CFile, content)) {
            string tempString = content;
            // Create an input stream
            istringstream iss(tempString);

            string token; // Token placeholder
            getline(iss, token, ';');
            ID = stoi(token); // Ignores the first entry

            // Stores all characteristics of customer
            getline(iss, token, ';');
            FName = atof(token.c_str());

            getline(iss, token, ';');
            LName = atof(token.c_str());

            getline(iss, token, ';');
            address = atof(token.c_str());

            getline(iss, token, ';');
            city = atof(token.c_str());

            getline(iss, token, ';');
            state = atof(token.c_str());

            getline(iss, token, ';');
            zip = atof(token.c_str());

            // Initalizes a new customer class object
            customer newcustomer(FName, LName, address, city, state, zip, ID);

            // Pushes new customer to vector
            customers.push_back(newcustomer);
        }
    }
    else {
        cout << "Error - cannot open " << CFileName << endl;  // Program Error
        return 1;
    }

    // Uncomment code to read customers vector

    for (int i = 0; i < customers.size(); i++) {
        cout << customers[i].getName() << "\n";
    }
   

    // This Program is a Menu driven with UI console display
    /*
    * ------------Menu Layout-------------
    * 1. Search for customer.
    * 2. Add customer.
    * 3. Read transaction history.
    * 4. Get customer transaction history.
    */
}

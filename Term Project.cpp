// Term Project-Phase 1
// Professor Kardaras
// Authors: Tyler, Briggs, Pete
// Due: 9/19/23

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include "customer.h"   // Includes calls from customer object
#include "transaction.h" // Includes calls from transaction objectr 

using namespace std;
//------------Call Functions-------------
// This function directly adds a new customer to the customer data file
void addCustomer(string firstName, string lastName, string address, ifstream outfile) {
    string filename = "customers.cta"
    // Open file for use
    outfile.open()
}

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
    string FName, LName, address, city, state, zip, ID;

    vector<customer> customers; // Vector that stores customer objects


    // Customer data file is opened
    CFile.open(CFilename);
    if (CFile.is_open()) {
        while (getline(CFile, content)) {
            // Create an input stream
            ifstringstream iss(content);

            string token; // Token placeholder
            getline(iss, token, ";");
            string ignore = token; // Save the first entry

            getline(iss, token, ';');
            Fname = atof(token.c_str());

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

            customer newcustomer = new customer(Fname, LName, address, city, state, zip);

            customers.push_back(newcustomer);
        }
    }
    else {
        cout << "Error - cannot open " << CFileName << endl;  // Program Error
        return 1;
    }

    // Uncomment code to read customers vector

    for (int i = 0; i < customers.size(); i++) {
        cout << customers[i] << "\n";
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

/*
* This heasder class contains characteristics of a customer
*/
using namespace std;
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

class customer {
// Private variables that remain in thne class.
private:
	string firstName;
	string lastName;
	string address;
	int ID;

	
// Public functions that are called from main()
public:
	// Initializes the characteristics of the customer.
	customer(string fname, string lname, string addy, int id ) {
		this->firstName = fname;
		this->lastName = lname;	
		this->address = addy;
		this->ID = id;
	}

	// function to genterate and return customer ID
	int getID(ifstream INFILE) {
		// Read ID contents of file

		// Loop to generate Random ID of 9 integers
		// Compare ID to contents in file

	}
	// returns customer name
	string getName() {
		return firstName, ", ", lastName;
	}
	string getAddress() {
		return address;
	}

};
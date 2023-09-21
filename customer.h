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
// Private vatiables that remain in thne class.
private:
	string firstName;
	string lastName;
	string address;

// Public functions that are called from main()
public:
	// Initializes the characteristics of the customer.
	void addCustomer(string fname, string lname, string addy) {
		firstName = fname;
		lastName = lname;
		address = addy;
	}
};
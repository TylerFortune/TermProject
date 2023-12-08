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
	string city;
	string state;
	string zip;
	int ID;

	
// Public functions that are called from main()
public:
	// Initializes the characteristics of the customer.
	customer(string fname, string lname, string addy, string city, string state, string zip) {
		this->firstName = fname;
		this->lastName = lname;
		this->address = addy;
		this->city = city;
		this->state = state;
		this->zip = zip;
	}
	customer(string fname, string lname, string addy, string city, string state, string zip, int id) {
		this->firstName = fname;
		this->lastName = lname;	
		this->address = addy;
		this->city = city;
		this->state = state;
		this->zip = zip;
		this->ID = id;
	}

	
	// returns customer characteristics
	string getFirstName() const {
		return this->firstName;
	}
	string getLastName() const {
		return this->lastName;
	}
	string getAddress() const {
		return this->address;
	}
	string getCity() const {
		return this->city;
	}
	string getState() const {
		return this->state;
	}
	string getZip() const {
		return this->zip;
	}
	int getID() const{
		return this->ID;
	}

	// Setter functions
	void setFirstName(const std::string& fname) {
		this->firstName = fname;
	}

	void setLastName(const std::string& lname) {
		this->lastName = lname;
	}

	void setAddress(const std::string& addy) {
		this->address = addy;
	}

	void setCity(const std::string& city) {
		this->city = city;
	}

	void setState(const std::string& state) {
		this->state = state;
	}

	void setZip(const std::string& zip) {
		this->zip = zip;
	}


};
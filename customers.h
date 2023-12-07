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
#include "transaction.h"

class customer {
// Private variables that remain in thne class.
public:
	string firstName;
    string encryptedPW;
	string lastName;
	string address;
	string city;
	string state;
	string zip;
	int ID;


	
// Public functions that are called from main()
public:
	// Initializes the characteristics of the customer.
	customer(string fname, string lname, string addy, string city, string state, string zip,string pw) {
		this->firstName = fname;
		this->lastName = lname;
		this->address = addy;
		this->city = city;
		this->state = state;
		this->zip = zip;
        this->encryptedPW=pw;

	}
	customer(string fname, string lname, string addy, string city, string state, string zip, int id,string pw) {
		this->firstName = fname;
		this->lastName = lname;	
		this->address = addy;
		this->city = city;
		this->state = state;
		this->zip = zip;
		this->ID = id;
        this->encryptedPW=pw;
	}

    string getEncryptedPW() const {
        return encryptedPW;
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
    void setEncryptedPW(const string& newPassword) {
        encryptedPW = newPassword;
    }
    static bool transactionIDExists(int id, const vector<Transactions>& transactionList) {
        for (const Transactions& t : transactionList) {
            if (t.getOrderId() == id) {
                return true; // ID already exists
            }
        }
        return false; // ID does not exist
    }
    // New method to assign a new transaction ID
    static int assignTransactionID(const vector<Transactions>& transactionList) {
        int newTransactionID;
        do {
            newTransactionID = rand() % 900000 + 100000;
        } while (transactionIDExists(newTransactionID, transactionList));

        return newTransactionID;
    }



};
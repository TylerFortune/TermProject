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
class orders {
private:
	int quantity; // Amount of giblets
	int transactionID; // Transaction ID
	double price; // Price of total order
	string date; // Date of purchase
public:
	// Initializes a customer object and assigns its characteristics
	orders(int quantity, int transactionID, double price, string date) {
		this->quantity = quantity;
		this->transactionID = transactionID;
		this->price = price;
		this->date = date;
	}

	int getQuantity() {
		return this->quantity;
	}
	int getTransactionID() {
		return this->transactionID;
	}
	double getPrice() {
		return this->price;
	}
	string getDate() {
		return this->date;
	}
};
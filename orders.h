using namespace std;

#pragma once

#include <iostream>
#include <string>

class orders {
private:
    int orderID;       // Order ID
    int transactionID; // Transaction ID
    int quantity;      // Amount of giblets
    double price;      // Price of the total order
    string orderDate;  // Date of purchase

public:
    // Constructor to initialize the order object and assign its characteristics
    orders(int orderID, int transactionID, int quantity, double price, string orderDate) {
        this->orderID = orderID;
        this->transactionID = transactionID;
        this->quantity = quantity;
        this->price = price;
        this->orderDate = orderDate;
    }

    // Getters for the order characteristics
    int getOrderID() const {
        return this->orderID;
    }

    int getTransactionID() const {
        return this->transactionID;
    }

    int getQuantity() const {
        return this->quantity;
    }

    double getPrice() const {
        return this->price;
    }

    string getOrderDate() const {
        return this->orderDate;
    }
    // Setters for the order characteristics
    void setOrderID(int orderID) {
        this->orderID = orderID;
    }

    void setTransactionID(int transactionID) {
        this->transactionID = transactionID;
    }

    void setQuantity(int quantity) {
        this->quantity = quantity;
    }

    void setPrice(double price) {
        this->price = price;
    }

    void setOrderDate(string orderDate) {
        this->orderDate = orderDate;
    }
};
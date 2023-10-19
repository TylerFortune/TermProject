#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "customers.h"
#include "transaction.h"
#include "orders.h"

using namespace std;

// Function declarations
void searchForCustomer(const vector<customer>& customers, const vector<Transactions>& transactionList, const vector<orders>& orderList);
void addCustomer(vector<customer>& customers);
int assignID(const vector<customer>& customers);
void readTransactionHistory(const vector<Transactions>& transactionList);
void getCustomerTransactionHistory(const vector<Transactions>& transactionList, int customerID);
void addOrder(vector<orders>& orderList, vector<Transactions>& transactionList, const vector<customer>& customers);
void updateOrder(vector<orders>& orderList);

// Function to check if a given ID already exists in the vector
bool idExists(int id, const vector<customer>& customers) {
    for (const customer& c : customers) {
        if (c.getID() == id) {
            return true; // ID already exists
        }
    }
    return false; // ID does not exist
}

// Main Function
int main() {
    ifstream CFile("customers.txt"); // Customer file
    ifstream TFile("transactions.txt"); // Transaction file
    ifstream OFile("orders.txt"); // Orders file

    vector<customer> customers; // Vector that stores customer objects
    vector<orders> orderList; // Vector that stores order objects
    vector<Transactions> transactionList; // Vector that stores transaction objects

    // Reading customer data file
    if (CFile.is_open()) {
        string content;
        while (getline(CFile, content)) {
            string tempString = content;
            istringstream iss(tempString);

            int ID;
            string FName, LName, address, city, state, zip;

            getline(iss, FName, ';');
            getline(iss, LName, ';');
            getline(iss, address, ';');
            getline(iss, city, ';');
            getline(iss, state, ';');
            getline(iss, zip, ';');
            getline(iss, content, ';'); // Ignoring the first entry
            ID = stoi(content);

            customer newcustomer(FName, LName, address, city, state, zip, ID);
            customers.push_back(newcustomer);
        }
        CFile.close();
    }

    // Reading transaction data file
    if (TFile.is_open()) {
        string content;
        while (getline(TFile, content)) {
            string tempString1 = content;
            istringstream iss(tempString1);
            string token;
            getline(iss, token, ':');
            int customerID = stoi(token);
            getline(iss, token, ':');
            int transactionID = stoi(token);
            Transactions newTransaction(customerID, transactionID);
            transactionList.push_back(newTransaction);
        }
        TFile.close();
    }

    // Reading order data file
    if (OFile.is_open()) {
        string content;
        while (getline(OFile, content)) {
            string tempString2 = content;
            istringstream iss(tempString2);
            string token;

            getline(iss, token, ':');
            int orderId = stoi(token);

            getline(iss, token, ':');
            int transactionID = stoi(token);

            getline(iss, token, ';');
            int quantity = stoi(token);

            getline(iss, token, ':');
            double price = stod(token);

            getline(iss, token, ':');
            string orderDate = token;

            orders newOrder(orderId, transactionID, quantity, price, orderDate);
            orderList.push_back(newOrder);
        }
        OFile.close();
    }
    else {
        cout << "Error - cannot open orders.txt" << endl;
        return 1;
    }

    int choice;
    do {
        // Display the main menu
        cout << "\n=== Customer and Order Management System ===" << endl;
        cout << "1. Search for Customer" << endl;
        cout << "2. Add Customer" << endl;
        cout << "3. Read Transaction History" << endl;
        cout << "4. Get Customer Transaction History" << endl;
        cout << "5. Add Order" << endl;
        cout << "6. Update Order Information" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            searchForCustomer(customers, transactionList, orderList);
            break;
        case 2:
            addCustomer(customers);
            break;
        case 3:
            readTransactionHistory(transactionList);
            break;
        case 4:
            int customerID;
            cout << "Enter customer ID: ";
            cin >> customerID;
            getCustomerTransactionHistory(transactionList, customerID);
            break;
        case 5:
            addOrder(orderList, transactionList, customers);
            break;
        case 6:
            updateOrder(orderList);
            break;
        case 7:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}

// Function to search for a customer by ID or last name
void searchForCustomer(const vector<customer>& customers, const vector<Transactions>& transactionList, const vector<orders>& orderList) {
    int searchOption;
    cout << "How would you like to search for the customer?" << endl;
    cout << "1. Search by ID" << endl;
    cout << "2. Search by Last Name" << endl;
    cout << "Enter your choice: ";
    cin >> searchOption;

    if (searchOption == 1) {
        // Search by ID
        int id;
        cout << "Enter customer ID to search: ";
        cin >> id;

        for (const customer& c : customers) {
            if (c.getID() == id) {
                cout << "Customer Information:" << endl;
                cout << "ID: " << c.getID() << endl;
                cout << "First Name: " << c.getFirstName() << endl;
                cout << "Last Name: " << c.getLastName() << endl;
                cout << "Address: " << c.getAddress() << endl;
                cout << "City: " << c.getCity() << endl;
                cout << "State: " << c.getState() << endl;
                cout << "ZIP Code: " << c.getZip() << endl;

                int transactionID = getTransactionID(id, transactionList);

                if (transactionID != -1) {
                    cout << "Transaction ID: " << transactionID << endl;
                    getOrderDetails(transactionID, orderList);
                }
                else {
                    cout << "No transaction history found for this customer." << endl;
                }

                return;
            }
        }

        cout << "Customer not found with ID " << id << endl;
    }
    else if (searchOption == 2) {
        // Search by Last Name
        string lastName;
        cout << "Enter customer last name: ";
        cin >> lastName;

        vector<const customer*> matchingCustomers;

        for (const customer& c : customers) {
            if (c.getLastName() == lastName) {
                matchingCustomers.push_back(&c);
            }
        }

        if (matchingCustomers.empty()) {
            cout << "No customers found with last name " << lastName << endl;
        }
        else if (matchingCustomers.size() == 1) {
            const customer& matchedCustomer = *matchingCustomers[0];
            cout << "Customer Information:" << endl;
            cout << "ID: " << matchedCustomer.getID() << endl;
            cout << "First Name: " << matchedCustomer.getFirstName() << endl;
            cout << "Last Name: " << matchedCustomer.getLastName() << endl;
            cout << "Address: " << matchedCustomer.getAddress() << endl;
            cout << "City: " << matchedCustomer.getCity() << endl;
            cout << "State: " << matchedCustomer.getState() << endl;
            cout << "ZIP Code: " << matchedCustomer.getZip() << endl;

            int transactionID = getTransactionID(matchedCustomer.getID(), transactionList);

            if (transactionID != -1) {
                cout << "Transaction ID: " << transactionID << endl;
                getOrderDetails(transactionID, orderList);
            }
            else {
                cout << "No transaction history found for this customer." << endl;
            }

        }
        else {
            cout << "Multiple customers found with last name " << lastName << ". Choose one:" << endl;

            for (int i = 0; i < matchingCustomers.size(); ++i) {
                const customer& matchedCustomer = *matchingCustomers[i];
                cout << i + 1 << ". " << matchedCustomer.getLastName() << ", " << matchedCustomer.getFirstName() << endl;
            }

            int choice;
            cout << "Enter the number corresponding to the customer you want to view: ";
            cin >> choice;

            if (choice >= 1 && choice <= matchingCustomers.size()) {
                const customer& chosenCustomer = *matchingCustomers[choice - 1];
                cout << "Customer Information:" << endl;
                cout << "ID: " << chosenCustomer.getID() << endl;
                cout << "First Name: " << chosenCustomer.getFirstName() << endl;
                cout << "Last Name: " << chosenCustomer.getLastName() << endl;
                cout << "Address: " << chosenCustomer.getAddress() << endl;
                cout << "City: " << chosenCustomer.getCity() << endl;
                cout << "State: " << chosenCustomer.getState() << endl;
                cout << "ZIP Code: " << chosenCustomer.getZip() << endl;

                int transactionID = getTransactionID(chosenCustomer.getID(), transactionList);

                if (transactionID != -1) {
                    cout << "Transaction ID: " << transactionID << endl;
                    getOrderDetails(transactionID, orderList);
                }
                else {
                    cout << "No transaction history found for this customer." << endl;
                }

            }
            else {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
    else {
        cout << "Invalid search option. Please try again." << endl;
    }
}

// Function to add a new customer to the vector
void addCustomer(vector<customer>& customers) {
    string fname, lname, addy, city, state, zip;
    cout << "Enter first name: ";
    cin >> fname;
    cout << "Enter last name: ";
    cin >> lname;
    cout << "Enter address: ";
    cin.ignore();
    getline(cin, addy);
    cout << "Enter city: ";
    cin >> city;
    cout << "Enter state: ";
    cin >> state;
    cout << "Enter ZIP code: ";
    cin >> zip;

    int newID = assignID(customers);
    customer newCustomer(fname, lname, addy, city, state, zip, newID);
    customers.push_back(newCustomer);

    cout << "Customer added successfully!" << endl;
}

// Function to add a new order to the order list
void addOrder(vector<orders>& orderList, vector<Transactions>& transactionList, const vector<customer>& customers) {
    int customerID, transactionID, quantity;
    double price;
    string orderDate;

    cout << "Enter customer ID: ";
    cin >> customerID;

    bool customerExists = false;
    for (const customer& c : customers) {
        if (c.getID() == customerID) {
            customerExists = true;
            break;
        }
    }

    if (!customerExists) {
        cout << "Customer with ID " << customerID << " does not exist." << endl;
        return;
    }

    cout << "Enter transaction ID: ";
    cin >> transactionID;
    cout << "Enter quantity: ";
    cin >> quantity;
    cout << "Enter price: ";
    cin >> price;
    cout << "Enter order date: ";
    cin >> orderDate;

    orders newOrder(customerID, transactionID, quantity, price, orderDate);
    orderList.push_back(newOrder);

    Transactions newTransaction(customerID, transactionID);
    transactionList.push_back(newTransaction);

    cout << "Order added successfully!" << endl;
}

// Function to update order information
void updateOrder(vector<orders>& orderList) {
    int orderID;
    cout << "Enter order ID to update: ";
    cin >> orderID;

    for (orders& o : orderList) {
        if (o.getOrderID() == orderID) {
            int newQuantity;
            double newPrice;
            string newOrderDate;

            cout << "Enter new quantity: ";
            cin >> newQuantity;
            cout << "Enter new price: ";
            cin >> newPrice;
            cout << "Enter new order date: ";
            cin >> newOrderDate;

            o.setQuantity(newQuantity);
            o.setPrice(newPrice);
            o.setOrderDate(newOrderDate);

            cout << "Order updated successfully!" << endl;
            return;
        }
    }

    cout << "Order not found with ID " << orderID << endl;
}

// Function to read transaction history
void readTransactionHistory(const vector<Transactions>& transactionList) {
    for (const Transactions& t : transactionList) {
        cout << "Transaction ID: " << t.getOrderId() << endl;
    }
}

// Function to get customer transaction history
void getCustomerTransactionHistory(const vector<Transactions>& transactionList, int customerID) {
    cout << "Transaction History for Customer ID " << customerID << ":" << endl;

    for (const Transactions& t : transactionList) {
        if (t.getCustomerId() == customerID) {
            cout << "Transaction ID: " << t.getOrderId() << endl;
        }
    }
}

// Function to generate a new six-digit ID for a customer
int assignID(const vector<customer>& customers) {
    int newID;
    do {
        newID = rand() % 900000 + 100000;
    } while (idExists(newID, customers));

    return newID;
}

// Function to get transaction ID for a customer
int getTransactionID(int customerID, const vector<Transactions>& transactionList) {
    for (const Transactions& t : transactionList) {
        if (t.getCustomerId() == customerID) {
            return t.getOrderId();
        }
    }
    return -1;
}

// Function to get order details for a transaction ID
void getOrderDetails(int transactionID, const vector<orders>& orderList) {
    cout << "Order Details for Transaction ID " << transactionID << ":" << endl;

    for (const orders& o : orderList) {
        if (o.getTransactionID() == transactionID) {
            cout << "Order ID: " << o.getOrderID() << endl;
            cout << "Quantity: " << o.getQuantity() << endl;
            cout << "Price: " << o.getPrice() << endl;
            cout << "Order Date: " << o.getOrderDate() << endl;
        }
    }
}

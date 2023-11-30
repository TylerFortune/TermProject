// Term Project-Phase 1
// Professor Kardaras
// Authors: Tyler, Briggs, Pete
// Due: 9/19/23
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*
* This functions generates the object of a rainbow trible order.
*/
class rainbow {
private:
	string customerid; // Stores the customers ID
public:
	// Default constructor for rainbow trible  
	rainbow() {
		this->customerid = "";
	}
	// Constructor that decalares the customers ID who registered for the trible
	rainbow(string id) {
		this->customerid = id;
	}

	// --------- GET FUNCTIONS ---------
	string getCustomerid() const {
		return this->customerid; // returns the customer ID's 
	}
};

/*
// Function to print the commission for each salesperson
void printCommission(const vector<absSales*>& salesStaff, const vector<Transactions>& transactionList, const vector<orders>& orderList) {
    for (absSales* salesperson : salesStaff) {
        int salesPersonID = stoi(salesperson->getID());

        // Calculate gross sales for the salesperson
        double grossSales = 0.0;
        for (const Transactions& transaction : transactionList) {
            if (transaction.getSalesPersonID() == salesPersonID) {
                int orderID = transaction.getOrderID();
                for (const orders& order : orderList) {
                    if (order.getOrderID() == orderID) {
                        grossSales += order.getPrice() * order.getQuantity();
                    }
                }
            }
        }

        // Calculate commission based on the title
        double commission = 0.0;
        if (salesperson->getTitle() == "Sales") {
            commission = 0.05 * grossSales;
        } else if (salesperson->getTitle() == "SuperSales") {
            commission = 0.065 * grossSales;
        } else if (salesperson->getTitle() == "Supervisor") {
            // Calculate commission for Supervisor
            commission = 0.065 * grossSales;

            // Calculate commission for the salespersons reporting to the Supervisor
            for (const absSales* subordinate : salesStaff) {
                if (stoi(subordinate->getBossID()) == salesPersonID) {
                    commission += 0.03 * calculateSubordinateSales(subordinate, transactionList, orderList);
                }
            }
        } else if (salesperson->getTitle() == "Manager") {
            // Calculate commission for Manager
            commission = 0.065 * grossSales;

            // Calculate commission for all the people below the Manager in the organization chart
            for (const absSales* subordinate : salesStaff) {
                if (isInSubordinateHierarchy(salesPersonID, subordinate, salesStaff)) {
                    commission += 0.03 * calculateSubordinateSales(subordinate, transactionList, orderList);
                }
            }
        }

        // Print the commission for the salesperson
        cout << "Salesperson: " << salesperson->getName() << endl;
        cout << "Gross Sales: $" << grossSales << endl;
        cout << "Commission: $" << commission << endl;
        cout << "----------------------" << endl;
    }
}

// Function to calculate the total sales for a subordinate salesperson
double calculateSubordinateSales(const absSales* subordinate, const vector<Transactions>& transactionList, const vector<orders>& orderList) {
    int subordinateID = stoi(subordinate->getID());
    double subordinateSales = 0.0;

    for (const Transactions& transaction : transactionList) {
        if (transaction.getSalesPersonID() == subordinateID) {
            int orderID = transaction.getOrderID();
            for (const orders& order : orderList) {
                if (order.getOrderID() == orderID) {
                    subordinateSales += order.getPrice() * order.getQuantity();
                }
            }
        }
    }

    return subordinateSales;
}

// Function to check if a salesperson is in the subordinate hierarchy of a boss
bool isInSubordinateHierarchy(int bossID, const absSales* subordinate, const vector<absSales*>& salesStaff) {
    int subordinateID = stoi(subordinate->getID());

    for (const absSales* sub : salesStaff) {
        if (stoi(sub->getBossID()) == bossID) {
            if (stoi(sub->getID()) == subordinateID || isInSubordinateHierarchy(subordinateID, sub, salesStaff)) {
                return true;
            }
        }
    }

    return false;
}*/
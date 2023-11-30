#include <iostream>
#include <fstream>
#include <string>

class Transactions {
private:
    int TransactionId;
    int SalesID;
    int OrderId;

public:
    Transactions(int tID, int sID, int oID) {
        this->TransactionId = tID;
        this->SalesID = sID;
        this->OrderId = oID;
    }

    // Getter methods (unchanged)
    int getTransactionID() const {
        return this->TransactionId;
    }

    int getSalesPersonID() const {
        return this->SalesID;
    }
    int getOrderId() const {
        return this->OrderId;
    }

    // Setter methods
    void setTransactionId(int cID) {
        this->TransactionId = cID;
    }

    void setOrderId(int oID) {
        this->OrderId = oID;
    }
    void setSalesPersonID(int sID) {
        this->SalesID = sID;
    }
};

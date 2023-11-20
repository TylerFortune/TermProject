#ifndef TEST_TERM_PROJECT_TRANSACTION_H
#define TEST_TERM_PROJECT_TRANSACTION_H

#endif //TEST_TERM_PROJECT_TRANSACTION_H
#include <iostream>
#include <fstream>
#include <string>

class Transactions {
private:
    int OrderId;
    int CustomerId;
    int salesId;

public:
    Transactions(int cID, int SID, int oID) {
        this->OrderId = oID;
        this->CustomerId = cID;
        this->salesId = SID;
    }

    // Getter methods (unchanged)
    int getCustomerId() const {
        return this->CustomerId;
    }

    int getOrderId() const {
        return this->OrderId;
    }
    int getSalesId() const{
        return this->salesId;
    }

    // Setter methods
    void setCustomerId(int cID) {
        this->CustomerId = cID;
    }

    void setOrderId(int oID) {
        this->OrderId = oID;
    }
    void setSalesID(int sID){
        this->salesId = sID;
    }

};
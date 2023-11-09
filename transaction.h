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

public:
    Transactions(int oID, int cID) {
        this->OrderId = oID;
        this->CustomerId = cID;
    }

    // Getter methods (unchanged)
    int getCustomerId() const {
        return this->CustomerId;
    }

    int getOrderId() const {
        return this->OrderId;
    }

    // Setter methods
    void setCustomerId(int cID) {
        this->CustomerId = cID;
    }

    void setOrderId(int oID) {
        this->OrderId = oID;
    }
};
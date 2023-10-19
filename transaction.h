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
    int getCustomerId() {
        return this->CustomerId;
    }

    int getOrderId() {
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

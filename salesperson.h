#ifndef TEST_TERM_PROJECT_SALESPERSON_H
#define TEST_TERM_PROJECT_SALESPERSON_H

#endif //TEST_TERM_PROJECT_SALESPERSON_H

#include <string>
#include "abstractsales.h"
using namespace std;

class salesperson : public abstractsales{
private:
    double commission = 0.05;
    double totalSalesProfit;
public:
    // Default Constructor
    salesperson(){
        this->name = "";
        this->position = "";
        this->EID = 0;
        this->bossID = 0;
        this->commission = 0.05;
    }
    // Constructor with appropriate parameters
    salesperson(string n, string p, int employeeID, int BID){
        this->name = p;
        this->position = n;
        this->EID = employeeID;
        this->bossID = BID;
        this->commission = 0.05;
    }

    // ===== Get Functions =====
    double getCommission(){
        return this->commission;
    }
    double getTotalProfit(){
        return totalSalesProfit;
    }

    // Function to add sale to total amount
    void addSales(double amt){
        totalSalesProfit += (amt * commission);
    }


};
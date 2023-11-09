//
// Created by tyler on 11/8/2023.
//

#ifndef TEST_TERM_PROJECT_SUPERSALES_H
#define TEST_TERM_PROJECT_SUPERSALES_H

#endif //TEST_TERM_PROJECT_SUPERSALES_H
#include <string>
#include "abstractsales.h"
using namespace std;

class superSales : abstractsales{
private:
    double commission = 0.10;
public:
    // Default Constructor
    superSales(){
        this->EID = 0;
        this->bossID = 0;
        this->commission = 0.10;
    }
    // Constructor with appropriate parameters
    superSales(string n, string p, int employeeID, int BID){
        this->EID = employeeID;
        this->position = p;
        this->name = n;
        this->bossID = BID;
        this->commission = 0.10;
    }

    // ===== Get Functions =====
    double getCommission(){
        return this->commission;
    }
    double getTotalProfit(double total){
        return total * this->commission;
    }
};
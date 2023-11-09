//
// Created by tyler on 11/8/2023.
//

#include "abstractsales.h"

#ifndef TEST_TERM_PROJECT_MANAGER_H
#define TEST_TERM_PROJECT_MANAGER_H

#endif //TEST_TERM_PROJECT_MANAGER_H
#include <string>
#include <vector>

using namespace std;
class manager : abstractsales{
private:
    double totalSalesProfit;
    double commission;
public:
    // Default constructor
    manager(){
        commission = .065;
    }
    manager(string n, string p, int EID, int bossID){
        this->name = n;
        this->position = p;
        this->EID =EID;
        this->bossID = bossID; // In this stage of the program, manager has no one above them. Placeholder value.
    }
    // Function that sets total commission
    double totalCommission(double belowCommission, double selfSales){
        return belowCommission + selfSales;
    }
    //Function to make a sale
    void makeSale(double amt){
        totalSalesProfit += amt * commission;
    }
    // Function that adds a sales to totalSales profit
    void addProfit(double amt){
        totalSalesProfit = totalSalesProfit + amt;
    }
};
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
class manager : public abstractsales{
private:
    double totalSalesProfit;
    double commission = 0.065;
    double undercommission = 0.03;
public:
    // Default constructor
    manager(){
        commission = .065;
        this->undercommission = 0.03;
    }
    manager(string p, string n, int EID, int bossID){
        this->name = n;
        this->position = p;
        this->EID =EID;
        this->bossID = bossID; // In this stage of the program, manager has no one above them. Placeholder value.
        commission = .065;
        this->undercommission = 0.03;
    }
    // Function that sets total commission
    double totalCommission(double belowCommission, double selfSales){
        return belowCommission + selfSales;
    }
    // Function that adds a sales to totalSales profit
    void addSales(double amt){
        totalSalesProfit += amt * commission;
    }
};
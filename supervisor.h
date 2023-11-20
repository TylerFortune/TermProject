//
// Created by tyler on 11/8/2023.
//

#ifndef TEST_TERM_PROJECT_SUPERVISOR_H
#define TEST_TERM_PROJECT_SUPERVISOR_H

#endif //TEST_TERM_PROJECT_SUPERVISOR_H

#include "abstractsales.h"
#include <string>
#include <vector>

using namespace std;

class supervisor: public abstractsales{
private:
    double commission = 0.065; // 6.5% commission for any sales made by supervisor
    double undersales = 0.03; // 3% commission for sales for employees under them
    double totalSales = 0;
public:
    //Default Constructor
    supervisor(){
        this->name = " ";
        this->position = "p";
        this->EID = 000;
        this->bossID = 000;
        this->commission = 0.065;
        this->undersales = 0.03;
    };
    // Main Constructor
    supervisor(string p, string n, int EID, int BID){
        this->name = n;
        this->position = p;
        this->EID = EID;
        this->bossID = BID;
    }

    //====== GET FUNCTIONS ======
    double getTotalSales(){
        return this->totalSales;
    }
    void addSales(double amt){
        totalSales += amt * this->commission;
    }




};
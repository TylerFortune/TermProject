#ifndef TEST_TERM_PROJECT_ABSTRACTSALES_H
#define TEST_TERM_PROJECT_ABSTRACTSALES_H



#include <string>
#include <ostream>

using namespace std;


class abstractsales{
private:
    // This class has no private variable as it's used for a parent for public functions
public:
    string name, position;
    int EID, bossID;

    /*
     * This abstract sales class generalizes the needs for each type of sales person
     * for them to adopt in subclasses.
     */

    // ===== Set Functions =====
    void setName(string n){
        this->name = n;
    }
    void setPosition(string spot){
        this->position = spot;
    }
    void setEID(int employeeID){
        this->EID = employeeID;
    }
    void setBossID(int bossesID) {
        this->bossID = bossesID;
    }
    // ===== Get Functions =====
    string getName() const{
        return this->name;
    }
    string getPosition() const{
        return this->position;
    }
    int getEID() const{
        return this->EID;
    }
    int getBossID() const{
        return this->bossID;
    }
};

#endif //TEST_TERM_PROJECT_ABSTRACTSALES_H
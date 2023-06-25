#include <iostream>
#include <string>
#include "Facility.h"
using namespace std;

#ifndef Part_h
#define Part_h

// Class Part
class Part {
private:
    double amount;
    double interest_payed;
    Facility *facility;

public:
    Part(double amount, Facility &facility){
        this->amount = amount;
        this->facility = &facility;
        this->interest_payed = facility.refund(amount);
    }

    double getAmount() const {
        return amount;
    }

    double getInterest() const {
        return interest_payed;
    }
};


#endif /* Part_h */

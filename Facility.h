#include <iostream>
#include <string>
#include "Lender.h"
#include <vector>

using namespace std;

#ifndef Facility_h
#define Facility_h



// Classe Facility
class Facility {
private:
    std::string startDate;
    std::string endDate;
    double trancheAmount;
    std::string currency;
    std::vector<Lender> lenders;
    double interestRate;
    double outStandingBalance;


public:
    Facility(){}
    Facility(std::string startDate, std::string endDate, double trancheAmount, std::string currency,
             std::vector<Lender> lenders, double interestRate) {
        this->startDate = startDate;
        this->endDate = endDate;
        this->trancheAmount = trancheAmount;
        this->currency = currency;
        this->lenders = lenders;
        this->interestRate = interestRate;
        this->outStandingBalance = trancheAmount;
    }

    std::string getStartDate() const {
        return startDate;
    }

    std::string getEndDate() const {
        return endDate;
    }

    double getTrancheAmount() const {
        return trancheAmount;
    }

    std::string getCurrency() const {
        return currency;
    }

    std::vector<Lender> getLenders() const {
        return lenders;
    }

    double getInterestRate() const {
        return interestRate;
    }

    double getOutstandingBalance() const {
        return this->outStandingBalance;
    }

    double refund(double amount) {
        double interest_payed = (amount * interestRate) / this->trancheAmount;
        double cash_interested_payed = amount * interest_payed;

        this->outStandingBalance = this->outStandingBalance - amount;
        this->interestRate = (this->interestRate * this->outStandingBalance) / this->trancheAmount;

        return cash_interested_payed;

    }
};


#endif /* Facility_h */

#include <iostream>
#include <string>
#include "Part.h"
#include "Portfolio.h"

using namespace std;

#ifndef Borrower_h
#define Borrower_h


// Classe Borrower
class Borrower {
private:
    std::string name;
    Portfolio portfolio;

public:
    Borrower(){}
    Borrower(std::string name,Portfolio portfolio) {
        this->name = name;
        this->portfolio = portfolio;
    }

    std::string getName() const {
        return name;
    }

    Portfolio getPortfolio() const {
        return portfolio;
    }

    void addPart(Part p){
  
        this->portfolio.addPart(p);
    }



};


#endif /* Borrower_h */

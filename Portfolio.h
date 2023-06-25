#include <iostream>
#include <string>
#include "Part.h"
#include "Facility.h"

using namespace std;

#ifndef Portofolio_h
#define Portofolio_h

// Classe Portfolio
class Portfolio {
private:
    std::vector<Part> parts;
    

public:
    Portfolio(){}

    void addPart(Part part) {
        parts.push_back(part);
    }

    std::vector<Part> getParts() const {
        return parts;
    }
};


#endif /* Portofolio_h */

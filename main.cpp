#include <iostream>
#include <string>
#include <vector>

#include "Facility.h"
#include "Deal.h"
#include "Borrower.h"
#include "Lender.h"

int main() {
    
    Lender *LCL = new Lender("LCL");
    Lender *BNP = new Lender("BNP");
    Lender *CACIB = new Lender("CACIB");
    Lender *SoGen = new Lender("SoGen");

    // Get Name Lender LCL :
    std::cout << LCL->getName() << std::endl;
    
    Portfolio *Portfolio_Air_France = new Portfolio();
    Borrower *AirFrance = new Borrower("Air France",*Portfolio_Air_France);
    
    //Get Name Borrower Air France :
    std::cout << AirFrance->getName() << std::endl;

    std::vector<Lender> f1_lenders;
    f1_lenders.push_back(*LCL);
    f1_lenders.push_back(*BNP);
    Facility *f1 = new Facility("25-06-2023","25-06,2024",100000,"EUR",f1_lenders,0.04); // 100.000 à 4%
    
    //Get the second Lender of the Facility f1 name --> BNP :
    std::cout << f1->getLenders()[1].getName() << std::endl;
    
    // Facilities Deal 1
    std::vector<Facility*> facilities_deal_one;
    facilities_deal_one.push_back(f1);
    
    //Pool Deal one including l'agent
    std::vector<Lender> Pool;
    Pool.push_back(*LCL);
    Pool.push_back(*BNP);
    Pool.push_back(*CACIB); //CACIB est l'agent -> appartient  à la Pool aussi
    
    Deal *d1 = new Deal("AZ88",*CACIB,Pool,*AirFrance,1000000,"EUR","20-06-2023","20-06-2024","OnGoing",facilities_deal_one);
    
    //get Agent Name -> CACIB :
    std::cout << d1->getAgent() << std::endl;
    
    //get Name of First Lender of the Pool -> LCL
    std::cout << d1->getPool()[0].getName() << std::endl;
    
    //get Interst Rate of the First Facility of the Deal -> 0.04 soit 4%
    std::cout << d1->getFacilities()[0]->getInterestRate() << std::endl;
    
    // get OutStadingBalance of the First Facility donc 100.000 euros car on a encore rien remboursé
    std::cout << d1->getFacilities()[0]->getOutstandingBalance() << std::endl;
    
    // check si on remboursé tout le deal --> False soit 0
    std::cout << d1->totalRefund() << std::endl;
    
    //crée une remboursement/part 10000 EUR pour la facility f1
    Part *p = new Part(10000, *f1);
    
    //Cash Interest paid pour cette part --> 10000 * ((10000*0.04)/ 100000) = 40 soit un interest de 0.4%
    // 100.000 -> 0.04 (4%)
    // 10.000 -> 0.004 (0.4%)
    // Ainsi on doit payer 40 EUR d'intérêts :
    std::cout << p->getInterest() << std::endl;
    
    // Et outStandingBalance de Facility 1 doit être égale à 90.000 car rembourse 10.000
    // on peut soit y avoir accés direct depuis f1 ou passer par deal 1 car f1 est une facility du deal 1 les deux donneront 90.000 parce qu'on travaille avec des pointeurs ...
    std::cout << f1->getOutstandingBalance() << std::endl;
    std::cout << d1->getFacilities()[0]->getOutstandingBalance() <<std::endl;
    
    // Le nouveau Taux pour la Facility 1 sera de (0.04*90.000)/100.000 = 0.036 soit 3.6 % car 3.6% pour 90.000 est équivalente à 4% pour 100.000
    // Même principe qu'avant on test avec deal aussi pour être sur qu'on bien codé avec les pointeurs : on doit avoir le même résultat à savoir 3.6% soit 0.036
    std::cout << f1->getInterestRate() << std::endl;
    std::cout << d1->getFacilities()[0]->getInterestRate() << std::endl;
    
    return 0;
}

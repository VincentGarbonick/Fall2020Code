//
//   COPYRIGHT (C) Student@zips.uakron.edu>, 2020  All rights reserved.
//   Student Name
//   Purpose: This is myCode and is based upon what we study for Comp Sci
//
#include <cassert>
#include <iosfwd>
#include <iostream>
#include <iomanip>
#include <limits>  // numeric_limits<std::streamsize> for validations
#include <memory>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>

int gSIZE = 10;


class TaxPayer 
{
    private: 
        float taxRate;
        float income; 
        float taxes;

    public:
        // prototypes for mutators
        float getTaxRate();
        float getIncome();
        float getTaxes();
        
        void  setTaxRate(float);
        void  setIncome(float);
        void  setTaxes(float);
};

void taxTaker(TaxPayer * citizen);
void taxPrint(TaxPayer * citizen);

int main(void)
{
    
    TaxPayer *citizens = new TaxPayer[gSIZE];
    taxTaker(citizens);
    taxPrint(citizens);

    std::cout << "end of task E" << std::endl;

    return 0;
}



// taxtaker randomly instantiates and populates a dynamic array of TaxPayers
// Precon: pointer to dynamic array of taxpayer
// postcon: randomply populated taxpayer objects with taxes calculated 
void taxTaker(TaxPayer * citizen)
{
    float tempIntegerValue; 
    int randomIncome;
    float randomRate; 
    
    for(int i = 0; i < gSIZE; i++)
    {
        
        randomIncome = rand()%(50000-5000 + 1) + 5000;

        tempIntegerValue = ( rand()%(990-1 + 1) + 1 );        
        randomRate = tempIntegerValue/100;
        
        // std::cout << "RandIncome:" << randomIncome << std::endl;
        // std::cout << "RandRate:" << randomRate << "\n" << std::endl;
        
        // set randomly calculated values
        (citizen+i)->setIncome(randomIncome);
        (citizen+i)->setTaxRate(randomRate);
        (citizen+i)->setTaxes( ( (randomRate/100) * randomIncome ) );

    }

    return;
} 


// taxPrint: prints out the tax rate for all taxpayers in the dynamic array
// precon: pointer to dynamic array of taxpayer
// postcon: none 
void taxPrint(TaxPayer * citizen)
{

    for(int i = 0; i < gSIZE; i++)
    {
        std::cout << "Taxes for citizen " << i << ": " << (citizen + i)->getTaxes() << std::endl;
    }

    return;
}

// getTaxRate returns the value in the member variable taxRate
// precondtion: no parameters
// postcondition: return the object taxRate
float TaxPayer::getTaxRate()
{
    return taxRate;
}

// getIncome returns the value in the member variable income
// precondtion: no parameters
// postcondition: return the object income
float TaxPayer::getIncome()
{
    return income;
}

// getTaxes returns the value in the member variable taxes
// precondtion: no parameters
// postcondition: return the object taxes
float TaxPayer::getTaxes()
{
    return taxes;
}



// setTaxRate sets the value of the member variable taxRate
// precondtion: pass the function the valid user choice
// postcondition: sets the object value if valid
void TaxPayer::setTaxRate(float sTaxRate)
{
    taxRate = sTaxRate;
    return;
}

// setIncome sets the value of the member variable income
// precondtion: pass the function the valid user choice
// postcondition: sets the object value if valid
void TaxPayer::setIncome(float sIncome)
{
    income = sIncome;
    return;
}

// setTaxes sets the value of the member variable taxes
// precondtion: pass the function the valid user choice
// postcondition: sets the object value if valid
void TaxPayer::setTaxes(float sTaxes)
{
    taxes = sTaxes;
    return;
}
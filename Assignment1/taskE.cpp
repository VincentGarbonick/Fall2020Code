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

int main(void)
{
    return 0;
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
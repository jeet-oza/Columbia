//
//  AmericanOption.cpp
//  Group A-B
//
//  Created by Jeet Oza on 4/17/18.
//  Copyright © 2018 Jeet Oza. All rights reserved.
//

#include "AmericanOption.hpp"
#include <cmath>
#include <iostream>
using namespace std;


// Kernel Functions (Haug)
double AmericanOption::CallPrice(double U) const
{
    double sig2 = sig*sig;
    double fac = b/sig2 - 0.5; fac *= fac;
    double y1 = 0.5 - b/sig2 + sqrt(fac + 2.0*r/sig2);
    
    
    if (1.0 == y1)
        return U;
    
    double fac2 = ((y1 - 1.0)*U) / (y1 * K);
    double c = K * pow(fac2, y1) / (y1 - 1.0);
    
    return c;
}

double AmericanOption::PutPrice(double U) const
{
    double sig2 = sig*sig;
    double fac = b/sig2 - 0.5; fac *= fac;
    double y2 = 0.5 - b/sig2 - sqrt(fac + 2.0*r/sig2);
    
    if (0.0 == y2)
        return U;
    
    double fac2 = ((y2 - 1.0)*U) / (y2 * K);
    double p = K * pow(fac2, y2) / (1.0 - y2);
    
    return p;
}

/////////////////////////////////////////////////////////////////////////////////////

void AmericanOption::init()
{    // Initialise all default values
    
    // Default values
    r = 0.05;
    sig= 0.2;
    
    K = 110.0;
    b = r;            // Black and Scholes stock option model (1973)
    
    optType = "C";        // European Call Option (this is the default type)
}

void AmericanOption::copy( const AmericanOption& o2)
{
    
    r    = o2.r;
    sig = o2.sig;
    K    = o2.K;
    b    = o2.b;
    
    optType = o2.optType;
    
}

AmericanOption::AmericanOption()
{ // Default call option
    
    init();
}

AmericanOption::AmericanOption(const AmericanOption& o2)
{ // Copy constructor
    
    copy(o2);
}

AmericanOption::AmericanOption (const string& optionType)
{    // Create option type
    
    init();
    optType = optionType;
    
    if (optType == "c")
        optType = "C";
    
}



AmericanOption::~AmericanOption()
{
    
}


AmericanOption& AmericanOption::operator = (const AmericanOption& option2)
{
    
    if (this == &option2) return *this;
    
    copy (option2);
    
    return *this;
}

// Functions that calculate option price and sensitivities
double AmericanOption::Price(double U) const
{
    
    
    if (optType == "C")
    {
        //        cout << "calling call\n";
        return CallPrice(U);
    }
    else
    {
        //        cout << "calling put\n";
        return PutPrice(U);
    }
}

// Modifier functions
void AmericanOption::toggle()
{ // Change option type (C/P, P/C)
    
    if (optType == "C")
        optType = "P";
    else
        optType = "C";
}

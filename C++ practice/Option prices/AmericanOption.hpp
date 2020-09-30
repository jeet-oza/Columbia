//
//  AmericanOption.hpp
//  Group A-B
//
//  american perpetual option
//  
//  Created by Jeet Oza on 4/17/18.
//  Copyright © 2018 Jeet Oza. All rights reserved.
//

#ifndef AmericanOption_hpp
#define AmericanOption_hpp

#include <string>
using namespace std;

//  class for americal perpetual option
class AmericanOption
{
private:
    
    void init();    // Initialise all default values
    void copy(const AmericanOption& o2);
    
    // 'Kernel' functions for option calculations
    double CallPrice(double U) const;
    double PutPrice(double U) const;

public:
    
    // Member data public for convenience; anyway, the format will
    // not change for a plain option.
    
    double r;        // Interest rate
    double sig;        // Volatility
    double K;        // Strike price
    double b;        // Cost of carry
    
    string optType;    // Option name (call, put)
    string unam;    // Name of underlying asset
    
    
public:    // Public functions
    AmericanOption();                            // Default call option
    AmericanOption(const AmericanOption& option2);    // Copy constructor
    AmericanOption (const string& optionType);    // Create option type
    virtual ~AmericanOption();
    
    AmericanOption& operator = (const AmericanOption& option2);
    
    // Functions that calculate option price and sensitivities
    double Price(double U) const;

    // Modifier functions
    void toggle();        // Change option type (C/P, P/C)
};
#endif /* AmericanOption_hpp */

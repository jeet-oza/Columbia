//
//  optionPrices.hpp
//  Group A-B
//
//  Created by Jeet Oza on 4/15/18.
//  Copyright © 2018 Jeet Oza. All rights reserved.
//

#ifndef optionPrices_hpp
#define optionPrices_hpp

#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include "EuropeanOption.hpp"
#include "AmericanOption.hpp"
using namespace std;


namespace optionPrices
{
string optType;
    
double priceExact(double S, double T, double sig, double K, double r)
{ //    option price from input argument
    
    EuropeanOption anOption;
    anOption.optType = optType;
    anOption.K = K;
    anOption.T = T;
    anOption.r = r;
    anOption.sig = sig;
    anOption.b = anOption.r;
    return anOption.Price(S);
}

//  result vector of option prices based on array of stock price and other input variable
vector<double> priceExact(const vector<double>& Sarr, double T, double sig, double K, double r,
                          double (*optionPrices)(double S, double T, double sig, double K, double r) )
{ // This function uses a function pointer, so flexible

    vector<double> result(Sarr.size());

    for (std::size_t n = 0; n < result.size(); ++n)
    {
        result[n] = optionPrices(Sarr[n], T, sig, K, r);
    }

    return result;
}

//  input vector of vector;inside vector is in order stoke price, Time horizon, volatility, strike price and rate
vector<double> priceExact(const vector<vector<double>>& Arr,
                          double (*optionPrices)(double S, double T, double sig, double K, double r))
{

    //    vector<vector<double> > result(xarr.size(), tarr.size());

    vector<double> result(Arr.size());
    for (std::size_t j = 0; j < Arr.size(); ++j)
    {
        result[j] = optionPrices(Arr[j][0], Arr[j][1], Arr[j][2], Arr[j][3], Arr[j][4]);
    }


    return result;
}
    
double sensitivityExact(double S, double T, double sig, double K, double r, string Type)
{ //    option price from input argument
    
    EuropeanOption anOption;
    anOption.optType = optType;
    anOption.K = K;
    anOption.T = T;
    anOption.r = r;
    anOption.sig = sig;
    anOption.b = anOption.r;
    return anOption.Sensitivity(Type, S);
}

//  result vector of option prices based on array of stock price and other input variable
vector<double> sensitivityExact(const vector<double>& Sarr, double T, double sig, double K, double r, string Type,
                          double (*optionPrices)(double S, double T, double sig, double K, double r, string Type) )
{ // This function uses a function pointer, so flexible
    
    vector<double> result(Sarr.size());
    
    for (std::size_t n = 0; n < result.size(); ++n)
    {
        result[n] = optionPrices(Sarr[n], T, sig, K, r, Type);
    }
    
    return result;
}

//  input vector of vector;inside vector is in order stoke price, Time horizon, volatility, strike price and rate
vector<double> sensitivityExact(const vector<vector<double>>& Arr, string Type,
                          double (*optionPrices)(double S, double T, double sig, double K, double r, string Type))
{
    
    //    vector<vector<double> > result(xarr.size(), tarr.size());
    
    vector<double> result(Arr.size());
    for (std::size_t j = 0; j < Arr.size(); ++j)
    {
        result[j] = optionPrices(Arr[j][0], Arr[j][1], Arr[j][2], Arr[j][3], Arr[j][4], Type);
    }
    
    
    return result;
}
    
    double americanPrice(double S, double sig, double K, double r, double b)
    { //    option price from input argument
        
        AmericanOption anOption;
        anOption.optType = optType;
        anOption.K = K;
        anOption.r = r;
        anOption.sig = sig;
        anOption.b = b;
        return anOption.Price(S);
    }
    
    //  result vector of option prices based on array of stock price and other input variable
    vector<double> AmericanPrice(const vector<double>& Sarr, double sig, double K, double r, double b,
                              double (*optionPrices)(double S, double sig, double K, double r, double b) )
    { // This function uses a function pointer, so flexible
        
        vector<double> result(Sarr.size());
        
        for (std::size_t n = 0; n < result.size(); ++n)
        {
            result[n] = optionPrices(Sarr[n], sig, K, r, b);
        }
        
        return result;
    }
    
    //  input vector of vector;inside vector is in order stoke price, volatility, strike price, rate and b
    vector<double> AmericanPrice(const vector<vector<double>>& Arr,
                              double (*optionPrices)(double S, double sig, double K, double r, double b))
    {
        
        //    vector<vector<double> > result(xarr.size(), tarr.size());
        
        vector<double> result(Arr.size());
        for (std::size_t j = 0; j < Arr.size(); ++j)
        {
            result[j] = optionPrices(Arr[j][0], Arr[j][1], Arr[j][2], Arr[j][3], Arr[j][4]);
        }
        
        
        return result;
    }
    
} // end of namespace 'optionPrices'
#endif /* optionPrices_hpp */

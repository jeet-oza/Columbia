// EurpeanOption.cpp
//
//  Group A-B
//  European option source file

//  Created by Jeet Oza on 4/15/18.
//  Copyright © 2018 Jeet Oza. All rights reserved.
//

#include "EuropeanOption.hpp"
#include "SensitivityException.hpp"
#include <cmath>
#include <algorithm>
#include <iostream>
#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions.hpp> // For non-member functions of distributions
using namespace std;
using namespace boost::math;

double EuropeanOption::n(double x) const
{ 
    normal_distribution<> myNormal(0.0, 1.0);
    return pdf(myNormal, x);
}

double EuropeanOption::N(double x) const
{ // The approximation to the cumulative normal distribution
    normal_distribution<> myNormal(0.0, 1.0);
    return cdf(myNormal, x);
}


// Kernel Functions (Haug)
double EuropeanOption::CallPrice(double U) const
{

	double tmp = sig * sqrt(T);

	double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;
	double d2 = d1 - tmp;


	return (U * exp((b-r)*T) * N(d1)) - (K * exp(-r * T)* N(d2));

}

double EuropeanOption::PutPrice(double U) const
{

	double tmp = sig * sqrt(T);
	double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;
	double d2 = d1 - tmp;

	return (K * exp(-r * T)* N(-d2)) - (U * exp((b-r)*T) * N(-d1));

}

double EuropeanOption::CallDelta(double U) const
{
	double tmp = sig * sqrt(T);

	double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;


	return exp((b-r)*T) * N(d1);
}

double EuropeanOption::PutDelta(double U) const
{
	double tmp = sig * sqrt(T);

	double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;

	return exp((b-r)*T) * (N(d1) - 1.0);
}


double EuropeanOption::CallGamma(double U) const
{
    double tmp = sig * sqrt(T);

    double d1 = ( log(U/K) + (b + (sig*sig)*0.5 ) * T )/ tmp;
    double d2 = d1 - tmp;

    return ( n(d1) * exp((b-r)*T) ) / (U * tmp);
}

double EuropeanOption::PutGamma(double U) const
{
    return CallGamma(U);
}


double EuropeanOption::CallVega(double U) const
{
    double tmp = sig * sqrt(T);

    double d1 = ( log(U/K) + (b + (sig*sig)*0.5 ) * T )/ tmp;

    return (U * exp((b-r)*T) * n(d1) * sqrt(T) );
}

double EuropeanOption::PutVega(double U) const
{
    return CallVega(U);
}

double EuropeanOption::CallTheta(double U) const
{

    double tmp = sig * sqrt(T);

    double d1 = ( log(U/K) + (b + (sig*sig)*0.5 ) * T )/ tmp;
    double d2 = d1 - tmp;

    double t1 =  (U * exp((b-r)*T ) * n(d1) * sig * 0.5 )/ sqrt(T);
    double t2 =  (b-r)*(U * exp((b-r)*T) * N(d1));
    double t3 =  r * K * exp(-r * T) * N(d2);

    return -(t1 + t2 + t3);
}


double EuropeanOption::PutTheta(double U) const
{

    double tmp = sig * sqrt(T);

    double d1 = ( log(U/K) + (b + (sig*sig)*0.5 ) * T )/ tmp;
    double d2 = d1 - tmp;

    double t1 =  (U * exp( (b-r)*T ) * n(d1) * sig * 0.5 )/ sqrt(T);
    double t2 =  (b-r)*(U * exp((b-r)*T) * N(-d1));
    double t3 =  r * K * exp(-r * T) * N(-d2);

    return t2 + t3 - t1;
}

double EuropeanOption::CallRho(double U) const
{

    double tmp = sig * sqrt(T);

    double d1 = ( log(U/K) + (b + (sig*sig)*0.5 ) * T )/ tmp;
    double d2 = d1 - tmp;

    if (b != 0.0)
        return T * K * exp(-r * T) * N(d2);
    else
        return - T * CallPrice( U );

}


double EuropeanOption::PutRho(double U) const
{
    double tmp = sig * sqrt(T);

    double d1 = ( log(U/K) + (b + (sig*sig)*0.5 ) * T )/ tmp;
    double d2 = d1 - tmp;

    if (b != 0.0)
        return - T * K * exp(-r * T) * N(-d2);
    else
        return - T * PutPrice(U);
}


/////////////////////////////////////////////////////////////////////////////////////

void EuropeanOption::init()
{	// Initialise all default values

	// Default values
	r = 0.05;
	sig= 0.2;

	K = 110.0;
	T = 0.5;

	b = r;			// Black and Scholes stock option model (1973)
	
	optType = "C";		// European Call Option (this is the default type)
}

void EuropeanOption::copy( const EuropeanOption& o2)
{

	r	= o2.r;
	sig = o2.sig;	
	K	= o2.K;
	T	= o2.T;
	b	= o2.b;
	
	optType = o2.optType;
	
}

EuropeanOption::EuropeanOption() 
{ // Default call option

	init();
}

EuropeanOption::EuropeanOption(const EuropeanOption& o2)
{ // Copy constructor

	copy(o2);
}

EuropeanOption::EuropeanOption (const string& optionType)
{	// Create option type

	init();
	optType = optionType;

	if (optType == "c")
		optType = "C";

}



EuropeanOption::~EuropeanOption()
{

}


EuropeanOption& EuropeanOption::operator = (const EuropeanOption& option2)
{

	if (this == &option2) return *this;

	copy (option2);

	return *this;
}

// Functions that calculate option price and sensitivities
double EuropeanOption::Price(double U) const
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

double EuropeanOption::Delta(double U) const 
{
	if (optType == "C")
		return CallDelta(U);
	else
		return PutDelta(U);

}

//  approx formula with differentiation with 3 point formula
double EuropeanOption::ApproxDelta(double U, double h) const
{
    return (Price(U+h) - Price(U-h)) / (2 * h);
}

double EuropeanOption::Gamma(double U) const
{
    if (optType == "C")
        return CallGamma(U);
    else
        return PutGamma(U);

}

double EuropeanOption::ApproxGamma(double U, double h) const
{
    return (Price(U+h) - (2 * Price(U))+ Price(U-h)) / (pow(h, 2));
}

double EuropeanOption::Vega(double U) const
{
    if (optType == "C")
        return CallVega(U);
    else
        return PutVega(U);

}

double EuropeanOption::Theta(double U) const
{
    if (optType == "C")
        return CallTheta(U);
    else
        return PutTheta(U);

}

double EuropeanOption::Rho(double U) const
{
    if (optType == "C")
        return CallRho(U);
    else
        return PutRho(U);
}

double EuropeanOption::Sensitivity(string Type, double U) const
{
    std::transform(Type.begin(), Type.end(), Type.begin(), ::tolower);
    double result;
    if( Type == "price" )
        result = Price(U);
    else if (Type == "delta" )
        result = Delta(U);
    else if (Type == "gamma" )
        result = Gamma(U);
    else if (Type == "approxdelta" )
        result = ApproxDelta(U, 0.01);  //  coding small value for h
    else if (Type == "approxgamma" )
        result = ApproxGamma(U, 0.01);  //  coding small value for h
    else if (Type == "vega" )
        result = Vega(U);
    else if (Type == "theta" )
        result = Theta(U);
    else if (Type == "rho" )
        result = Rho(U);
    else
        throw SensitivityException(Type);
    return result;
}


// Modifier functions
void EuropeanOption::toggle()
{ // Change option type (C/P, P/C)

	if (optType == "C")
		optType = "P";
	else
		optType = "C";
}



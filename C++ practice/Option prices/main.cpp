//
//  main.cpp
//  Group A-B
//
//  Created by Jeet Oza on 4/15/18.
//  Copyright © 2018 Jeet Oza. All rights reserved.
//

#include "EuropeanOption.hpp"
#include "AmericanOption.hpp"
#include "optionPrices.hpp"
#include "OptionException.hpp"
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
/* Cost of carry factor b must be included in formulae depending on the
 derivative type. These are used in the generalised Black-Scholes formula.
 If r is the risk-free interest and q is the continuous dividend yield then
 the cost-of-carry b per derivative type is:
 
 a) Black-Scholes (1973) stock option model: b = r
 b) b = r - q Merton (1973) stock option model with continuous dividend yield
 c) b = 0 Black (1976) futures option model
 d) b = r - rf Garman and Kohlhagen (1983) currency option model, where rf is the
 'foreign' interest rate
 */

//  function to get putprice from puct-call parity
double putPriceFromParity( EuropeanOption aCallOption, double stockPrice )
{
    //  P = C - S + k*e^-rT
    double K = aCallOption.K;
    double r = aCallOption.r;
    double T = aCallOption.T;
    double PVOfK = K * exp( -1 * r * T );
    double callPrice = aCallOption.Price(stockPrice);
    double putPrice = callPrice + PVOfK - stockPrice;
    return putPrice;
}

//  function to create mesh
vector<double> createMesh( double rMin, double rMax, double h)
{
    int NR = (rMax - rMin ) / h;
    vector<double> xarr(NR);
    xarr[0] = rMin;
    xarr[xarr.size()-1] = rMax; // To avoid rounding errors at x = 1.
    for (std::size_t n = 1; n < xarr.size()-1; ++n)
    {
        xarr[n] = xarr[n-1] + h;
    }
    return xarr;
}

vector<vector<double>> createMeshArray(vector<double> sArr, vector<double> TArr, vector<double> sigArr,
                                       vector<double> KArr, vector<double> rArr)
{
    vector<vector<double>> result(sArr.size()*TArr.size() * sigArr.size() * KArr.size() * rArr.size());
    for (std::size_t j = 0; j < result.size(); ++j)
    {
        result[j] = std::vector<double>(5);
    }
    int i = 0;
    //  looping over each vector to vreate vector of vectors
    for (int a = 0; a < sArr.size(); ++a)
    {
        for (int b = 0; b < TArr.size(); ++b)
        {
            for (int c = 0; c < sigArr.size(); ++c)
            {
                for (int d = 0; d < KArr.size(); ++d)
                {
                    for (int e = 0; e < rArr.size(); ++e)
                    {
                        result[i][0] = sArr[a];
                        result[i][1] = TArr[b];
                        result[i][2] = sigArr[c];
                        result[i][3] = KArr[d];
                        result[i][4] = rArr[e];
                        i++;
                    }
                }
            }
        }
    }
    return result;
}

void print(const vector<double>& vec)
{
    cout << endl;
    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << ", ";
    }
    cout << endl;
}

int main()
{ // All options are European
    
    // Call option on a stock (b = r by default)
    //  get put and call price from exact solution
    cout << "Part A : a) call and put option prices" << endl;
    
    //  Batch 1: T = 0.25, K = 65, sig = 0.30, r = 0.08, S = 60 (then C = 2.13337, P = 5.84628).
    cout << "batch1: " << endl;
    EuropeanOption callOption1;
    callOption1.optType = "C";
    callOption1.K = 65;
    callOption1.T = 0.25;
    callOption1.r = 0.08;
    callOption1.sig = 0.3;
    callOption1.b = callOption1.r;
    EuropeanOption putOption1 = callOption1;
    putOption1.optType = "P";
    double S1 = 60;
    cout << "Call price : " << callOption1.Price(S1) <<endl;
    cout << "Put price : " << putOption1.Price(S1) <<endl;

    //  Batch 2: T = 1.0, K = 100, sig = 0.2, r = 0.0, S = 100 (then C = 7.96557, P = 7.96557).
    cout << "batch2: " << endl;
    EuropeanOption callOption2;
    callOption2.optType = "C";
    callOption2.K = 100;
    callOption2.T = 1.0;
    callOption2.r = 0.0;
    callOption2.sig = 0.2;
    callOption2.b = callOption2.r;
    EuropeanOption putOption2 = callOption2;
    putOption2.optType = "P";
    double S2 = 100;
    cout << "Call price : " << callOption2.Price(S2) <<endl;
    cout << "Put price : " << putOption2.Price(S2) <<endl;
    
    //  Batch 3: T = 1.0, K = 10, sig = 0.50, r = 0.12, S = 5 (C = 0.204058, P = 4.07326).
    cout << "batch3: " << endl;
    EuropeanOption callOption3;
    callOption3.optType = "C";
    callOption3.K = 10;
    callOption3.T = 1;
    callOption3.r = 0.12;
    callOption3.sig = 0.5;
    callOption3.b = callOption3.r;
    EuropeanOption putOption3 = callOption3;
    putOption3.optType = "P";
    double S3 = 5;
    cout << "Call price : " << callOption3.Price(S3) <<endl;
    cout << "Put price : " << putOption3.Price(S3) <<endl;
    
    //  Batch 4: T = 30.0, K = 100.0, sig = 0.30, r = 0.08, S = 100.0 (C = 92.17570, P = 1.24750).
    cout << "batch4: " << endl;
    EuropeanOption callOption4;
    callOption4.optType = "C";
    callOption4.K = 100;
    callOption4.T = 30;
    callOption4.r = 0.08;
    callOption4.sig = 0.3;
    callOption4.b = callOption1.r;
    EuropeanOption putOption4 = callOption4;
    putOption4.optType = "P";
    double S4 = 100;
    cout << "Call price : " << callOption4.Price(S4) <<endl;
    cout << "Put price : " << putOption4.Price(S4) <<endl;
    
    cout << "Part A : b) put prices from call-put parity" << endl;
    //  Checking put price from put call parity gives same result
    cout << "Batch1: PutPrice = " << putPriceFromParity( callOption1, S1) << endl;
    cout << "Batch2: PutPrice = " << putPriceFromParity( callOption2, S2) << endl;
    cout << "Batch3: PutPrice = " << putPriceFromParity( callOption3, S3) << endl;
    cout << "Batch4: PutPrice = " << putPriceFromParity( callOption4, S4) << endl;
    
    cout << "Part A : c) call prices with array of stock prices" << endl;
    using namespace optionPrices;
    optType = "C";
    cout << "Price from func: " << priceExact(S1, callOption1.T, callOption1.sig, callOption1.K, callOption1.r) << endl;
    // Choose which model to use
    double (*optionPrices) (double S, double T, double sig, double K, double r);
    optionPrices = priceExact;
    // getting price array
    vector<double> priceArray = priceExact(createMesh(10, 50, 1), callOption1.T, callOption1.sig, callOption1.K, callOption1.r, optionPrices);
    print(priceArray);
    
    cout << "Part A : d) call prices with array of different variable" << endl;
    vector<double> sArr = createMesh(10,50,10);
    vector<double> TArr = createMesh(1,5,1);
    vector<double> sigArr = createMesh(0,0.5,0.1);
    vector<double> KArr = createMesh(10,50,10);
    vector<double> rArr = createMesh(0.08,0.12,0.01);
    // creating mesh
    vector<vector<double>> meshArray = createMeshArray(sArr, TArr, sigArr, KArr, rArr);
    //  getting price array
    vector<double> priceMeshArray = priceExact(meshArray, optionPrices);
    cout << "All result : " << endl;
    print(priceMeshArray);
    
    cout << "A: sensitivity : a : calculate sensitivity" << endl;
    // data set: K = 100, S = 105, T = 0.5, r = 0.1, b = 0 and sig = 0.36. (delta call = 0.5946, delta put = -0.3566).
    EuropeanOption callSensitivityOption;
    callSensitivityOption.K = 100;
    callSensitivityOption.T = 0.5;
    callSensitivityOption.r = 0.1;
    callSensitivityOption.b = 0;
    callSensitivityOption.sig = 0.36;
    EuropeanOption putSensitivityOption = callSensitivityOption;
    putSensitivityOption.toggle();
    cout << "Call Option sensitivities: " << endl;
    cout << "delta: " << callSensitivityOption.Delta(105) << endl;
    cout << "gamma: " << callSensitivityOption.Gamma(105) << endl;
    
    cout << "Put Option sensitivities: " << endl;
    cout << "delta: " << putSensitivityOption.Delta(105) << endl;
    cout << "gamma: " << putSensitivityOption.Gamma(105) << endl;

    cout << "Part A : sensitivity : b) call sensitivities with array of stock prices" << endl;
    // Choose which model to use
    double (*optionSensitivities) (double S, double T, double sig, double K, double r, string Type);
    optionSensitivities = sensitivityExact;
    // getting price array
    try {
        vector<double> deltaArray = sensitivityExact(createMesh(10, 50, 1), callOption1.T, callOption1.sig, callOption1.K, callOption1.r, "delta", optionSensitivities);
        print(deltaArray);
    } catch (OptionException& err) {
        cout << "Error: " << err.GetMessage() << endl;
    }
    
    cout << "Part A : sensitivity : c) call sensitivities with Matric pricer" << endl;
    // getting price array
    try {
        vector<double> deltaMeshArray = sensitivityExact(meshArray, "delta", optionSensitivities);
        print(deltaMeshArray);
    } catch (OptionException& err) {
        cout << "Error: " << err.GetMessage() << endl;
    }
    
    
    cout << "A: sensitivity : a : calculate sensitivity" << endl;
    // data set: K = 100, S = 105, T = 0.5, r = 0.1, b = 0 and sig = 0.36. (delta call = 0.5946, delta put = -0.3566).
    cout << "Call Option sensitivities: " << endl;
    cout << "exactdelta: " << callSensitivityOption.Delta(105) << endl;
    cout << "approxdelta H = 0.5: " << callSensitivityOption.ApproxDelta(105, 0.5) << endl;
    cout << "approxdelta h = 0.1: " << callSensitivityOption.ApproxDelta(105, 0.1) << endl;
    cout << "approxdelta h = 0.01: " << callSensitivityOption.ApproxDelta(105, 0.01) << endl;
    cout << "approxdelta h = 0.001: " << callSensitivityOption.ApproxDelta(105, 0.001) << endl;
    
    cout << "exactgamma: " << callSensitivityOption.Gamma(105) << endl;
    cout << "approxGamma H = 0.5: " << callSensitivityOption.ApproxGamma(105, 0.5) << endl;
    cout << "approxGamma h = 0.1: " << callSensitivityOption.ApproxGamma(105, 0.1) << endl;
    cout << "approxGamma h = 0.01: " << callSensitivityOption.ApproxGamma(105, 0.01) << endl;
    cout << "approxGamma h = 0.001: " << callSensitivityOption.ApproxGamma(105, 0.001) << endl;
    //  Conclusion: as delta becomes smaller approxomated value reached near to exact solution
    
    try {
        //  incresing distance between meshpoints so you can see all the values
        vector<double> deltaApproxArray = sensitivityExact(createMesh(10, 50, 10), callOption1.T, callOption1.sig, callOption1.K, callOption1.r, "ApproxDelta", optionSensitivities);
        cout << "Approx Delta array: " << endl;
        print(deltaApproxArray);
    } catch (OptionException& err) {
        cout << "Error: " << err.GetMessage() << endl;
    }
    
    cout << "\n\n Perpetual American Option Pricing: " << endl;
    cout << "Part B start : " << endl;
    cout << "B : b: Pricing" << endl;
    //  K = 100, sig = 0.1, r = 0.1, b = 0.02, S = 110 (check C = 18.5035, P = 3.03106)
    AmericanOption aCallAmOption;
    aCallAmOption.sig = 0.1;
    aCallAmOption.r = 0.1;
    aCallAmOption.b = 0.02;
    aCallAmOption.K = 100;
    //  Prices checked comes out correct
    cout << "Call price C = " << aCallAmOption.Price(110) << endl;
    AmericanOption aPutAmOption = aCallAmOption;
    aPutAmOption.toggle();
    cout << "put Price P = " << aPutAmOption.Price(110) << endl;
    
    cout << "\nB: c: call price array from stock price array" << endl;
    double (*amOptionPrice) (double S, double sig, double K, double r, double b);
    amOptionPrice = americanPrice;
    // getting price array
    vector<double> amPriceArray = AmericanPrice(createMesh(10, 50, 1), 0.1, 100, 0.1, 0.02, amOptionPrice);
    print(amPriceArray);
    
    cout << "\nB : d) call prices with array of different variable" << endl;
    sArr = createMesh(10,50,10);
    sigArr = createMesh(0.1,0.5,0.1);
    KArr = createMesh(10,50,10);
    rArr = createMesh(0.08,0.12,0.01);
    vector<double> bArr = createMesh(0.02, 0.05, 0.01);
    // creating mesh
    meshArray = createMeshArray(sArr, sigArr, KArr, rArr, bArr);
    //  getting price array
    vector<double> amPriceMeshArray = priceExact(meshArray, amOptionPrice);
    cout << "All result : " << endl;
    print(amPriceMeshArray);
    return 0;
}


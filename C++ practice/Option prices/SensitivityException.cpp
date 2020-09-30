//
//  SensitivityException.cpp
//  Group A-B
//
//  Created by Jeet Oza on 4/16/18.
//  Copyright © 2018 Jeet Oza. All rights reserved.
//

#include "SensitivityException.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//  Default constructor
//  Not calling ArrayException(, since if not provided it calls base constructor by default and that's what we want
SensitivityException::SensitivityException() : Type("") {}

//  Constructor from input values
SensitivityException::SensitivityException( string Type ) : Type(Type){}

string SensitivityException::GetMessage()
{
    ostringstream oss;
    oss << "Sensitivity " << Type << " not defined.";
    string val = oss.str();
    return val;
}

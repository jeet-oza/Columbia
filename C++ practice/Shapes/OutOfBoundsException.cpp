//
//  OutOfBoundsException.cpp
//  Exercise 6 section 4.2b
//
//  source file for out of bound array exception
//
//  Created by Jeet Oza on 2/13/18.
//  Copyright © 2018 Jeet Oza. All rights reserved.
//

#include "OutOfBoundsException.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//  Default constructor
//  Not calling ArrayException(, since if not provided it calls base constructor by default and that's what we want
OutOfBoundsException::OutOfBoundsException() : m_index(-1) {}

//  Constructor from input values
OutOfBoundsException::OutOfBoundsException( int index ) : m_index(index){}

string OutOfBoundsException::GetMessage()
{
    ostringstream oss;
    oss << "Index " << m_index << " is out of range.";
    string val = oss.str();
    return val;
}

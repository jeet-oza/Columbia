//
//  EqualSizeException.cpp
//  Exercise 6 section 4.2b
//
//  exception for if 2 array doesn't have same size for some operator which requires array of same sizes
//
//  Created by Jeet Oza on 2/17/18.
//  Copyright © 2018 Jeet Oza. All rights reserved.
//

#include "EqualSizeException.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//  Default constructor
//  Not calling ArrayException(, since if not provided it calls base constructor by default and that's what we want
EqualSizeException::EqualSizeException() : m_size1(0), m_size2(0) {}

//  Constructor from input values
EqualSizeException::EqualSizeException( int size1, int size2 ) : m_size1(size1), m_size2(size2){}

string EqualSizeException::GetMessage()
{
    ostringstream oss;
    oss << "Arrays are of different sizes " << m_size1 << " and " << m_size2 << ". ";
    oss << "please use same size arrays.";
    string val = oss.str();
    return val;
}

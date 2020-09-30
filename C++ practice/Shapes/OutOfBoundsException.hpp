//
//  OutOfBoundsException.hpp
//  Exercise 6 section 4.2b
//
//  derived class of array exception; this handles index out of range exceptions
//
//  Created by Jeet Oza on 2/13/18.
//  Copyright © 2018 Jeet Oza. All rights reserved.
//

#ifndef OutOfBoundsException_hpp
#define OutOfBoundsException_hpp

#include <string>
#include "ArrayException.hpp"

using namespace std;

class OutOfBoundsException: public ArrayException
{
private:
    int m_index;    //  erroneous index
public:
    //  constructors
    OutOfBoundsException();
    OutOfBoundsException( int index );  //  constructor from input index
    // destructor;
    ~OutOfBoundsException() {};
    //  handling error message for out of bound exception
    string GetMessage();
};

#endif /* OutOfBoundsException_hpp */

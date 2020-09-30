//
//  EqualSizeException.hpp
//  Exercise 6 section 4.2b
//
//  Created by Jeet Oza on 2/17/18.
//  Copyright © 2018 Jeet Oza. All rights reserved.
//

#ifndef EqualSizeException_hpp
#define EqualSizeException_hpp

#include <string>
#include "ArrayException.hpp"

using namespace std;

class EqualSizeException: public ArrayException
{
private:
    int m_size1;    //  size of Array 1
    int m_size2;    //  size of array 2
public:
    //  constructors
    EqualSizeException();
    EqualSizeException( int size1, int size2 );  //  constructor from input sizes
    // destructor;
    ~EqualSizeException() {};
    //  handling error message for out of bound exception
    string GetMessage();
};

#endif /* EqualSizeException_hpp */

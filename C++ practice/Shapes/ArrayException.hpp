//
//  ArrayException.hpp
//  Exercise 6 section 4.2b
//
//  Base Array exception class
//  ArrayException has pure virtual function so its instance cannot be made
//
//  Created by Jeet Oza on 2/13/18.
//  Copyright © 2018 Jeet Oza. All rights reserved.
//

#ifndef ArrayException_hpp
#define ArrayException_hpp

#include <string>
using namespace std;

class ArrayException
{
public:
    //  Default construcotr
    ArrayException() {};
    //  Destructor
    ~ArrayException() {};
    //  pure virtual function; needs to be managed in derived class
    virtual string GetMessage() = 0;
};

#endif /* ArrayException_hpp */

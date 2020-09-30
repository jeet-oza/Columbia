//
//  StackException.hpp
//  Exercise 6 section 4.2b
//
//  Stack specific exceptions base class
//
//  Created by Jeet Oza on 2/18/18.
//  Copyright © 2018 Jeet Oza. All rights reserved.
//

#ifndef StackException_hpp
#define StackException_hpp

#include <string>
using namespace std;

class StackException
{
public:
    //  Default construcotr
    StackException() {};
    //  Destructor
    ~StackException() {};
    //  pure virtual function; needs to be managed in derived class
    virtual string GetMessage() = 0;
};

#endif /* StackException_hpp */

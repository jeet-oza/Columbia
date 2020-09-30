//
//  StackFullException.hpp
//  Exercise 6 section 4.2b
//
//  Stack full exception for push function
//
//  Created by Jeet Oza on 2/18/18.
//  Copyright © 2018 Jeet Oza. All rights reserved.
//

#ifndef StackFullException_hpp
#define StackFullException_hpp

#include <string>
#include "StackException.hpp"
using namespace std;

class StackFullException : public StackException
{
public:
    //  Default construcotr
    StackFullException() {};
    //  Destructor
    ~StackFullException() {};
    //  pure virtual function; needs to be managed in derived class
    virtual string GetMessage() { return "Stack is full cannot add any element to stack. "; };
};

#endif /* StackFullException_hpp */

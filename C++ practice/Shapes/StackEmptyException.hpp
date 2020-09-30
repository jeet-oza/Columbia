//
//  StackEmptyException.hpp
//  Exercise 6 section 4.2b
//
//  Created by Jeet Oza on 2/18/18.
//  Copyright © 2018 Jeet Oza. All rights reserved.
//

#ifndef StackEmptyException_hpp
#define StackEmptyException_hpp

#include <string>
#include "StackException.hpp"
using namespace std;

class StackEmptyException : public StackException
{
public:
    //  Default construcotr
    StackEmptyException() {};
    //  Destructor
    ~StackEmptyException() {};
    //  pure virtual function; needs to be managed in derived class
    virtual string GetMessage() { return "Stack is empty cannot pop any element of stack. "; };
};

#endif /* StackEmptyException_hpp */

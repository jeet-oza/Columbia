//
//  OptionException.hpp
//  Group A-B
//
//  Created by Jeet Oza on 4/16/18.
//  Copyright © 2018 Jeet Oza. All rights reserved.
//

#ifndef OptionException_hpp
#define OptionException_hpp

#include <string>
using namespace std;

class OptionException
{
public:
    //  Default construcotr
    OptionException() {};
    //  Destructor
    ~OptionException() {};
    //  pure virtual function; needs to be managed in derived class
    virtual string GetMessage() = 0;
};

#endif /* OptionException_hpp */

//
//  SensitivityException.hpp
//  Group A-B
//
//  Created by Jeet Oza on 4/16/18.
//  Copyright © 2018 Jeet Oza. All rights reserved.
//

#ifndef SensitivityException_hpp
#define SensitivityException_hpp

#include <string>
#include "OptionException.hpp"

using namespace std;

class SensitivityException: public OptionException
{
private:
    string Type;    //  erroneous index
public:
    //  constructors
    SensitivityException();
    SensitivityException( string Type );  //  constructor from input index
    // destructor;
    ~SensitivityException() {};
    //  handling error message for out of bound exception
    string GetMessage();
};

#endif /* SensitivityException_hpp */

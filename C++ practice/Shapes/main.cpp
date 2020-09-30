//
//  main.cpp
//  Exercise 6 section 4.2b
//
//  Value template
//
//  Created by Jeet Oza on 2/18/18.
//  Copyright © 2018 Jeet Oza. All rights reserved.
//

#include <iostream>
#include "Stack.cpp"
#include "Point.hpp"

using namespace JeetOza::CAD;
using namespace JeetOza::Container;
using namespace std;


class EA {};
class EB: public EA {};

void F()
{
    throw EB();
}

int main()
{
    try
    {
        F();
    }
    catch(EA&)
    {
        std::cout<<"EA Exception"<<std::endl;
    }
    catch(EB&)
    {
        std::cout<<"EB Exception"<<std::endl;
    }
    
    std::cout<<"Finished"<<std::endl;
    
    return 0;
}

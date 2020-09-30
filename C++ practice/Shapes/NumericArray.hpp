//
//  NumericArray.hpp
//  Exercise 6 section 4.2b
//
//  NumericArray header file, operator overloading and constructors, destructors
//
//  Created by Jeet Oza on 2/17/18.
//  Copyright © 2018 Jeet Oza. All rights reserved.
//

#ifndef NumericArray_hpp
#define NumericArray_hpp

#include <string>
#include <iostream>
#include "Array.cpp"
using namespace std;
//using namespace JeetOza::CAD; this can be done instead of applying full namespace

namespace JeetOza
{
    namespace Container
    {
        template< typename T >
        class NumericArray : public Array<T>{
        public:
            //  constructors
            NumericArray();    //  default constructor
            NumericArray( int aSize );  //  constructor based on size of an array
            NumericArray( const NumericArray<T>& anArray);        //  Copy constructor from other Array of points
            
            ~NumericArray();   //  destructor of object
            
            //  operator functions
            NumericArray<T>& operator = (const NumericArray<T>& source); // Assignment operator.
            NumericArray<T> operator * (double factor) const;   //  Multiply each element Array with double
            NumericArray<T> operator + (const NumericArray<T> &aArray) const; //  Add 2 arrays
            T DotProduct ( const NumericArray<T> &aArray) const;
        };
    };
};
#endif /* NumericArray_hpp */

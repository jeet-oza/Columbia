//
//  PointArray.hpp
//  Exercise 6 section 4.2b
//
//  Header file for point arrray class
//
//  Created by Jeet Oza on 2/17/18.
//  Copyright © 2018 Jeet Oza. All rights reserved.
//

#ifndef PointArray_hpp
#define PointArray_hpp

#include <string>
#include <iostream>
#include "Array.cpp"
#include "Point.hpp"
using namespace std;
using namespace JeetOza::CAD;

namespace JeetOza
{
    namespace Container
    {
        class PointArray : public Array<Point>{
        public:
            //  constructors
            PointArray();    //  default constructor
            PointArray( int aSize );  //  constructor based on size of an array
            PointArray( const PointArray& anArray);        //  Copy constructor from other Array of points
            
            ~PointArray();   //  destructor of object
            
            //  operator functions
            PointArray& operator = (const PointArray& source); // Assignment operator.
            
            //  Specific PointArray Function
            double Length() const;  //  total length of pointArray
        };
    };
};

#endif /* PointArray_hpp */

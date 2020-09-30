//
//  Shape.cpp
//  Exercise 6 section 4.2b
//
//  Source file for Shape class
//
//  Created by Jeet Oza on 2/13/18.
//  Copyright © 2018 Jeet Oza. All rights reserved.
//

#include "Shape.hpp"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

namespace JeetOza
{
    namespace CAD
    {
        Shape::Shape() : id( rand() )
        {
//            cout << "default shape constructor" << endl;
        }
        
        Shape::Shape( const Shape& aShape ) : id(aShape.id)
        {
//            cout << "Copy shape constructor" << endl;
        }
        
        Shape::~Shape()
        {
//            cout << "Destroying Shape ... " << endl;
        }
        
        int Shape::ID() const
        {
            return id;
        }
        
        //  String representation fo shape
        string Shape::ToString() const
        {
            ostringstream oss;
            oss << "Id :  " << id ;
            string val = oss.str();
            return val;
        }
        
        //  Assignment operator
        Shape& Shape::operator = (const Shape& source){
//            cout << "assignment operator" << endl;
            if( this != &source)
            {
                id = source.id;
            };
            return *this;
        }
        
        //  Print function common for all shapes, calls ToString polymorphic function
        void Shape::Print() const
         {
             cout << ToString() << endl;
         }
        
        //  overloading << operation
        ostream& operator << (ostream& os, const Shape& source){
            os << source.ToString();
            return os;
        }
    }
}

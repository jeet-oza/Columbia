//
//  PointArray.cpp
//  Exercise 6 section 4.2b
//
//  Source file for implementation of PointArray function
//
//  Created by Jeet Oza on 2/17/18.
//  Copyright © 2018 Jeet Oza. All rights reserved.
//

#include "PointArray.hpp"
#include "Array.cpp"
#include "Point.hpp"

using namespace JeetOza::CAD;
using namespace std;

namespace JeetOza
{
    namespace Container
    {
        
        //  Default Array constructor, makes dynamic array of 10 points
        PointArray::PointArray() : Array<Point>()
        {
            //    cout << "Default Array constructor, makes dynamic array of 10 points" << endl;
        }
        
        //  Make dynamic Point array of input size
        PointArray::PointArray( int aSize ) : Array<Point>(aSize)
        {
            //    cout<< "Make dynamic Point array of input size" << endl;
        }
        
        //  Copy Constructor
        PointArray::PointArray( const PointArray& anArray ) : Array<Point>(anArray)
        {
        }
        
        //  destructor
        PointArray::~PointArray()
        {
        }
        
        //  operator functions
        //  assignment operator
        PointArray& PointArray::operator = (const PointArray& source){
            //  not checking self assignment since it is checked in base class function
            Array<Point>::operator=(source);
            return *this;
        }
        
        //  Total Length of PointArray
        //  Length = Distance( Pt1, Pt2) + Distance( Pt2, pt3) +...+ Distance(Pt[n-1], Pt[n])
        double PointArray::Length() const
        {
            int size = Size();
            double length = 0.0;
            for (int i = 1; i < size; i++) {
                length += GetElement(i).Distance(GetElement(i-1));
            }
            return length;
        }
    }
}

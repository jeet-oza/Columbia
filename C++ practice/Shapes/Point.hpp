//
//  Point.hpp
//  Exercise 6 section 4.2b
//
//  Point class header file
//  Point has x and y cordinate. currently working in 2-D plane
//  default constructor sets point to origin
//  getter and setter function set for x,y coordinate
//  converting point to string to print output as well
//  distance of point from origin as well as from give point also
//  distance function input point pass by reference
//  const functions
//
//  learn OSstream operator <<
//  implementing under  Jeetoza::CAD namespace
//
//  Created by Jeet Oza on 1/8/18.

#ifndef point_hpp
#define point_hpp

#include <string>
#include <iostream>
#include "Shape.hpp"
using namespace std;

namespace JeetOza
{
    namespace CAD
    {
        class Point : public Shape
        {
        //  Data
        private:
            double x;   //  x coordinate of a point
            double y;   //  y coordinate of a point
        public:
            //  constructors
            Point();    //  default constructor
            Point( double xVal, double yVal );  //  constructor based on x and y input coordinate
            Point( const Point& aPoint);        //  Copy constructor from other point
            
            virtual ~Point();   //  destructor of object
            
            //  Accessing function
            double X() const;        //  get x coordinate
            void X( double newX );   //  set new x coordinate
            double Y() const;        //  get y coordinate
            void Y( double newY );   //  set new y coordinate
            virtual string ToString() const;   //  convert point into string
            double Distance() const;  //  distance of point from origin
            double Distance( const Point& aPoint ) const;   //  distance of a point from given point
            virtual void Draw() const;  //  currently to simulate just prints something
            
            //  member operator overloading
            Point operator - () const; // Negate the coordinates.
            Point operator * (double factor) const; // Scale the coordinates.
            Point operator + (const Point& p) const; // Add coordinates.
            bool operator == (const Point& p) const; // Equally compare operator.
            Point& operator = (const Point& source); // Assignment operator.
            Point& operator *= (double factor); // Scale the coordinates & assign.
            
            friend ostream& operator << (ostream& os, const Point& p); // Send to ostream.
        };
    };
};

#endif /* point_hpp */






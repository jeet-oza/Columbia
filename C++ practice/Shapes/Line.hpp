//
//  Point.hpp
//  Exercise 6 section 4.2b
//
//  Line class header file
//  Line has start point and end point
//  default constructor sets both points at origin
//  getter and setter function for start and end point
//  converting line to string to print output as well
//  distance of start point to end point
//  appropriate const functions
//
//  learn OSstream operator <<
//  implementing under  Jeetoza::CAD namespace
//
//  Created by Jeet Oza on 1/8/18.

#ifndef line_hpp
#define line_hpp

#include <string>
#include "Point.hpp"
#include "Shape.hpp"
using namespace std;

namespace JeetOza
{
    namespace CAD
    {
        class Line : public Shape
        {
            //  Data
        private:
            Point startPoint;   //  start point of a line
            Point endPoint;     //  endPoint of a line
        public:
            //  constructors
            Line();    //  default constructor
            Line( const Point& aStartPoint, const Point& aEndPoint );  //  constructor based on start and end point input
            Line( const Line& aLine);   //  Copy constructor from other line
            
            virtual ~Line();   //  destructor of object
            
            //  Accessing function
            Point StartPoint() const;        //  get start point
            void StartPoint( const Point& aStartPoint);   //  set new startpoint
            Point EndPoint() const;        //  get End point
            void EndPoint( const Point& aEndPoint );   //  set new end point
            virtual string ToString() const;   //  convert line into string
            double Distance() const;  //  distance between 2 points of line
            virtual void Draw() const;  //  currently to simulate just prints something

            //  member operator overloading
            Line& operator = (const Line& source); // Assignment operator.
            
            friend ostream& operator << (ostream& os, const Line& p); // Send to ostream.
        };
    };
}

#endif /* line_hpp */






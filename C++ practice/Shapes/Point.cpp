//
//  Point.cpp
//  Exercise 6 section 4.2b
//
//  Point class source file
//  Point has x and y cordinate. currently working in 2-D plane
//  defining class functions of point
//  implementing under  Jeetoza::CAD namespace
//
//  Created by Jeet Oza on 1/8/18.

#include "Point.hpp"
#include "Shape.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

namespace JeetOza
{
    namespace CAD
    {
        //  set default constructor to (0,0)
        Point::Point() : Shape(), x(0), y(0)
        {
//            cout << "Making point from default constructor" << endl;
        }

        //  constructor set to initialized values of constructor
        Point::Point( double xVal, double yVal ) : Shape(), x(xVal), y(yVal)
        {
//            cout << "Making point from initialized value constructor" << endl;
        }

        //  Constructor to copy existing point
        Point::Point( const Point& aPoint ) : Shape(aPoint),x(aPoint.x), y(aPoint.y)
        {
//            cout << "Making point from copy constructor" << endl;
        }

        //  Destructor
        Point::~Point()
        {
//            cout << "destructing point..." << endl;
        }

        //  Get X coordinate value, const since it doesn't change data of object point
        double Point::X() const
        {
            return x;
        }

        //  set new value of x coordinate
        void Point::X(double newX)
        {
            x = newX;
        }

        //  Get y coordinate value, const since it doesn't change data of object point
        double Point::Y() const
        {
            return y;
        }

        //  set new value of y coordinate
        void Point::Y(double newY)
        {
            y = newY;
        }


        //  convert point to string
        string Point::ToString() const
        {
            ostringstream oss;
            string idString = Shape::ToString();    //  show ID also
            oss << idString << " : point( " << x << ", " << y << " )";
            string val = oss.str();
            return val;
        }

        //  distance of a point from origin
        //  Distance for origin = Sqrt( x^2 + y^2 )
        double Point::Distance() const
        {
            return sqrt( pow( x, 2 ) + pow( y, 2 ) );
        }

        //  distance of a point from given point
        //  Class point = P1(x1,y1); argument point = p2(x2,y2)
        //  xDist = x1 - x2; yDist = y1 - y2
        //  Distance between class and argument point = sqrt( xDist^2 + yDist^2 )
        double Point::Distance( const Point& aPoint ) const
        {
            double xDist = x - aPoint.x;    //  x coordinate distance between 2 point
            double yDist = y - aPoint.y;    //  y coordinate distance between 2 point
            return sqrt( pow( xDist, 2 ) + pow( yDist, 2 ) );
        }
        
        //  Printing some text for simulation of pure virtual function
        void Point::Draw() const
        {
            cout << "Drawing Point..." << endl;
        }

        //  return points with negative co0rdinates of input point
        //  - Point( x, y) = Point( -x, -y )
        Point Point::operator - () const
        {
        //    cout << "points with negative coordinates of input point" << endl;
            return Point( -x, -y );
        }

        //  Scaling a point
        //  a * Point( x, y ) = Point( a*x, a*y )
        Point Point::operator * (double factor) const
        {
        //    cout << "scaling Point" << endl;
            return Point( factor * x, factor * y );
        }

        //  Addition between 2 points
        //  Point( x1, y1 ) + Point( x2 + y2 ) = Point( x1 + x2, y1 + y2 )
        Point Point::operator + (const Point &p) const
        {
        //    cout << "adding 2 points" << endl;
            return Point( x + p.x, y + p.y );
        }

        //  Checking if 2 points are same
        //  Point( x1, y1 ) == Point( x2, y2 ) if( x1 == x2 and y1 == y2 ) true : false
        bool Point::operator == (const Point &p) const
        {
            return x == p.x && y == p.y;
        }

        //  Assignment operator
        Point& Point::operator = (const Point& source){
//            cout << "assignment operator" << endl;
            if( this != &source)
            {
                Shape::operator = (source);
                x = source.x;
                y = source.y;
            };
            return *this;
        }

        //  Change existing point with scaled point
        Point& Point::operator*=(double factor){
        //    cout << "scaling existing coordinates" << endl;
            x *= factor;
            y *= factor;
            return *this;
        }

        ostream& operator << (ostream& os, const Point& p){
            os << p.ToString();
            return os;
        }
 
    }
}

//
//  Point.cpp
//  Exercise 6 section 4.2b
//
//  line class source file
//  Line from start point to end point
//  defining class functions of line
//  implementing under  Jeetoza::CAD namespace
//
//  Created by Jeet Oza on 1/8/18.

#include "Point.hpp"
#include "Line.hpp"
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

        //  set default constructor to (0,0)end and start point;
        //  default point is set to (0,0) so no need to write
        Line::Line() : Shape(), startPoint(0,0), endPoint(0,0)
        {
//            cout << "Making line from default constructor" << endl;
        }

        //  constructor set to initialized values of constructor
        Line::Line(  const Point& aStartPoint, const Point& aEndPoint ) :
            Shape(), startPoint(aStartPoint), endPoint(aEndPoint)
        {
//            cout << "Making line from initialized value constructor" << endl;
        }

        //  Constructor to copy existing line
        Line::Line( const Line& aLine ) : Shape(aLine), startPoint(aLine.startPoint), endPoint(aLine.endPoint)
        {
//            cout << "Making line from copy constructor" << endl;
        }

        //  Destructor
        Line::~Line()
        {
//            cout << "destructing line..." << endl;
        }

        //  Get start point, const since it doesn't change data of object point
        Point Line::StartPoint() const
        {
            return startPoint;
        }

        //  set new value of start point
        void Line::StartPoint(const Point& aStartPoint)
        {
            startPoint = aStartPoint;
        }

        //  Get end point, const since it doesn't change data of object point
        Point Line::EndPoint() const
        {
            return endPoint;
        }

        //  set new value of end point
        void Line::EndPoint(const Point& aEndPoint)
        {
            endPoint = aEndPoint;
        }

        //  convert point to string
        string Line::ToString() const
        {
            ostringstream oss;
            string idString = Shape::ToString();    //  show ID also in string; adds ID of point as well
            oss << idString << " : line from " << startPoint.ToString() << " to " << endPoint.ToString();
            string val = oss.str();
            return val;
        }

        //  distance of a point from origin
        //  Distance for origin = Sqrt( x^2 + y^2 )
        double Line::Distance() const
        {
            return startPoint.Distance(endPoint);
        }
        
        //  Printing some text for simulation of pure virtual function
        void Line::Draw() const
        {
            cout << "Drawing Line..." << endl;
        }

        //  Assignment operator
        Line& Line::operator = (const Line& source){
//            cout << "assignment operator" << endl;
            if( this != &source)
            {
                Shape::operator=(source);
                startPoint = source.startPoint;
                endPoint = source.endPoint;
            };
            return *this;
        }

        ostream& operator << (ostream& os, const Line& aLine){
            os << aLine.ToString();
            return os;
        }
    }
}




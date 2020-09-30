//
//  Circle.cpp
//  Exercise 6 section 4.2b
//
//  circle class source file
//  circle defined with center and a radius
//  here all the functiona are defined
//  implementing under  Jeetoza::CAD namespace
//
//  Created by Jeet Oza on 1/12/18.
//
#define _USE_MATH_DEFINES

#include "Circle.hpp"
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

        //  default constructor
        Circle::Circle() : Shape(), radius(10), center(0,0)
        {
//            cout << "default circle constructor... " << endl;
        }

        //  constructor from input argument
        Circle::Circle( const Point& aCenter, const double aRadius) : Shape(), center(aCenter), radius(aRadius)
        {
//            cout << "circle constructor from input values.. " << endl;
        }

        //  Copy constructor
        Circle::Circle( const Circle& aCircle ) : Shape(aCircle), center(aCircle.center), radius(aCircle.radius)
        {
//            cout << "Circle copy constructor..." << endl;
        }

        //  destructor
        Circle::~Circle()
        {
//            cout << "Destroying circle.. " << endl;
        }

        //  getting radius function
        double Circle::Radius() const
        {
            return radius;
        }

        //  setting radius
        void Circle::Radius(double aRadius)
        {
            radius = aRadius;
        }

        //  getting center
        Point Circle::Center() const
        {
            return center;
        }

        //  setting center
        void Circle::Center(const Point &aCenter)
        {
            center = aCenter;
        }

        //  get diameter
        double Circle::Diameter() const
        {
            return 2 * radius;
        }

        //  get circumference
        double Circle::Circumference() const
        {
            return 2 * M_PI * radius;
        }

        //  get area
        double Circle::Area() const
        {
            return M_PI * radius * radius;
        }

        //  convert circle to string
        string Circle::ToString() const
        {
            ostringstream oss;
            string idString = Shape::ToString(); //  show ID also in string; adds ID of point as well
            oss << idString << " : circle with center " << center.ToString() << " and radius " << radius;
            string val = oss.str();
            return val;
        }
        
        //  Printing some text for simulation of pure virtual function
        void Circle::Draw() const
        {
            cout << "Drawing Circle..." << endl;
        }

        //  Assignment operator
        Circle& Circle::operator = (const Circle& source){
//            cout << "assignment operator" << endl;
            if( this != &source)
            {
                Shape::operator=(source);
                center = source.center;
                radius = source.radius;
            };
            return *this;
        }

        ostream& operator << (ostream& os, const Circle& aCircle){
            os << aCircle.ToString();
            return os;
        }
    }
}

//
//  Circle.hpp
//  Exercise 6 section 4.2b
//
//  circle class header file
//  circle defined with center and a radius
//  constructors and destructor of circle
//  getter and setter overloading function of center and radius
//  function to get diameter, circumference and area
//  represent in string format
//
//  learn OSstream operator <<
//  implementing under  Jeetoza::CAD namespace
//
//  Created by Jeet Oza on 1/12/18.

#ifndef circle_hpp
#define circle_hpp

#include <string>
#include "Point.hpp"
#include "Shape.hpp"
using namespace std;

namespace JeetOza
{
    namespace CAD
    {
        class Circle : public Shape
        {
        private:
            Point center;   //  center point of a circle; default would be (0,0)
            double radius;  //  radius of a circle; assuming it will be non-negative
        public:
            //  constructors
            Circle();       //  default constructor, center(0,0) and radius 0
            Circle( const Point& aCenter, const double aRadius );    //  Constructor from predefined values
            Circle( const Circle& aCircle); //  copy constructor
            
            virtual ~Circle();  //  destructor
            
            //  Accessing functions
            double Radius() const;  //  returns radius of circle; doesn't change object
            void Radius( double aRadius );  //  setting radius
            Point Center() const;   //  getting ceter of a circle
            void Center( const Point& aCenter );    //  SETTING CENTER OF A CIRCLE
            
            double Diameter() const;    //  get diameter of a circle
            double Circumference() const;   //  get circumference
            double Area() const;        //  get area
            virtual string ToString() const;   //  convert point into string
            virtual void Draw() const;  //  currently to simulate just prints something

            //  member operator overloading
            Circle& operator = (const Circle& source); // Assignment operator.
            
            friend ostream& operator << (ostream& os, const Circle& p); // Send to ostream.
        };
    };
};

#endif /* circle_hpp */

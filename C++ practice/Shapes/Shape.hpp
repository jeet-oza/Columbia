//
//  Shape.hpp
//  Exercise 6 section 4.2b
//
//  Base shape class for other shapes
//
//  ID member and some common functionality to get ID and assignment operator
//  learning use of virtual functions
//  Template method pattern; print function common function for all shapes
//  delegated part of function that is different to ToString polymorphic function
//
//  Created by Jeet Oza on 2/13/18.
//  Copyright © 2018 Jeet Oza. All rights reserved.
//

#ifndef Shape_hpp
#define Shape_hpp

#include <string>
#include <iostream>
using namespace std;

namespace JeetOza
{
    namespace CAD
    {
        class Shape{
        //  Data
        private:
            int id;
        public:
            //  constructors
            Shape();    //  default constructor
            Shape( const Shape& aShape );   //  copy constructor
            
            //  made it virtual so if Shape sp = Point destoyed, it calls correct destructor
            virtual ~Shape();   //  destructor
            //  Accessing function
            int ID() const; // get ID of shape
            
            //  making ToString Virtual so Shape* can point to right version
            virtual string ToString() const;  //  string representation
            //  cannot draw shape without mentioning which shape we need to draw
            //  so making it pure virtual function; this is implemented in derived class
            //  because of this we cannot create instance of Shape class, just we can make pointer of this class
            //  which can point to instance of derived class
            virtual void Draw() const=0;    //  draw function specific to each shape
            void Print() const;
            
            //  member operator overloading
            Shape& operator = (const Shape& source); // Assignment operator.
            
            friend ostream& operator << (ostream& os, const Shape& source); // Send to ostream.
        };
    };
};

#endif /* Shape_hpp */

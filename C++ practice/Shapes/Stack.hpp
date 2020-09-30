//
//  Stack.hpp
//  Exercise 6 section 4.2b
//
//  Stack class; composition
//  Header file
//
//  Created by Jeet Oza on 2/17/18.
//  Copyright © 2018 Jeet Oza. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <string>
#include <iostream>
#include "Array.cpp"
using namespace std;
//using namespace JeetOza::CAD; this can be done instead of applying full namespace

namespace JeetOza
{
    namespace Container
    {
        template< typename T, int size >
        class Stack{
            //  Data
        private:
            int m_current;      //  current index in an array
            Array<T> m_Array;   //  Array member variable
        public:
            //  constructors
            Stack();    //  default constructor
            Stack( Stack<T, size>& aStack );  //  Copy Constructor
            
            //Destructor
            ~Stack();
            
            //  Specific functions to Stack
            Array<T> GetArray() const; //   Get array
            void Push(const T& var );    //  adding new element atcurrent position
            T Pop();        //  popping element from current-1 position
            
            //  Assignment operator
            Stack<T, size>& operator = (const Stack<T, size>& source); // Assignment operator.

            template < typename U, int aSize >
            friend ostream& operator << (ostream& os, const Stack<U,aSize>& p); // Send to ostream.
        };
    };
};

#endif /* Stack_hpp */

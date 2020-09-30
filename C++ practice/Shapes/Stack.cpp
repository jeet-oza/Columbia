//
//  Stack.cpp
//  Exercise 6 section 4.2b
//
//  Stack class source file
//
//  Created by Jeet Oza on 2/17/18.
//  Copyright © 2018 Jeet Oza. All rights reserved.
//

#ifndef Stack_cpp
#define Stack_cpp

#include "Stack.hpp"
#include "Array.hpp"
#include "ArrayException.hpp"
#include "StackEmptyException.hpp"
#include "StackFullException.hpp"
#include <iostream>

using namespace std;

namespace JeetOza
{
    namespace Container
    {
        //  Default Constructor
        template< typename T, int Size >
        Stack<T,Size>::Stack() : m_current(0), m_Array(Size) {};
        
        //  Copy Constructor
        template< typename T, int Size >
        Stack<T,Size>::Stack( Stack<T,Size>& aStack ) : m_current(aStack.m_current), m_Array(aStack.m_Array) {};
        
        //  Destructor
        template< typename T, int Size >
        Stack<T,Size>::~Stack()
        {
        };
        
        //  Get array of stack
        template< typename T, int Size >
        Array<T> Stack<T,Size>::GetArray() const
        {
            return m_Array;
        }
        
        //  Stack Specific Function
        //  add element to current position and increment currentLocation
        //  Throw exception when current location is out of bound and don't increment location
        template< typename T, int Size >
        void Stack<T,Size>::Push( const T& var)
        {
            try {
                m_Array.SetElement(m_current, var);
                //  Only increments if setelement succeeds, so if out of bound we don't increment currentLocation
                m_current += 1;
            } catch (ArrayException& ex) {
                throw StackFullException();
            }
            
        }
        
        //  getting current - 1 location element and decreasing current location count
        //  kind of freeing space, now can be written by pushing element at cuurent decremented location
        template< typename T, int Size >
        T Stack<T,Size>::Pop()
        {
            try
            {
                T elem = m_Array.GetElement(m_current - 1);
                //  only decrement if we can get current-1 element
                m_current -= 1;
                return elem;
            } catch (ArrayException& ex) {
                throw StackEmptyException();
            }
        }
        
        //  assignment operator
        template< typename T, int Size >
        Stack<T,Size>& Stack<T,Size>::operator = (const Stack<T,Size>& source){
            //  checking for self assignment
            if( this != &source)
            {
                m_Array = source.m_Array;
                m_current = source.m_current;
            }
            return *this;
        }
        
        template< typename T, int Size >
        ostream& operator << (ostream& os, const Stack<T,Size>& source){
            os << source.m_Array << endl;
            os << "Current Position : " << source.m_current << endl;
            return os;
        }
    }
}

#endif /* Stack_cpp */

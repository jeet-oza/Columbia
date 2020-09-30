//
//  NumericArray.cpp
//  Exercise 6 section 4.2b
//
//  NumericArray Implementation
//
//  Created by Jeet Oza on 2/17/18.
//  Copyright © 2018 Jeet Oza. All rights reserved.
//

#ifndef NumericArray_cpp
#define NumericArray_cpp

#include "NumericArray.hpp"
#include "Array.hpp"
#include "EqualSizeException.hpp"
#include <iostream>

using namespace std;

namespace JeetOza
{
    namespace Container
    {
        
        //  Default Array constructor, makes dynamic array of 10 points
        template < typename T >
        NumericArray<T>::NumericArray() : Array<T>()
        {
            //    cout << "Default Array constructor, makes dynamic array of 10 points" << endl;
        }

        //  Make dynamic Point array of input size
        template < typename T >
        NumericArray<T>::NumericArray( int aSize ) : Array<T>(aSize)
        {
            //    cout<< "Make dynamic Point array of input size" << endl;
        }

        //  Copy Constructor
        template < typename T >
        NumericArray<T>::NumericArray( const NumericArray<T>& anArray ) : Array<T>(anArray)
        {
        }

        //  destructor
        template < typename T >
        NumericArray<T>::~NumericArray()
        {
        }
        
        //  operator functions
        //  assignment operator
        template < typename T >
        NumericArray<T>& NumericArray<T>::operator = (const NumericArray<T>& source){
            //  not checking self assignment since it is checked in base class function
            Array<T>::operator=(source);
            return *this;
        }
        
        //  multiply each element with double value
        template < typename T >
        NumericArray<T> NumericArray<T>::operator*(double factor) const
        {
            int size = Array<T>::Size();
            NumericArray<T> result(size);
            for (int i = 0; i < size; i++) {
                result[i] = Array<T>::GetElement(i) * factor;
            }
            return result;
        }
        
        //  Add 2 arrays of equal size
        template < typename T >
        NumericArray<T> NumericArray<T>::operator+(const NumericArray<T> &aArray) const
        {
            int size = Array<T>::Size();
            int size2 = aArray.Size();
            if (size == size2) {
                NumericArray<T> result(size);
                for (int i = 0; i < size; i++) {
                    result[i] = Array<T>::GetElement(i) + aArray[i];
                }
                return result;
            } else {
                throw EqualSizeException(size, size2);
            }
        }
        
        //  Dot product of 2 arrays
        template < typename T >
        T NumericArray<T>::DotProduct(const NumericArray<T> &aArray) const
        {
            int size = Array<T>::Size();
            int size2 = aArray.Size();
            if (size == size2) {
                T result = Array<T>::GetElement(0) * aArray[0];
                for (int i = 1; i < size; i++) {
                    result = result + ( Array<T>::GetElement(i) * aArray[i] );
                }
                return result;
            } else {
                throw EqualSizeException(size, size2);
            }
        }
    }
}

#endif /* NumericArray_cpp */

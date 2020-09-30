//
//  Array.cpp
//  Exercise 6 section 4.2b

//  Array Class source file
//  defining array class functions
//  Using CAD::Point namespace for Point, we can use using name space JeetOza::CAD so we don;t have to repeat
//
//  making Array class template class, so we can generalize and don't have make array class for each dataTypes
//  static member variable and function
//
//  Created by Jeet Oza on 2/10/18.
//  Copyright © 2018 Jeet Oza. All rights reserved.
//

#ifndef Array_cpp
#define Array_cpp

#include "Array.hpp"
#include "Point.hpp"
#include "OutOfBoundsException.hpp"
#include <iostream>

using namespace std;

namespace JeetOza
{
    namespace Container
    {
        //  set static variable
        template < typename T >
        int Array<T>::defaultSize = 3;
        
        //  Default Array constructor, makes dynamic array of 10 points
        template < typename T >
        Array<T>::Array() : size(defaultSize),m_data( new T[defaultSize] )
        {
        //    cout << "Default Array constructor, makes dynamic array of 10 points" << endl;
        }

        //  Make dynamic Point array of input size
        template < typename T >
        Array<T>::Array( int aSize ) : size(aSize), m_data( new T[ aSize ] )
        {
        //    cout<< "Make dynamic Point array of input size" << endl;
        }

        //  Copy Constructor
        template < typename T >
        Array<T>::Array( const Array<T>& anArray )
        {
            size = anArray.Size();
            m_data = new T[ size ];
            for (int i = 0; i < size; i++ ) {
                m_data[ i ] = anArray[i];
            }
        }

        //  destructor
        template < typename T >
        Array<T>::~Array()
        {
//            cout << "deleting array object" << endl;
            delete [] m_data;
        }

        //  size of an array
        template < typename T >
        int Array<T>::Size() const
        {
            return size;
        }

        //  sets an element at given index of dynamic array
        //  if index is out of bound don't set the point
        template < typename T >
        void Array<T>::SetElement(int index, const T &aValue)
        {
            if (index < size && index >= 0) {
                m_data[ index ] = aValue;
            } else {
                throw OutOfBoundsException( index );
            };
        }

        //  get element of array at given index
        //  if index out of bound return first element
        template < typename T >
        T& Array<T>::GetElement(int index) const
        {
            if (index < size && index >= 0 ) {
                return m_data[ index ];
            } else {
                throw OutOfBoundsException( index );
            }
        }
        
        //  functions for Setting and getting static variable
        //  getting static variable
        template < typename T >
        int Array<T>::DefaultSize()
        {
            return defaultSize;
        }
        
        //  setting static variable default size
        template < typename T >
        void Array<T>::DefaultSize(int aDefaultSize)
        {
            defaultSize = aDefaultSize;
        }

        //  assignment operator
        template < typename T >
        Array<T>& Array<T>::operator = (const Array<T>& source){
            //  checking for self assignment
            if( this != &source)
            {
                size = source.Size();
                delete [] m_data;
                m_data = new T[ size ];
                for (int i = 0; i < size; i++ ) {
                    m_data[ i ] = source[i];
                }
            }
            return *this;
        }

        //  overriding [] operator for array
        template < typename T >
        T& Array<T>::operator [] ( int index )
        {
//            cout << "Calling non-const [] operator" << endl;
            return GetElement(index);
        }

        template < typename T >
        const T& Array<T>::operator [] ( int index ) const
        {
//            cout << "Calling const  [] operator" << endl;
            return GetElement(index);
        }

        template < typename T >
        ostream& operator << (ostream& os, const Array<T>& source){
            cout << "Size of Array : " << source.Size() << endl;
            for (int i = 0; i < source.Size(); i++ ) {
                os << source[i] << endl;
            }
            return os;
        }
    }
}

#endif /* Array_cpp */


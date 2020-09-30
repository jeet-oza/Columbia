//
//  Array.hpp
//  Exercise 6 section 4.2b
//
//  Array class which make dynamic array of points
//  multiple constructors
//  getter and setter functions based in index
//  assignment operator made; takes care of self assighnment as well
//  namespace container and use of namespace CAD for point
//
//  making Array class template class, so we can generalize and don't have make array class for each dataTypes
//  static member variable and function
//
//  Created by Jeet Oza on 2/10/18.
//  Copyright © 2018 Jeet Oza. All rights reserved.
//

#ifndef Array_hpp
#define Array_hpp

#include <string>
#include <iostream>
using namespace std;
//using namespace JeetOza::CAD; this can be done instead of applying full namespace

namespace JeetOza
{
    namespace Container
    {
        template< typename T >
        class Array{
            //  Data
        private:
            int size;           //  size of an array
            static int defaultSize; //  static variable default size
            T* m_data;      //  dynamic array of point
        public:
            //  constructors
            Array();    //  default constructor
            Array( int aSize );  //  constructor based on size of an array
            Array( const Array<T>& anArray);        //  Copy constructor from other Array of points
            
            ~Array();   //  destructor of object
            
            //  Accessing function
            int Size() const;        //  size of an array
            void SetElement( int index, const T& aValue );   //  set aPoint at particular location
            T& GetElement( int index ) const; //  get element at give position of an array
            
            //  accessing static variables
            static int DefaultSize();
            static void DefaultSize( int aDefaultSize );
            
            //  member operator overloading
            Array<T>& operator = (const Array<T>& source); // Assignment operator.
            T& operator [] ( int index );   //  overloading [] operator
            const T& operator [] ( int index ) const;   //  just in case we want read only ability and not change anything
            
            //  
            template < typename U >
            friend ostream& operator << (ostream& os, const Array<U>& p); // Send to ostream.
        };
    };
};

//  below code will work, if want to include header file; since because of below code source file is included only once

//#ifndef Array_cpp // Must be the same name as in source file #define
//#include "Array.cpp"
//#endif

#endif /* Array_hpp */

#ifndef ARRAYT_H
#define ARRAYT_H
#include <iostream>
#include <iomanip>
#include <cstdlib>
// Portions gratuitously copied from Array.h, Array.cpp

template <typename T>
class ArrayT
{
public:
	ArrayT(void);
	Array(int, T initValue=0);
	Array(const Array &)
	~ArrayT(void);
	int getSize() const;
	const Array& operator=(const Array&);
	bool operator==(const Array & ) const;
	bool operator!=(const Array& ) const;
	T& operator[](int);
	T operator[](int) const;
	void print() const;
	void input();
private:
	int size;
	T  *ptr;
	
};
template<typename T>
Array<T>::Array():ptr(NULL),size(0)
{
}
template <typename T>
Array<T>:Array(int arraySize, T initValue)
{
 // validate arraySize //copied from Array.cpp
   if ( arraySize > 0 )
	  size = arraySize;
   else 
	  throw invalid_argument( "Array size must be greater than 0" );

   ptr = new T[ size ]; // create space for pointer-based array, type T

   for ( int i = 0; i < size; ++i )
	  ptr[ i ] = initValue; // set pointer-based array element
}
// copy constructor for class Array;
// must receive a reference to prevent infinite recursion
template <typename T>
Array<T>::Array( const Array<T> &arrayToCopy ) 
   : size( arrayToCopy.size )
{
   ptr = new T[ size ]; // create space for pointer-based array, type T

   for ( int i = 0; i < size; ++i )
	  ptr[ i ] = arrayToCopy.ptr[ i ]; // copy into object
} // end Array copy constructor
template <typename T>
Array<T>::~Array()
{
   delete [] ptr; // release pointer-based array space
} // end destructor
// return number of elements of Array
template <typename T>
int Array<T>::getSize() const
{
   return size; // number of elements in Array
} // end function getSize

// overloaded assignment operator;
// const return avoids: ( a1 = a2 ) = a3
template <typename T>
const Array<T> &Array::operator=( const Array<T> &right )
{
   if ( &right != this ) // avoid self-assignment
   {
	  // for Arrays of different sizes, deallocate original
	  // left-side array, then allocate new left-side array
	  if ( size != right.size )
	  {
		 delete [] ptr; // release space
		 size = right.size; // resize this object
		 ptr = new T[ size ]; // create space for array copy, type T
	  } // end inner if

	  for ( int i = 0; i < size; ++i )
		 ptr[ i ] = right.ptr[ i ]; // copy array into object
   } // end outer if

   return *this; // enables x = y = z, for example
} // end function operator=

#endif //ARRAYT_H
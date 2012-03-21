#include "ArrayTHelper.h"

using namespace std;
// overloaded input operator for class ArrayT;
// inputs values for entire ArrayT
//not a friend for ArrayTT
template<typename T>
istream & operator>>( istream &input, ArrayT<T> &a )
{
   //for ( int i = 0; i < a.size; ++i )
	//  input >> a.ptr[ i ];
	a.input(is);
   return input; // enables cin >> x >> y;
} // end function 

// overloaded output operator for class ArrayT 
template<typename T>
ostream &operator<<( ostream &output, const ArrayT<T> &a )
{
  // int i;

   // output private ptr-based ArrayT 
  // for ( i = 0; i < a.size; ++i )
  // {
  //    output << a.ptr[ i ] << " ";
  // } // end for
	a.print(os);
   return output; // enables cout << x << y;
} // end function operator<<
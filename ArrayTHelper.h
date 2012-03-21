#ifndef ARRAYHELPER_H
#define ARRAYHELPER_H
#include <iostream>
#include "ArrayT.h"
template< typename T>
std::ostream &operator<<( std::ostream &, const ArrayT<T> & );
template< typename T>
std::istream &operator>>( std::istream &, ArrayT<T> & );
#endif //ARRAYTHELPER_H

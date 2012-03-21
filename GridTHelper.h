#ifndef GRIDTHELPER_H
#define GRIDTHELPER_H
#include "GridT.h"
#include <iostream>
template< typename T>
std::ostream& operator<<(std::ostream&,const GridT<T>&);
#endif//GRIDTHELPER_H

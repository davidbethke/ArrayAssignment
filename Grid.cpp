#include "Grid.h"
#include "GridHelper.h"


Grid::Grid(int r,int c):nRows(r),nCols(c)
{
	myGrid= new Array[nRows];
	for(int i=0;i<nRows;++i)
		myGrid[i]=Array(nCols); //vals not pointers
}


Grid::~Grid(void)
{
	delete[] myGrid;
}
Grid::Grid(const Grid &other)
{
	nRows=other.nRows;
	nCols=other.nCols;
	myGrid=new Array[other.nRows];
	for(int i=0;i<nRows;++i)
		myGrid[i]=Array(other.myGrid[i]); // use copy constructor from array
}
Grid& Grid::operator=(const Grid &other)
{
	if(this != &other)// dont check nRows and nCols, start from scratch
	{
		delete [] myGrid;			// de alloc old mem
		myGrid= new Array[other.nRows];
		nRows=other.nRows;
		nCols=other.nCols;
		for(int i=0; i<nRows;++i)
			myGrid[i]=Array(other.myGrid[i]); // Array copy constructor
	}
	return *this;
}
int Grid::getRows() const
{
	return nRows;
}
int Grid::getCols() const
{
	return nCols;
}
Array& Grid::operator[](int i)
{
	if(inBounds(i))
		return myGrid[i];
	else
		throw out_of_range( "Subscript out of range" ); // borrowed from Array.cpp
}
const Array& Grid::operator[](int i) const
{
	if(inBounds(i))
		return myGrid[i];
	else
		throw out_of_range( "Subscript out of range" ); // borrowed from Array.cpp
}
bool Grid::inBounds(int i) const
{
	if(i>=0 && i<nRows)
		return true;
	else
		return false;
}

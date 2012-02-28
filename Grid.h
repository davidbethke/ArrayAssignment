#ifndef GRID_H
#define GRID_H
#include "ArrayClass\Array.h"

class Grid
	
{
	friend std::ostream& operator<<(std::ostream&,const Grid&);
public:
	Grid(int=10,int=10);
	~Grid(void);
	Grid(const Grid&); // copy constructor
	Grid& operator=(const Grid&);
	int getRows() const;
	int getCols() const;
	Array& operator[](int);
	const Array& operator[](int) const;
private:
	Array * myGrid;
	int nRows;
	int nCols;
	bool inBounds(int) const;

};
//TODO operator<<
/*
std::ostream& operator<<(std::ostream& os, const Grid& g)
{
	
	return os;
}
*/
#endif //GRID_H
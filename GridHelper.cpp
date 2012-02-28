#include "GridHelper.h"
#include "Grid.h"
using namespace std;
ostream& operator<<(ostream& os, const Grid& g)
{
	for(int i=0; i<g.nRows;++i)
		cout << g.myGrid[i]<<endl;
	return os;
}

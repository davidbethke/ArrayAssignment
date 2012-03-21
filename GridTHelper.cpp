#include "GridTHelper.h"
using namespace std;
template< typename T>
std::ostream& operator<<(std::ostream& os,const GridT<T>&g)
{
	g.print(os);
	return os;
}

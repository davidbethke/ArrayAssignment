#ifndef GRID_TEST_H
#define GRID_TEST_H
#include "d:\users\dave\documents\visual studio 2010\projects\gtest\include\gtest\gtest.h"
#include "Grid.h"
void makeOutput(string&);

class GridTest :
	public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		p_cout_streambuf = std::cout.rdbuf();
		makeOutput(gridOutput);

	}
	virtual void TearDown()
	{
		std::cout.rdbuf(p_cout_streambuf); // restore
	}
	Grid myGrid, myGridVals;
	std::string gridOutput;
	const Grid myGridConst;
	std::ostringstream oss;
	std::streambuf* p_cout_streambuf;
public:
	GridTest(void);
	~GridTest(void);
};

#endif // GRID_TEST_H
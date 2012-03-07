// Grid.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Grid.h"
#include <iostream>

#ifdef _DEBUG
#include "gtest/gtest.h"


TEST(sample_test_case, sample_test)
{
	EXPECT_EQ(1, 1);
}
#endif //_DEBUG
#ifdef NDEBUG
void initMyGrid(Grid&,int,int,int);
void initMyGrid(Grid &g, int initVal)
{
	for(int i=0; i<g.getRows();++i)
		for(int j=0;j<g.getCols();++j)
			g[i][j]=initVal;

}

#endif //NDEBUG
using namespace std;
int main(int argc, char** argv) 
{ 
#ifdef _DEBUG //Debug Version
	::testing::GTEST_FLAG(print_time) = true;
	::testing::GTEST_FLAG(output) = "xml:C:\\Program Files\\Jenkins\\jobs\\GridTest\\workspace\\test_detail.xml";
	
	testing::InitGoogleTest(&argc, argv); 
	RUN_ALL_TESTS(); 
	std::getchar(); // keep console window open until Return keystroke
#endif // _DEBUG
#ifdef NDEBUG // Release Version
	Grid myGrid(5,5),myDefaultGrid;
	Grid myOtherGrid(myGrid);
	Grid const myConstGrid;
	//print rows cols
	cout <<"MyGrid"<<endl;
	cout <<"rows:"<<myGrid.getRows()<<",cols:"<<myGrid.getCols()<<endl;
	cout <<"MyDefaultGrid"<<endl;
	cout <<"rows:"<<myDefaultGrid.getRows()<<",cols:"<<myDefaultGrid.getCols()<<endl;
	cout <<"MyOtherGrid"<<endl;
	cout <<"rows:"<<myOtherGrid.getRows()<<",cols:"<<myOtherGrid.getCols()<<endl;
	cout <<"MyConstGrid"<<endl;
	cout <<"rows:"<<myConstGrid.getRows()<<",cols:"<<myConstGrid.getCols()<<endl;
	// init
	initMyGrid(myGrid,55);
	initMyGrid(myDefaultGrid,110);
	initMyGrid(myOtherGrid,44);
	//init of const fails
	// initMyGrid(myConstGrid,99); // fails as expected
	//print out
	cout << "MyGrid"<<endl;
	cout << myGrid;
	cout <<endl;
	cout << "MyDefaultGrid"<<endl;
	cout << myDefaultGrid;
	cout <<endl;
	cout << "MyOtherGrid"<<endl;
	cout << myOtherGrid;
	cout <<endl;
	cout << "MyConstGrid"<<endl;
	cout << myConstGrid;
	cout <<endl;
	// assign myGrid to myOtherGrid, print
	myOtherGrid=myGrid;
	cout << "MyOtherGrid"<<endl;
	cout << myOtherGrid;
	cout <<endl;
	// assign myConstGrid to myGrid, print
	myGrid=myConstGrid;
	cout << "MyGrid"<<endl;
	cout << myGrid;
	cout <<endl;
	getchar();
#endif // NDEBUG
}
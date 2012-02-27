#include "GridTest.h"


GridTest::GridTest(void):myGrid(),myGridVals(5,5),myGridConst()
{
	for(int i=0; i<myGridVals.getRows();++i)
		for(int j=0; j<myGridVals.getCols();++j)
			myGridVals[i][j]= i*j;
}


GridTest::~GridTest(void)
{
}
TEST_F(GridTest,getSize)
{
	EXPECT_EQ(10,myGrid.getRows());
	EXPECT_EQ(10,myGrid.getCols());
	EXPECT_EQ(10,myGridConst.getRows());
	EXPECT_EQ(10,myGridConst.getCols());
	EXPECT_EQ(5,myGridVals.getRows());
	EXPECT_EQ(5,myGridVals.getCols());
}
TEST_F(GridTest,subScriptnonConst)
{
	std::cout.rdbuf(oss.rdbuf());
	Array myArray;
	myArray=myGrid[0];
	EXPECT_EQ(0,myArray[0])<<"default array val FAIL";
	myArray[5]=55;
	EXPECT_EQ(55,myArray[5])<<"set array val FAIL";
	cout <<myArray;
	EXPECT_EQ("0 0 0 0 0 55 0 0 0 0 ",oss.str());
}
TEST_F(GridTest,subScriptnonConst2)
{
	std::cout.rdbuf(oss.rdbuf());
	
	myGrid[0];
	EXPECT_EQ(0,myGrid[0][0])<<"default array val FAIL";
	myGrid[0][5]=55;
	EXPECT_EQ(55,myGrid[0][5])<<"set array val FAIL";
	cout <<myGrid[0];
	EXPECT_EQ("0 0 0 0 0 55 0 0 0 0 ",oss.str());
}
TEST_F(GridTest,subScriptnonConst3)
{
	std::cout.rdbuf(oss.rdbuf());
	
	myGridVals[0];
	EXPECT_EQ(0,myGridVals[0][0])<<"default array val FAIL";
	myGridVals[4][0]=55;
	EXPECT_EQ(55,myGridVals[4][0])<<"set array val FAIL";
	cout <<myGridVals[4];
	EXPECT_EQ("55 4 8 12 16 ",oss.str());
}
TEST_F(GridTest,subScriptConst)
{
	std::cout.rdbuf(oss.rdbuf());
	Array myArray;
	myArray=myGridConst[0];
	EXPECT_EQ(0,myArray[0])<<"default array val FAIL";
	myArray[5]=55;
	EXPECT_EQ(55,myArray[5])<<"set array val FAIL";
	cout <<myArray;
	EXPECT_EQ("0 0 0 0 0 55 0 0 0 0 ",oss.str());
}
TEST_F(GridTest,subScriptConst2)
{
	std::cout.rdbuf(oss.rdbuf());
	
	myGridConst[0];
	EXPECT_EQ(0,myGridConst[0][0])<<"default array val FAIL";
	//myGridConst[0][5]=55; // fail can't assign to const, rval
	//EXPECT_EQ(55,myArray[5])<<"set array val FAIL";
	cout <<myGridConst[0];
	EXPECT_EQ("0 0 0 0 0 0 0 0 0 0 ",oss.str());
}

TEST_F(GridTest,gridBounds)
{
	ASSERT_NO_THROW(myGrid[0])<<" out of boundsFAIL";
	ASSERT_NO_THROW(myGridConst[0])<<" out of boundsFAIL";
	ASSERT_NO_THROW(myGridVals[0])<<" out of boundsFAIL";
	ASSERT_THROW(myGrid[10],out_of_range)<<" out of boundsFAIL";
	ASSERT_THROW(myGridConst[10],out_of_range)<<" out of boundsFAIL";
	ASSERT_THROW(myGridVals[5],out_of_range)<<" out of boundsFAIL";
}
TEST_F(GridTest,copyConstructor)
{
	std::cout.rdbuf(oss.rdbuf());
	Grid myG(myGrid), myGc(myGridConst), myGv(myGridVals);
	cout <<myGv[4];
	EXPECT_EQ("0 4 8 12 16 ",oss.str());
	oss.str(""); //clear string
	cout << myG[0];
	EXPECT_EQ("0 0 0 0 0 0 0 0 0 0 ",oss.str());
	oss.str(""); //clear string
	cout << myGc[9];
	EXPECT_EQ("0 0 0 0 0 0 0 0 0 0 ",oss.str());
		
}
TEST_F(GridTest, assignOp)
{
	std::cout.rdbuf(oss.rdbuf());
	// check self assign
	myGridVals= myGridVals;
	EXPECT_EQ(5,myGridVals.getRows())<<"Rows after assign FAIL";
	EXPECT_EQ(5,myGridVals.getCols())<<"Cols after assign FAIL";
	cout << myGridVals[4];
	EXPECT_EQ("0 4 8 12 16 ",oss.str());
	oss.str(""); //clear string
	//assign smaller to larger
	myGrid=myGridVals;
	EXPECT_EQ(5,myGrid.getRows())<<"Rows after assign FAIL";
	EXPECT_EQ(5,myGrid.getCols())<<"Cols after assign FAIL";
	cout << myGrid[4];
	EXPECT_EQ("0 4 8 12 16 ",oss.str());
	oss.str(""); //clear string
	// assign a const to a non const of different size
	myGridVals=myGridConst;
	EXPECT_EQ(10,myGridVals.getRows())<<"Rows after assign FAIL";
	EXPECT_EQ(10,myGridVals.getCols())<<"Cols after assign FAIL";
	cout << myGridVals[4];
	EXPECT_EQ("0 0 0 0 0 0 0 0 0 0 ",oss.str());
}
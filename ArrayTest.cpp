#include "ArrayTest.h"


ArrayTest::ArrayTest(void):arr(10),arrHalf(5),arrConst(10)
{
}


ArrayTest::~ArrayTest(void)
{
}
TEST_F(ArrayTest,arrTestSize)
{
	EXPECT_EQ(10,arr.getSize())<<"Arr Size Fail";
	EXPECT_EQ(10,arrConst.getSize())<<"Const Arr Size FAIL";
	EXPECT_EQ(5,arrHalf.getSize())<<"Const Arr Size FAIL";
}
TEST_F(ArrayTest,arrTestEqual)
{
	EXPECT_TRUE(arr==arrConst)<<"Arr Equal arrConst Fail";
	EXPECT_TRUE(arrConst==arr)<<"ArrConst Equal arr Fail";
	EXPECT_TRUE(arrConst==arrConst)<<"ArrConst Equal arrConst Fail";
	EXPECT_TRUE(arrHalf==arrHalf)<<"arrHalf equal arrHalf Fail";
	EXPECT_FALSE(arrHalf == arr)<<"arrHalf equal arr Fail";
	EXPECT_FALSE(arr == arrHalf)<<"arr equal arrHalf Fail";
	EXPECT_FALSE(arrHalf == arrConst)<<"arrHalf equal arrConst Fail";
}
TEST_F(ArrayTest, arrTestNotEqual)
{
	EXPECT_FALSE(arr!=arrConst)<<"Arr not Equal arrConst Fail";
	EXPECT_FALSE(arrConst!=arr)<<"ArrConst not Equal arr Fail";
	EXPECT_FALSE(arrConst!=arrConst)<<"ArrConst not Equal arrConst Fail";
	EXPECT_FALSE(arrHalf!=arrHalf)<<"arrHalf not equal arrHalf Fail";
	EXPECT_TRUE(arrHalf != arr)<<"arrHalf not equal arr Fail";
	EXPECT_TRUE(arr != arrHalf)<<"arr not equal arrHalf Fail";
	EXPECT_TRUE(arrHalf != arrConst)<<"arrHalf not equal arrConst Fail";
}
TEST_F(ArrayTest, arrTestAssignmentConst)
{
	arr=arrConst;
	EXPECT_TRUE(arr==arrConst)<<"Arr  Equal arrConst Fail";
	EXPECT_TRUE(arrConst==arr)<<"arrConst  equal arr FAIL";
	//half = const
	EXPECT_EQ(5,arrHalf.getSize())<<"arrHalf getSize before assign FAIL";
	arrHalf=arrConst;
	EXPECT_TRUE(arrHalf==arrConst)<<"ArrHalf  Equal arrConst Fail";
	EXPECT_TRUE(arrConst==arrHalf)<<"arrConst  equal arrHalf FAIL";
	EXPECT_EQ(10,arrHalf.getSize())<<"arrHalf getSize after assign FAIL";
}
TEST_F(ArrayTest,arrTestCopyConst)
{
	Array arrCp1(arr);
	Array arrCp1Const(arrConst);
	// check size
	EXPECT_EQ(10,arrCp1.getSize())<<"arrCp1 getSize FAIL";
	EXPECT_EQ(10,arrCp1Const.getSize())<<"arrCp1Const getSize FAIL";
	// check equality
	EXPECT_TRUE(arrCp1 == arr)<<"arrCp1 equal arr FAIL";
	EXPECT_TRUE(arrCp1Const == arrConst)<<"arrCp1Const equal arrConst FAIL";
	EXPECT_TRUE(arrCp1 == arrCp1Const)<<"arrCp1 equal arrConstCp1 FAIL";
}
TEST_F(ArrayTest,arrTestSubscriptRead)
{
	EXPECT_EQ(0,arr[0])<<"arr[0] FAIL";
	EXPECT_EQ(0,arrConst[0])<<"arrConst[0] FAIL";
	EXPECT_EQ(0,arrHalf[0])<<"arrHalf[0] FAIL";

}
TEST_F(ArrayTest,arrTestSubscriptWrite)
{
	arr[0]=99;
	//arrConst[0]=99; // should fail assign to const, wont compile
	arrHalf[0]=88;
	EXPECT_TRUE(arr[0]==99)<<"arr[0] FAIL";
	EXPECT_TRUE(arrConst[0] != 99)<<"arrConst[0] FAIL";
	EXPECT_TRUE(arrHalf[0]==88)<<"arrHalf[0] FAIL";

}
TEST_F(ArrayTest,arrTestOutOfBounds)
{
	ASSERT_THROW(arr[10],out_of_range)<<" out of boundsFAIL";
	ASSERT_THROW(arrConst[10],out_of_range)<<" out of boundsFAIL";
	ASSERT_THROW(arrHalf[5],out_of_range)<<" out of boundsFAIL";
}


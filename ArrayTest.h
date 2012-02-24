#pragma once
#include "d:\users\dave\documents\visual studio 2010\projects\gtest\include\gtest\gtest.h"
#include "ArrayClass\Array.h"
class ArrayTest :
	public ::testing::Test
{
protected: 
	virtual void SetUp()
	{
	}
	virtual void TearDown()
	{
	}
	Array arr, arrHalf;
	const Array arrConst;
public:
	ArrayTest(void);
	~ArrayTest(void);
};


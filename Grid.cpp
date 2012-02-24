// Grid.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>

#include "gtest/gtest.h"

TEST(sample_test_case, sample_test)
{
	EXPECT_EQ(1, 1);
}

int main(int argc, char** argv) 
{ 
	::testing::GTEST_FLAG(print_time) = true;
	::testing::GTEST_FLAG(output) = "xml:C:\\Program Files\\Jenkins\\jobs\\GridTest\\workspace\\test_detail.xml";
		
	testing::InitGoogleTest(&argc, argv); 
	RUN_ALL_TESTS(); 
	std::getchar(); // keep console window open until Return keystroke
}
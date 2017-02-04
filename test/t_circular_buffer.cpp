/*
 * push.cpp
 *
 *  Created on: 25.01.2017
 *      Author: sash
 */
#include "gtest/gtest.h"
#include "circular_buffer.h"

TEST(t_circular_buffer, push)
{
	lib98::circular_buffer<int> a(5);
	int res[] = {4,5,6,7,8};

	for(int i=0; i<9; ++i){
		a.push_back(i);
	}

	EXPECT_TRUE(std::equal(a.begin(), a.end(), res));
//	int res
//    double res;
//    res = add_numbers(1.0, 2.0);
//    ASSERT_NEAR(res, 3.0, 1.0e-11);
}




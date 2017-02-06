/*
 * push.cpp
 *
 *  Created on: 25.01.2017
 *      Author: sash
 */
#include "gtest/gtest.h"
#include "circular_buffer.h"

TEST(t_circular_buffer, push9)
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

TEST(t_circular_buffer, cctor)
{
	lib98::circular_buffer<int> a(5);
	int res[] = {4,5,6,7,8};

	for(int i=0; i<9; ++i){
		a.push_back(i);
	}


	lib98::circular_buffer<int> b(a);

	EXPECT_TRUE(std::equal(a.begin(), a.end(), b.begin()));
}

TEST(t_circular_buffer, assignment_operator)
{
	lib98::circular_buffer<int> a(5);
	int res[] = {4,5,6,7,8};

	for(int i=0; i<9; ++i){
		a.push_back(i);
	}


	lib98::circular_buffer<int> b;

	b=a;

	EXPECT_TRUE(std::equal(a.begin(), a.end(), b.begin()));
}

TEST(t_circular_buffer, logic_queries)
{
// not allocated
	lib98::circular_buffer<int> e;
	EXPECT_TRUE(e.size()==0);
	EXPECT_TRUE(e.capacity()==0);
	EXPECT_TRUE(e.is_full()==1);
	EXPECT_TRUE(e.begin()==e.end());
	EXPECT_TRUE(e.empty());

// allocated, empty
	lib98::circular_buffer<int> a(5);
	EXPECT_TRUE(a.size()==0);
	EXPECT_TRUE(a.capacity()==5);
	EXPECT_TRUE(a.is_full()==0);
	EXPECT_TRUE(a.begin()==a.end());
	EXPECT_TRUE(a.empty());

// allocated, not full
	a.push_back(1);
	EXPECT_TRUE(a.size()==1);
	EXPECT_TRUE(a.capacity()==5);
	EXPECT_TRUE(a.is_full()==0);
	EXPECT_TRUE(a.begin()!=a.end());
	EXPECT_TRUE(!a.empty());

// allocated full
	for(int i=2; i<6; ++i){
		a.push_back(i);
	}
	EXPECT_TRUE(a.size()==5);
	EXPECT_TRUE(a.capacity()==5);
	EXPECT_TRUE(a.is_full()==1);
	EXPECT_TRUE(a.begin()!=a.end());
	EXPECT_TRUE(!a.empty());

}



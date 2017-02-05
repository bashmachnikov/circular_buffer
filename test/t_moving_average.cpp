/*
 * t_moving_average.cpp
 *
 *  Created on: 04.02.2017
 *      Author: sash
 */

#include "gtest/gtest.h"
#include "moving_average.h"

TEST(t_moving_average, push1)
{
	lib98::moving_average<int> a(5);
	int res[] = {1};

	a.push_back(1);

	ASSERT_NEAR(a.get_average(), 1, 1.0e-11);

//	EXPECT_TRUE();
//	int res
//    double res;
//    res = add_numbers(1.0, 2.0);
//    ASSERT_NEAR(res, 3.0, 1.0e-11);
}

TEST(t_moving_average, push5)
{
	lib98::moving_average<int> a(5);
	int init[] = {1, 2, 3, 4, 5 };
	int res=3;
	int i;

	std::copy( init, init+5, std::back_insert_iterator< lib98::moving_average<int> >(a) );
	ASSERT_NEAR(a.get_average(), res, 1.0e-11);

//	lib98::moving_average<int>::iterator it;
//	lib98::moving_average<int>::iterator it_end;
//	std::copy( a.begin(), a.end(), std::ostream_iterator<int>( std::cout, ", " ) );
//	it =
//	for( ; it!=it_end; ++it){
//		printf("%d, ", *it);
//	}
//	printf("\n%ld, %f\n", a.size(), a.get_average());
//	EXPECT_TRUE();
//	int res
//    double res;
//    res = add_numbers(1.0, 2.0);
//    ASSERT_NEAR(res, 3.0, 1.0e-11);
}

TEST(t_moving_average, push8)
{
	lib98::moving_average<int> a(5);
	int init[] = {0, -1, -2, 1, 2, 3, 4, 5 };
	int res=3;
	int i;

	std::copy( init, init+sizeof(init)/sizeof(*init), std::back_insert_iterator< lib98::moving_average<int> >(a) );
	//std::copy( a.begin(), a.end(), std::ostream_iterator<int>( std::cout, ", " ) );
	//std::cout << "\n";
	ASSERT_NEAR(a.get_average(), res, 1.0e-11);
}

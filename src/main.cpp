//============================================================================
// Name        : circular_buffer.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;
#include "circular_buffer.h"


bool test_push(){
	lib98::circular_buffer<int> a(5);

	for( int i=0; i<20; ++i ){
		a.push_back(i);

		cout<<i<<": sz="<<a.size()<<"; cap="<<a.capacity()<<"; ";
		copy( a.begin(), a.end(), std::ostream_iterator<int>(cout, ", ") );
		cout<<endl;
	}


	return 1;
}

int main() {

	if( !test_push() ){
		cout<<"boom: push\n";
	}
	return 0;
}

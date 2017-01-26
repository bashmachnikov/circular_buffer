//============================================================================
// Name        : circular_buffer.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <iostream>
#include <vector>

#include "circular_buffer.h"
#include "config.h"

using namespace std;

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

int main(int argc, char *argv[]) {


	fprintf(stdout, "%s Version %d.%d git_rev=%s\n", argv[0],
	VERSION_MAJOR,
	VERSION_MINOR, GIT_REVISION);

  
	if( !test_push() ){
		cout<<"boom: push\n";
	}

	return 0;
}

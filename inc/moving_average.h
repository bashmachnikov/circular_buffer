/*
 * moving_average.h
 *
 *  Created on: 04.02.2017
 *      Author: sash
 */

#ifndef INC_MOVING_AVERAGE_H_
#define INC_MOVING_AVERAGE_H_

#include <circular_buffer.h>

namespace lib98{

template <typename T>
class moving_average: public circular_buffer<T>{
public:
	moving_average(size_t sz):circular_buffer(sz){}

private:
};

}


#endif /* INC_MOVING_AVERAGE_H_ */

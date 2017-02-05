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
	//typedef typename circular_buffer<T> base;
	typedef typename circular_buffer<T>::size_type size_type;
	typedef typename circular_buffer<T>::value_type value_type;
	typedef typename circular_buffer<T>::iterator iterator;
	typedef typename circular_buffer<T>::const_reference const_reference;

	moving_average(size_t sz):circular_buffer<T>(sz), m_sum(0){}

	void push_back(value_type v){
		value_type minus = *circular_buffer<T>::begin() * circular_buffer<T>::is_full();
		circular_buffer<T>::push_back(v);
		m_sum+= v - minus;
	}

	double get_average()const{
		if( circular_buffer<T>::empty() ) return 0;
		return m_sum/circular_buffer<T>::size();
	}

protected:
	double m_sum;
};

}


#endif /* INC_MOVING_AVERAGE_H_ */

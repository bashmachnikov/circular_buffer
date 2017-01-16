/*
 * circular_buffer.h
 *
 *  Created on: 14.01.2017
 *      Author: sash
 */

#ifndef CIRCULAR_BUFFER_H_
#define CIRCULAR_BUFFER_H_

#include <vector>
#include <iterator>

namespace lib98{

template<typename T>
class circular_buffer{
public:

	typedef std::vector<T> container;
	typedef typename container::iterator viterator;
	typedef typename container::const_iterator vconst_iterator;
	typedef typename container::size_type size_type;
	typedef typename viterator::value_type value_type;

	class iterator : public std::iterator<	std::bidirectional_iterator_tag,
											value_type>
	{
	      typedef std::iterator_traits<viterator> traits_type;

	    public:
	      typedef typename traits_type::difference_type	difference_type;
	      typedef typename traits_type::pointer			pointer;
	      typedef typename traits_type::reference		reference;

		iterator(): m_fs(), m_bs(), m_it(){}
		iterator(viterator fs, viterator bs, viterator it):m_fs(fs), m_bs(bs), m_it(it){}
		iterator(viterator fs, viterator bs, difference_type pos):m_fs(fs), m_bs(bs), m_it(m_fs+pos){}
		~iterator(){}

		bool operator==(const iterator& rhv) {
			return m_it == rhv.m_it;
	    }

		bool operator!=(const iterator& rhv) {
			return !(*this==rhv);
	    }

		iterator& operator++() {
			++m_it;
			if(m_it == m_bs){
				m_it = m_fs+1;
			}
			return *this;
	    }

		iterator& operator--() {
			--m_it;
			if(m_it == m_fs){
				m_it = m_bs-1;
			}
			return *this;
	    }

		reference operator*() {
			return *m_it;
	    }

		difference_type pos() const{
			return m_it-m_fs;
		}

	protected:
	    viterator m_fs;
	    viterator m_bs;
	    viterator m_it;
	};

	circular_buffer():m_data(), m_size(0), m_begin(), m_end(){}

	circular_buffer(size_type size):m_data(), m_size(0), m_begin(), m_end(){
		if(size > 0){
			m_data.resize(size+1);
			m_size=0;
			m_begin = iterator(m_data.begin()-1, m_data.end(), m_data.begin());
			m_end = m_begin;
		}
	}

	circular_buffer(const circular_buffer& rhv) :
			m_data(rhv.m_data), m_size(rhv.m_size) {
		m_begin = iterator(m_data.begin() - 1, m_data.end(), rhv.begin().pos());
		m_end = iterator(m_data.begin() - 1, m_data.end(), rhv.end().pos());
	}

	circular_buffer& operator=(const circular_buffer& rhv){
		m_data = rhv.m_data;
		m_size = rhv.m_size;
		m_begin = iterator(m_data.begin() - 1, m_data.end(), rhv.begin().pos());
		m_end = iterator(m_data.begin() - 1, m_data.end(), rhv.end().pos());
		return *this;
	}

	virtual ~circular_buffer(){}

	bool empty()const{
		return m_size==0;
	}

	iterator begin(){
		return m_begin;
	}

	iterator end(){
		return m_end;
	}

	size_type capacity() const{
		return m_data.empty()?0:m_data.size()-1;
	}

	size_type size() const{
		return m_size;
	}

	void push_back(const value_type& v){
		if( m_data.empty() ){
			return;
		}

		*m_end = v;
		++m_end;

		if( m_size < capacity() ){
			++m_size;
			return;
		}
		++m_begin;
	}

protected:
	container 	m_data;
	size_type 	m_size;
	iterator 	m_begin;
	iterator 	m_end;
};


}//lib98

#endif /* CIRCULAR_BUFFER_H_ */

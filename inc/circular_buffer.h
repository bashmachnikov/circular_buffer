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
	typedef typename container::const_reference const_reference;

	template<typename _Iterator>
	class iterator_base
	{
	      typedef std::iterator_traits<_Iterator> traits_type;

	    public:
	      typedef iterator_base<_Iterator>					iterator_type;
	      typedef typename std::bidirectional_iterator_tag  iterator_category;
	      typedef typename traits_type::value_type  		value_type;
	      typedef typename traits_type::difference_type 	difference_type;
	      typedef typename traits_type::reference 			reference;
	      typedef typename traits_type::pointer   			pointer;

	    iterator_base(): m_fs(), m_bs(), m_it(){}
	    iterator_base(_Iterator fs, _Iterator bs, _Iterator it):m_fs(fs), m_bs(bs), m_it(it){}
	    iterator_base(_Iterator fs, _Iterator bs, difference_type pos):m_fs(fs), m_bs(bs), m_it(m_fs+pos){}
		~iterator_base(){}

		bool operator==(const iterator_type& rhv) {
			return m_it == rhv.m_it;
	    }

		bool operator!=(const iterator_type& rhv) {
			return !(*this==rhv);
	    }

		iterator_type& operator++() {
			++m_it;
			if(m_it == m_bs){
				m_it = m_fs+1;
			}
			return *this;
	    }

		iterator_type& operator--() {
			--m_it;
			if(m_it == m_fs){
				m_it = m_bs-1;
			}
			return *this;
	    }

		reference operator*() {
			return *m_it;
	    }

		pointer operator->() {
			return &(*m_it);
	    }

		difference_type pos() const{
			return m_it-m_fs;
		}

		_Iterator get_it() {
			return m_it;
		}

	protected:
		_Iterator m_fs;
		_Iterator m_bs;
		_Iterator m_it;
	};

	typedef iterator_base<viterator> iterator;
	typedef iterator_base<vconst_iterator> const_iterator;

	circular_buffer():m_data(), m_size(0), m_begin(), m_end(){}

	circular_buffer(size_type size):m_data(), m_size(0), m_begin(), m_end(){
		if(size > 0){
			m_data.resize(size+1);
			m_size=0;
			m_begin = m_end  = m_data.begin();
		}
	}

	circular_buffer(const circular_buffer& rhv) {
		*this = rhv;
	}

	circular_buffer& operator=(const circular_buffer& rhv){
		m_data = rhv.m_data;
		m_size = rhv.m_size;
		m_begin = m_data.begin() + (rhv.m_begin - rhv.m_data.begin());
		m_end = m_data.begin() + (rhv.m_end - rhv.m_data.begin());
		return *this;
	}

	virtual ~circular_buffer(){}

	bool empty()const{
		return m_size==0;
	}

	iterator begin(){
		return iterator( m_data.begin()-1, m_data.end(), m_begin );
	}

	iterator end(){
		return iterator( m_data.begin()-1, m_data.end(), m_end );
	}

	const_iterator begin() const{
		return const_iterator( m_data.begin()-1, m_data.end(), m_begin );
	}

	const_iterator end() const{
		return const_iterator( m_data.begin()-1, m_data.end(), m_end );
	}

	size_type capacity() const{
		return m_data.empty()?0:m_data.size()-1;
	}

	size_type size() const{
		return m_size;
	}

	bool is_full() const{
		return size() == capacity();
	}

	void push_back(const value_type& v){
		if( m_data.empty() ){
			return;
		}

		iterator it = end();
		*it = v;
		++it;
		m_end = it.get_it();

		if( m_size < capacity() ){
			++m_size;
			return;
		}
		it = begin();
		++it;
		m_begin = it.get_it();
	}

protected:
	container 	m_data;
	size_type 	m_size;
	viterator 	m_begin;
	viterator 	m_end;
};


}//lib98

#endif /* CIRCULAR_BUFFER_H_ */


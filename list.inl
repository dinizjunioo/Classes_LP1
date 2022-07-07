#include "list.h"
//#include <iostream>
/// Iterator accessor methods.

namespace sc 
{
    template < typename T >
    typename list<T>::iterator  list<T>::begin(void)
    {
        return iterator;
    }

    template < typename T >
    void list<T>::clear(void)
    {

    }

    template < typename T >
    size_t list<T>::size(void)const
    {
        return m_len;
    }

    template < typename T >
    bool list<T>::empty(void)const
    {
        return m_len == 0 ? true : false;
    }
}
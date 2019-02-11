#include "insert_sort.h"

#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
void insert_sort<T>::sort(typename std::vector<T>::iterator begin_it, typename std::vector<T>::iterator end_it)
{
  typename std::vector<T>::iterator it = begin_it;
   
  dump(begin_it, end_it);
  for( ; it != end_it; ++it) {
    typename std::vector<T>:: iterator sit = it;
    while ( sit != begin_it && *sit < *(sit-1) ) {
      std::swap(*sit, *(sit-1) );
      --sit;
      dump(begin_it, end_it);
    }
  }
}


template <typename T>
void insert_sort<T>::dump(typename std::vector<T>::iterator begin_it, typename std::vector<T>::iterator end_it)
{
  typename std::vector<T>::iterator it = begin_it;
  for ( ; it != end_it; ++it) {
    std::cout << *it << " ";
  }
  
  std::cout << std::endl;
}


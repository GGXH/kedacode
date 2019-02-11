#include "select_sort.h"

#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
void select_sort<T>::sort1(typename std::vector<T>::iterator begin_it, typename std::vector<T>::iterator end_it) 
{
  //debug
  select_sort<T>::dump(begin_it, end_it);
 
  typename std::vector<T>::iterator it = begin_it;
  while ( it != end_it ) {
    typename std::vector<T>::iterator sit = it;
    typename std::vector<T>::iterator min_it = it;
    while ( sit != end_it ) {
      if ( *sit < *min_it ) {
        min_it = sit;
      }
      ++sit;
    }
    if ( min_it != it ) {
      std::swap(*min_it, *it);
    }
    ++it;
    
    //debug
    select_sort<T>::dump(begin_it, end_it);
  }
}

template <typename T>
void select_sort<T>::dump(typename std::vector<T>::iterator begin_it, typename std::vector<T>::iterator end_it)
{
  typename std::vector<T>::iterator it = begin_it;
  for ( ; it != end_it; ++it) {
    std::cout << *it << " ";
  }
  
  std::cout << std::endl;
}



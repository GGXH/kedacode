#ifndef SELECT_SORT
#define SELECT_SORT

#include <vector>

template <typename T>
class select_sort {
public:
  static void sort1(typename std::vector<T>::iterator begin_it, typename std::vector<T>::iterator end_it);
   
  static void dump(typename std::vector<T>::iterator begin_it, typename std::vector<T>::iterator end_it);
};

template class select_sort<int>;

#endif

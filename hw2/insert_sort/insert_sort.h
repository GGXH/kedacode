#ifndef INSERT_SORT
#define INSERT_SORT

#include <vector>

template <typename T>
class insert_sort {
public:
  static void sort(typename std::vector<T>::iterator begin_it, typename std::vector<T>::iterator end_it);
   
  static void dump(typename std::vector<T>::iterator begin_it, typename std::vector<T>::iterator end_it);
};


template class insert_sort<int>;

#endif

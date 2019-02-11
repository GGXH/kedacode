#ifndef QUICK_SORT
#define QUICK_SORT

#include <vector>

template <typename T>
class quick_sort {
public:
  static void sort(typename std::vector<T>& data);
   
private:
  static void sort_sub(typename std::vector<T>& data, const typename std::vector<T>::size_type& bindx, 
                       const typename std::vector<T>::size_type& eindx);
  static void dump(const typename std::vector<T>& data, const typename std::vector<T>::size_type& bindx,
                   const typename std::vector<T>::size_type& eindx, const typename std::vector<T>::size_type& pindx);
};

template class quick_sort<int>;

#endif

#ifndef MERGE_SORT
#define MERGE_SORT

#include <vector>

template <typename T>
class merge_sort {
public:
  static void sort(typename std::vector<T>& data);
private:
  static void sort_sub(typename std::vector<T>& data, const typename std::vector<T>::size_type& bindx, 
                       const typename std::vector<T>::size_type& eindx);
  static void merge_sub(typename std::vector<T>& data, const typename std::vector<T>::size_type& bindx1, 
                        const typename std::vector<T>::size_type& eindx1, const typename std::vector<T>::size_type& bindx2, 
                        const typename std::vector<T>::size_type& eindx2);
  static void dump(const typename std::vector<T>& data, const typename std::vector<T>::size_type& bindx,
                   const typename std::vector<T>::size_type& mindx, const typename std::vector<T>::size_type& eindx);
};

template class merge_sort<int>;

#endif

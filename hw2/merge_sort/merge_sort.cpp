#include "merge_sort.h"

#include <iostream>
#include <vector>

template <typename T>
void merge_sort<T>::sort(typename std::vector<T>& data)
{
   sort_sub(data, 0, data.size() - 1);
}
 
 
 
template <typename T>
void merge_sort<T>::sort_sub(typename std::vector<T>& data, const typename std::vector<T>::size_type& bindx, 
                             const typename std::vector<T>::size_type& eindx) 
{
  if ( bindx >= eindx ) {
     return ;
  }
  
  typename std::vector<T>::size_type mindx = bindx + ( eindx - bindx ) / 2;
  sort_sub(data, bindx, mindx);
  //
  sort_sub(data, mindx + 1, eindx);
  //
  merge_sub(data, bindx, mindx, mindx+1, eindx);
  dump(data, bindx, mindx, eindx);
}


template <typename T>
void merge_sort<T>::dump(const typename std::vector<T>& data, const typename std::vector<T>::size_type& bindx,
                         const typename std::vector<T>::size_type& mindx, const typename std::vector<T>::size_type& eindx)
{
 
   std::cout << "bindx: " << bindx << " mindx: " << mindx << " eindx: " << eindx << std::endl;
   typename std::vector<T>::size_type indx = bindx;
   for( ; indx <= eindx; ++indx) {
      std::cout << data[indx] << " ";
   }
   std::cout << std::endl;
}


template <typename T>
void merge_sort<T>::merge_sub(typename std::vector<T>& data, const typename std::vector<T>::size_type& bindx1, 
                              const typename std::vector<T>::size_type& eindx1, const typename std::vector<T>::size_type& bindx2, 
                              const typename std::vector<T>::size_type& eindx2)
{
  if ( eindx1 < bindx1 && eindx2 < bindx2 ) return;
  
  typename std::vector<T>::size_type total_length = eindx1 - bindx1 + 1 + eindx2 - bindx2 + 1;
  typename std::vector<T> tmp_data(total_length);
  typename std::vector<T>::size_type mark1 = bindx1;
  typename std::vector<T>::size_type mark2 = bindx2;
  typename std::vector<T>::size_type mark0 = 0;
  
  while ( mark1 <= eindx1 && mark2 <= eindx2 ) {
    if ( data[mark1] < data[mark2] ) {
      tmp_data[mark0] = data[mark1];
      ++mark1;
    } else {
      tmp_data[mark0] = data[mark2];
      ++mark2;
    }
    ++mark0;
  }
  
  while ( mark1 <= eindx1 ) {
    tmp_data[mark0] = data[mark1];
    ++mark1;
    ++mark0;
  }
  
  while ( mark2 <= eindx2 ) {
    tmp_data[mark0] = data[mark2];
    ++mark2;
    ++mark0;
  }
  
  mark0 = 0;
  mark1 = bindx1;
  for ( ; mark0 <= total_length - 1; ++mark0, ++mark1) {
    data[mark1] = tmp_data[mark0];
  }
}


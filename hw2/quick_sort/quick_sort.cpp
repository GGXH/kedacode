#include "quick_sort.h"

#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <vector>

template <typename T>
void quick_sort<T>::sort(typename std::vector<T>& data)
{
   sort_sub(data, 0, data.size() - 1);
}

template <typename T>
void quick_sort<T>::sort_sub(typename std::vector<T>& data, const typename std::vector<T>::size_type& bindx, 
                             const typename std::vector<T>::size_type& eindx)
{
   if ( bindx >= eindx ) return ;
    
   typename std::vector<T>::size_type p_indx = std::rand() % ( eindx - bindx + 1 ) + bindx;
   
   typename std::vector<T>::size_type indx = bindx;
   typename std::vector<T>::size_type indx_end_marker = eindx;
    
   std::cout << "before sorting: " << std::endl;
   dump(data, bindx, eindx, p_indx);
    
   std::swap(data[p_indx], data[bindx]);
    
   dump(data, bindx, eindx, p_indx);
        
   while ( indx <= indx_end_marker ) {
     if ( data[indx] > data[bindx] ) {
       std::swap(data[indx], data[indx_end_marker]);
       --indx_end_marker;
     } else {
       ++indx;
     }
   }
   
   std::swap(data[bindx], data[indx_end_marker]);
    
   std::cout << "after sorting: " << std::endl;
   dump(data, bindx, eindx, p_indx);
   
   if ( indx_end_marker >= 1 ) {
     sort_sub(data, bindx, indx_end_marker - 1);
   }
   sort_sub(data, indx_end_marker + 1, eindx);
}



template <typename T>
void quick_sort<T>::dump(const typename std::vector<T>& data, const typename std::vector<T>::size_type& bindx,
                         const typename std::vector<T>::size_type& eindx, const typename std::vector<T>::size_type& pindx)
{
 
   std::cout << "bindx: " << bindx << " eindx: " << eindx << " pindx: " << pindx << std::endl;
   typename std::vector<T>::size_type indx = bindx;
   for( ; indx <= eindx; ++indx) {
      std::cout << data[indx] << " ";
   }
   std::cout << std::endl;
}
   
   

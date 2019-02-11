#include "pq.h"

#include <algorithm>
#include <iostream>
#include <vector>

template<class T>
pq<T>::~pq() {
}


template<class T>
void pq<T>::resize() {
  d_cap *= 2;
  d_data.resize(d_cap);
}


template<class T>
void pq<T>::push(const T& data) {
   if ( d_size == d_cap ) {
     resize();
   }
   
   ++d_size;
   d_data[d_size - 1] = data;
   
   popUp(d_size - 1);
   dump();
}


template<class T>
void pq<T>::pop() {
  if ( d_size == 0 ) {
     throw "Empty queue";
  }
  d_data[0] = d_data[d_size - 1];
  --d_size;
  pushDown(0);
}


template<class T>
T pq<T>::peek() {
  if ( d_size == 0 ) {
    throw "Emmpty queue";
  }
  return d_data[0];
}


template<class T>
typename pq<T>::indxtype pq<T>::leftChildIndx(const pq<T>::indxtype& indx) {
  return 2 * indx + 1;
}


template<class T>
typename pq<T>::indxtype pq<T>::rightChildIndx(const pq<T>::indxtype& indx) {
  return 2 * indx + 2;
}


template<class T>
typename pq<T>::indxtype pq<T>::parentIndx(const pq<T>::indxtype& indx) {
  return ( indx - 1 ) / 2;
}


template<class T>
inline bool pq<T>::indxIn(const pq<T>::indxtype& indx) {
  return indx >= 0 && indx < this->d_size;
}


template<class T>
void pq<T>::pushDown(const pq<T>::indxtype& indx) {
  pq<T>::indxtype lindx = leftChildIndx(indx);
  pq<T>::indxtype rindx = rightChildIndx(indx);
  
  if ( indxIn(lindx) && d_data[indx] < d_data[lindx] ) {
    std::swap(d_data[indx], d_data[lindx]);
    pushDown(lindx);
  }
  
  if ( indxIn(rindx) && d_data[indx] < d_data[rindx] ) {
    std::swap(d_data[indx], d_data[rindx]);
    pushDown(rindx);
  }
}

template<class T>
void pq<T>::popUp(const pq<T>::indxtype& indx) {
  pq<T>::indxtype pindx = parentIndx(indx);
  
  if ( indxIn(pindx) && d_data[indx] > d_data[pindx] ) {
    std::swap(d_data[indx], d_data[pindx]);
    popUp(pindx);
    
    indxtype rindx = rightChildIndx(indx);
    pushDown(pindx);
  }
}


template<class T>
void pq<T>::dump() {
  std::cout << "Dump prio_q: ";
  std::cout << "size: " << this->d_size << " ";
  std::cout << "cap: " << this->d_cap;
  std::cout << std::endl;
  std::cout << "data: ";
  for(indxtype i = 0; i < this->d_size; ++i) {
    std::cout << d_data[i] << " ";
  }
  std::cout << std::endl;
}



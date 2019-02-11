#ifndef PG
#define PG

#include <vector>

template <class T>
class pq {
public:
  using indxtype = typename std::vector<T>::size_type;
 
public:
  pq(): d_size(0), d_cap(10) {
    d_data.resize(10);
  }
  
  ~pq();
  
  void push(const T& data);
  void pop();
  
  T peek();
  
  void dump();
  
private:
  void resize();
 
  indxtype leftChildIndx(const indxtype& indx);
  indxtype rightChildIndx(const indxtype& indx);
  indxtype parentIndx(const indxtype& indx);
  
  inline bool indxIn(const indxtype& indx);
  
  void pushDown(const indxtype& indx);
  void popUp(const indxtype& indx);
  
   
private:
  indxtype d_size;
  indxtype d_cap;
  
  std::vector<T> d_data;
  
};

template class pq<int>;

#endif
  
#include "sll.h"

#include <cstdio>
#include <vector>

class dequeue_list {

public:
  dequeue_list() : d_head(0), d_tail(0), d_size(0) {}
  
  ~dequeue_list() {
    clear();
  }
  
  void clear();
  
  bool insertFront(const int& data);
  
  int removeFront();
  
  bool insertLast(const int& data);
  
  int removeLast();
  
  int peekFront();
  
  int peekLast();
  
  void showDequeue();
  
  void showData();
  
private:
  bool isEmpty();
  
  bool insertFirst(const int& data);
  
private:
  node* d_head;
  node* d_tail;
  size_t d_size;
};

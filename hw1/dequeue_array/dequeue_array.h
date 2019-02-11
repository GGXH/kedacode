#include <cstdio>
#include <vector>

class dequeue_array {

public:
  dequeue_array() : d_size(0), d_capability(10), d_start(0), d_end(0) {
    d_data = new std::vector<int>(d_capability);
  }
  
  ~dequeue_array() {
    delete d_data;
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
  size_t indexBefore(size_t indx);
  
  size_t indexAfter(size_t indx);
  
  bool isFull();
    
  bool isEmpty();
  
  void doubleSize();
  
private:
  std::vector<int>* d_data;
  size_t d_size;
  size_t d_capability;
  size_t d_start;
  size_t d_end;
};

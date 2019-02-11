#include "dequeue_array.h"

#include <iostream>

int main() {
  dequeue_array* da = new dequeue_array();
  
  da->insertFront(10);
  da->insertLast(1);
  da->insertFront(20);
  da->insertLast(2);
  
  da->showDequeue();
  da->showData();
  
  for(int i = -10; i < 100; ++i) {
    da->insertFront(i);
  }
  
  da->showDequeue();
  da->showData();
  
  da->clear();
  
  std::cout << "cleared dequeue" << std::endl;
  
  da->showDequeue();
  da->showData();
  
  for(int i = -10; i < 100; ++i) {
    da->insertFront(i);
  }
  
  da->showDequeue();
  da->showData();
}
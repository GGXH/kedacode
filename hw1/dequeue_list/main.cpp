#include "dequeue_list.h"

#include <iostream>

int main() {
  dequeue_list* da = new dequeue_list();
  
  da->insertFront(10);
  da->insertLast(1);
  da->insertFront(20);
  da->insertLast(2);
  
  da->showDequeue();
  
  for(int i = -10; i < 100; ++i) {
    da->insertFront(i);
  }
  
  da->showDequeue();
  
  da->clear();
  
  std::cout << "cleared dequeue" << std::endl;
  
  da->showDequeue();
  
  for(int i = -10; i < 100; ++i) {
    da->insertFront(i);
  }
  
  da->showDequeue();
}
#include "pq.h"

#include <iostream>
#include <vector>

int main() {
  pq<int>* prio_q = new pq<int>();
  
  std::vector<int> data{1, 5, 4, 3, 6, 2, 10, 11, 12, 2, 3, 4};
   
  for(auto& it : data) {
    std::cout << "push " << it << std::endl;
    prio_q->push(it);
  }
  
  prio_q->dump();
  
  std::cout << "start to pop" << std::endl;
   
  for(auto& it : data) {
    std::cout << prio_q->peek() << std::endl;
    prio_q->pop();
    prio_q->dump();
  }
}
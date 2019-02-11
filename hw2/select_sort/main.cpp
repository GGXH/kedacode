#include "select_sort.h"

#include <iostream>
#include <vector>

int main() {
  std::vector<int> data = {4, 3, 5, 6, 1, 2, 9, 7, 10};
   
  for(auto& it : data) {
    std::cout << it << " ";
  }
  
  std::cout << std::endl;
  
  select_sort<int>::sort1(data.begin(), data.end());
   
  std::cout << "after sorting: ";
   
  for(auto& it : data) {
    std::cout << it << " ";
  }
  
  std::cout << std::endl;
}
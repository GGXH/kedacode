#include <algorithm>
#include <iostream>
#include <vector>

int trappingwater(const std::vector<int>& input) {
  if ( input.size() < 3 ) return 0;
  
  std::vector<int>::size_type start = 0;
  std::vector<int>::size_type end = input.size() - 1;
  
  int left_max = 0;
  int right_max = 0;
  
  int res = 0;
  
  while ( start < end ) {
    if ( right_max >= left_max ) {
      if ( input[start] > left_max ) {
        left_max = input[start];
      } else {
        res += left_max - input[start];
      }
      ++start;
    } else {
      if ( input[end] > right_max ) {
        right_max = input[end];
      } else {
        res += right_max - input[end];
      }
      --end;
    }
  }
  return res;
}

int main() {
  std::vector<int> input{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  
  std::cout << trappingwater(input) << std::endl;
  
  return 0;
}
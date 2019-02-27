#include <iostream>
#include <vector>

int removeAdjacentDup(std::vector<int>& input) {
  if ( input.size() <= 1 ) return input.size();
  
  std::vector<int>::size_type end = 0;
  std::vector<int>::size_type curr = 1;
  for ( ; curr < input.size(); ++curr) {
    if ( input[curr] != input[end] ) {
      ++end;
      if ( curr != end ) {
       input[end] = input[curr];
      }
    }
  }
  return end + 1;
}

int main() {
  std::vector<int> input{1, 1, 1, 2, 2, 3, 3, 1};
  
  int res = removeAdjacentDup(input);
  
  std::cout << res << std::endl;
  for (auto i = 0; i < res; ++i) {
    std::cout << input[i] << " ";
  }
  std::cout << std::endl;
}
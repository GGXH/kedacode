#include <iostream>
#include <vector>

int removeAllDup(std::vector<int>& input) {
  if ( input.size() < 2 ) return input.size();
   
  int end = -1;
  std::vector<int>::size_type curr = 1;
  bool dup = false;
  for ( ; curr < input.size(); ++curr) {
    if ( input[curr] == input[curr-1] ) {
      dup = true;
    } else {
      if ( !dup ) {
        ++end;
        input[end] = input[curr-1];
      }
      dup = false;
    }
  }
  
  if ( !dup ) {
    ++end;
    input[end] = input[input.size() - 1];
  }
  
  return end + 1;
}

int main() {
  std::vector<int> input{1, 1, 1, 2, 2, 3, 3, 3, 1};
  
  int res = removeAllDup(input);
  
  std::cout << res << std::endl;
  for (auto i = 0; i < res; ++i) {
    std::cout << input[i] << " ";
  }
  std::cout << std::endl;
}
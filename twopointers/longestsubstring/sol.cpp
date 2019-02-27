#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int longestSubString(std::string& input) {
  std::vector<int> lib(256, -1);
  
  std::string::size_type start = 0;
  std::string::size_type end = 0;
  std::string::size_type max_length = 1;
   
  for (; end < input.size(); ++end) {
    std::string::size_type indx = input[end] - 'a';
    if ( lib[indx] >= start ) {
      start = lib[indx] + 1;
    }
    lib[indx] = end;
    std::cout << input[end] << " " << start << " " << end << std::endl;
    max_length = std::max(max_length, end - start + 1);
  }
  return max_length;
}

int main() {
  std::string str = "abcabcbb";
   
  std::cout << longestSubString(str) << std::endl;
}

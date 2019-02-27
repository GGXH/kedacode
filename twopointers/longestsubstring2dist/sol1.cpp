#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int longestSubString2dist(std::string& input, int& k) {
  std::vector<int> lib(256, 0);
  
  std::string::size_type start = 0;
  std::string::size_type end = 0;
  std::string::size_type max_length = 1;
  int count = 0;
   
  for (; end < input.size(); ++end) {
    if ( lib[input[end]] == 0 ) ++count;
    ++lib[input[end]];
    
    while ( count > k ) {
      if ( lib[input[start]] == 1 ) --count;
      --lib[input[start]];
      ++start;
    }
    max_length = std::max(max_length, end - start + 1);
  }
  return max_length;
}

int main() {
  std::string str = "abcabcbb";
   
  int k = 2;
  std::cout << longestSubString2dist(str, k) << std::endl;
}

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

int longestSubString2dist(std::string& input, int& k) {
  std::unordered_map<char, int> lib;
  
  std::string::size_type start = 0;
  std::string::size_type end = 0;
  std::string::size_type max_length = 1;
   
  for (; end < input.size(); ++end) {
    std::unordered_map<char, int>::iterator it = lib.find(input[end]);
    if ( lib.size() == k && it == lib.end() ) {
      char min_char;
      int min_end = input.size();
      for (auto& it : lib) {
        if ( it.second < min_end ) {
          min_end = it.second;
          min_char = it.first;
        }
      }
      lib.erase(min_char);
      start = min_end + 1;
    }
    lib[input[end]] = end;
    max_length = std::max(max_length, end - start + 1);
  }
  return max_length;
}

int main() {
  std::string str = "abcabcbb";
   
  int k = 3;
  std::cout << longestSubString2dist(str, k) << std::endl;
}

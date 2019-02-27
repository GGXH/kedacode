#include <iostream>
#include <string>

int isPal(const std::string& input, int left, int right) {
  while ( left >= 0 && right < input.size() && input[left] == input[right] ) {
    --left;
    ++right;
  }
  
  if ( input[left] != input[right] ) {
    ++left;
    --right;
  }
  
  return right - left + 1;
}

std::string longestPal(const std::string& input) {
  if ( input.size() < 2 ) return input;
  
  int max_len = 0;
  int max_left;
  int max_right;
  
  for (std::string::size_type i = 0; i < input.size(); ++i) {
    int len = isPal(input, i, i + 1);
    if ( max_len < len ) {
      max_len = len;
      max_left = i - len / 2 + 1;
      max_right = i + len / 2;
    }
    
    len = isPal(input, i, i + 2);
    if ( max_len < len ) {
      max_len = len;
      max_left = i - ( len- 1 ) / 2 + 1;
      max_right = i + ( len - 1 ) / 2 + 1;
    }
  }
  
  return input.substr(max_left, max_right);
}


int main() {
  std::string str = "aabbbaccc";
   
  std::cout << longestPal(str) << std::endl;
  
  return 0;
}


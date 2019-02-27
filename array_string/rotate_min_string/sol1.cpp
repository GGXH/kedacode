#include <iostream>
#include <string>


std::string::size_type rotate_min_string(const std::string& str) {
  std::string input = str + str;
   
  std::string::size_type min_indx = 0;
  
  for (std::string::size_type i = 1; i < input.size(); ++i) {
    std::string::size_type curr = i;
    int diff = 0;
    for (std::string::size_type j = min_indx;diff == 0 &&  j < i && curr < input.size(); ++j, ++curr) {
      diff = input[curr] - input[j];
    }
    if ( diff < 0 ) {
      min_indx = i;
    }
  }
  return min_indx;
}


int main() {
  std::string str;
  
  while ( std::cin >> str ) {
    std::cout << str << " " << rotate_min_string(str) << std::endl;
  }
  
  return 0;
}

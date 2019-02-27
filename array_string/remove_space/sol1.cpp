
#include <iostream>
#include <string>


std::string leave1space(std::string &input) {
  int end = -1;
  int cur = 0;
  
  while ( cur < input.size() ) {
    if ( input[cur] != ' ' ) {
      ++end;
      if ( cur != end ) {
        input[end] = input[cur];
      }
    } else {
      if ( end >= 0 && input[end] != ' ' ) {
        ++end;
        if ( end != cur ) {
          input[end] = input[cur];
        }
      }
    }
    ++cur;
    
    std::cout << input << cur << end << std::endl;
  }
  
  return input.substr(0, end + 1);
}


int main() {
  std::string str;
  
  while (std::getline(std::cin, str)) {
    std::cout << leave1space(str) << std::endl;
  }
  return 0;
}


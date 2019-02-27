#include <algorithm>
#include <iostream>
#include <string>

int main() {
  std::string str;
  while ( std::cin >> str ) {
    sort(str.begin(), str.end());
    std::cout << str << std::endl;
  }
  
  return 0;
}
  
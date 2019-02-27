#include <iostream>
#include <string>
#include <vector>

int minwindsubstr(const std::string& S, const std::string& P)
{
   std::vector<int> lib(256, 0);
    
   for(auto& c : P) {
     ++lib[c];
   }
   
   int start = 0;
   int end = 0;
   int count = P.size();
   
   int min_len = S.size();
   
   while ( start < S.size() - P.size() ) {
     if ( count > 0 && end < S.size() ) {
       --lib[S[end]];
       if ( lib[S[end]] >= 0 ) {
         --count;
       }
       ++end;
     } else {
       ++lib[S[start]];
       if ( lib[S[start]] > 0 ) {
         ++count;
       }
       ++start;
     }
     
     if (count == 0 && min_len > end - start) {
       min_len = end - start;
     }
   }
   
   return min_len;
}

int main() {
  std::string S = "adobecodebanc";
  std::string P = "abca";
   
  std::cout << minwindsubstr(S, P) << std::endl;
   
  return 0;
}
   
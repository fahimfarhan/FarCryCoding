#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countVowelStrings(int n) {
      int result = 0;
      a = 1; e = 1; i = 1; o = 1; u = 1;
      while(n--) {
        increment();
      }
      result = a + e + i + o + u;
      return result;
    }

  private:
    int a, e, i, o, u;

    void increment() {
      a = a + e + i + o + u;
      e = e + i + o + u;
      i = i + o + u;
      o = o + u;
      // u = u;
    }
};

int main() {
  Solution s;
  cout<<s.countVowelStrings(1)<<"\n";
  cout<<s.countVowelStrings(5)<<"\n";
  cout<<s.countVowelStrings(10)<<"\n";
  cout<<s.countVowelStrings(20)<<"\n";
  cout<<s.countVowelStrings(100)<<"\n";
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    // base case: pattern is empty
    if (p.empty()) {
      return s.empty();
    }

    bool firstMatch = false;

    if (!s.empty()) {
      firstMatch = (s[0] == p[0]) || (p[0] == '.');
    }

    if ((p.length() >= 2) && (p[1] == '*')) {

      bool b1 = isMatch(s, p.substr(2));
      bool b2 = firstMatch && (isMatch(s.substr(1), p));

      return b1 || b2;
    } else {
      return firstMatch && isMatch(s.substr(1), p.substr(1));
    }

    return false;
  }
};

int main(int argc, char *argv[]) { return 0; }

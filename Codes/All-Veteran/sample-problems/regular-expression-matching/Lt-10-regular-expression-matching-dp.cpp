#include <bits/stdc++.h>
#include <cstring>
using namespace std;

#define TRUE 1
#define FALSE 0
#define NOT_INIT -1

class Solution {
private:
  int **memo = nullptr;

public:
  void preprocess(int sSize, int pSize) {
    memo = new int *[sSize + 1];
    for (int i = 0; i < sSize + 1; i++) {
      memo[i] = new int[pSize + 1];
      memset(memo[i], -1, sizeof(int) * (pSize + 1));
      // this is the correct way to init the array
    }
  }

  bool isMatch(string s, string p) {
    // CASE 1: PATTERN = ""
    if (p.empty()) {
      return s.empty();
    }
    // case 2: first character match

    bool firstMatch = false;
    if (!s.empty()) {
      firstMatch = ((s[0] == p[0]) || (p[0] == '.'));
    }

    // case 3: next character match

    if (p.size() >= 2 && p[1] == '*') {
      bool b1 = firstMatch && isMatch(s.substr(1), p);
      bool b2 = isMatch(s, p.substr(2));
      return (b1 || b2);
    } else {
      return firstMatch && isMatch(s.substr(1), p.substr(1));
    }

    return FALSE;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  s.preprocess(5, 5);
  return 0;
}

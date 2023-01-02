#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool detectCapitalUse(string word) {
    int N = word.size();
    char ch = '\0';

    int upperCaseCount = 0, lowerCaseCount = 0;

    for (int i = 0; i < N; i++) {
      if (('A' <= word[i]) && (word[i] <= 'Z')) {
        upperCaseCount++;
      } else if (('a' <= word[i]) && (word[i] <= 'z')) {
        lowerCaseCount++;
      }
    }

    if (upperCaseCount == N) {
      return true;
    }
    if (lowerCaseCount == N) {
      return true;
    }
    if (('A' <= word[0]) && (word[0] <= 'Z') && (lowerCaseCount == (N - 1))) {
      return true;
    }
    return false;
  }
};

int main(int argc, char *argv[]) { return 0; }

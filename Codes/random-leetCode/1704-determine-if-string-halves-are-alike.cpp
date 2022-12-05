#include <bits/stdc++.h>
#include <cctype>
using namespace std;

class Solution {
public:
  bool halvesAreAlike(string s) {
    int N = s.size();
    int m = N / 2;

    int vowels[26] = {0};
    vowels[('a' - 'a')] = 1;
    vowels[('e' - 'a')] = 1;
    vowels[('i' - 'a')] = 1;
    vowels[('o' - 'a')] = 1;
    vowels[('u' - 'a')] = 1;

    int a = 0, b = 0;
    char ch = '\0';
    for (int i = 0; i < m; i++) {
      ch = tolower(s[i]);
      if (vowels[ch - 'a']) {
        a++;
      }
    }

    for (int i = m; i < N; i++) {
      ch = tolower(s[i]);
      if (vowels[ch - 'a']) {
        b++;
      }
    }

    return a == b;
  }
};

int main(int argc, char *argv[]) { return 0; }

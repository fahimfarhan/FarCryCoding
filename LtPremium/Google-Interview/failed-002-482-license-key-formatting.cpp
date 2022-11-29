#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string licenseKeyFormatting(string s, int k) {
    string output = "";
    int N = s.size();
    int m = k;

    for (int i = N - 1; i >= 0; i--) {
      if (s[i] == '-') {
        continue;
      } else if ('a' <= s[i] && s[i] <= 'z') {
        output = (char)(s[i] - 'a' + 'A') + output;
      } else {
        output = s[i] + output;
      }
    }

    N = output.size();
    int r = N % k;
    if (r == 0) {
      r = k;
    }
    // r - k - k - ... - k
    string temp = output.substr(0, r);
    for (int i = r; i < N; i += k) {
      temp += ("-" + output.substr(i, k));
    }
    return temp;
  }
};

int main() { return 0; }

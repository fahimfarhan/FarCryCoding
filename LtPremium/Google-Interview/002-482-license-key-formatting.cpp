#include <bits/stdc++.h>
#include <cctype>
using namespace std;

class Solution {
public:
  string licenseKeyFormatting(string s, int k) {
    string output = "";
    int N = s.size();

    int temp = k;
    for (int i = N - 1; i >= 0; i--) {
      if (s[i] != '-') {
        output += toupper(s[i]);

        temp--;
        if (temp == 0) {
          output += "-";
          temp = k;
        }
      }
    }

    if ((output.size() > 0) && (output.back() == '-')) {
      output.pop_back();
    }

    reverse(output.begin(), output.end());

    return output;
  }
};

int main() { return 0; }

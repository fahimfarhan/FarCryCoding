#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string gcdOfStrings(string str1, string str2) {

    if ((str1 + str2) != (str2 + str1)) {
      return "";
    }

    int gcdLength = __gcd(str1.length(), str2.length());
    string gcdString = str1.substr(0, gcdLength);

    return gcdString;
  }
};

int main(int argc, char *argv[]) { return 0; }

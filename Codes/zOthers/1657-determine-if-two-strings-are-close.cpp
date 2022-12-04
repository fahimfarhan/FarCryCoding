#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool closeStrings(string word1, string word2) {

    int n1 = word1.size();
    int n2 = word2.size();

    if (n1 != n2) {
      return false;
    }

    int f1[26] = {0};
    int f2[26] = {0};

    int m = 0;
    for (int i = 0; i < n1; i++) {
      m = (word1[i] - 'a');
      f1[m]++;
    }

    for (int i = 0; i < n2; i++) {
      m = (word2[i] - 'a');
      f2[m]++;
    }

    // condition 1: check if both array have zeroes in same places
    bool closeStr = true;

    for (int i = 0; i < 26; i++) {
      if (((f1[i] == 0) && (f2[i] == 0)) || ((f1[i] != 0) && (f2[i] != 0))) {
        closeStr = true;
      } else {
        closeStr = false;
        break;
      }
    }

    if (!closeStr) {
      return closeStr;
    }

    sort(f1, f1 + 26);
    sort(f2, f2 + 26);

    for (int i = 0; i < 26; i++) {
      if (f1[i] != f2[i]) {
        closeStr = false;
        break;
      }
    }

    return closeStr;
  }
};

int main(int argc, char *argv[]) { return 0; }

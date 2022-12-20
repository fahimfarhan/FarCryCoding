#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    // unordered_map<char, int> mp;
    int mp[200] = {0};

    int left = 0, right = 0;

    int maximus = 0; // INT_MIN;

    int chLeft = 0, chRight = 0;

    while (right < s.size()) {
      chRight = s[right];
      mp[chRight]++;

      while (mp[chRight] > 1) {
        chLeft = s[left];
        mp[chLeft]--;
        left++;
      }
      maximus = max(maximus, (right - left + 1));
      right++;
    }
    return maximus;
  }
};

int main(int argc, char *argv[]) { return 0; }

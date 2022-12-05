#include <bits/stdc++.h>
#include <cstring>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {

    if (s.size() == 0) {
      return 0;
    }

    int mp[300];
    memset(mp, -1, sizeof(int) * 300);

    // cerr << "\n";

    int i = 0, N = s.size();
    int maximus = INT_MIN;

    int start = 0, end = 0;
    while (i < N) {
      if (mp[(int)s[i]] != -1) {
        // we've found a new subString!
        /*
        s[start]... ...(s[i-1] = s[end]) has no repeatation,
        */
        // cerr << "start = " << start << ", end = " << end << "\n";
        int temp = end - start + 1;
        maximus = max(maximus, temp);
        /*
         * let s[i] = 'j';
         * mp['j' - 'a'] = k;
         * therefore, s[k] = 'j';
         *
         * s[start]...s[k] should be reset to -1,
         *
         * new start = k + 1;
         * */
        int k = mp[(int)s[i]];
        for (int ii = start; ii <= k; ii++) {
          mp[ii] = -1;
        }
        start = k + 1;
      }
      end = i;
      mp[(int)s[i]] = i;
      i++;
    }

    // the last one may have been missed, so,
    int temp = end - start + 1;
    maximus = max(maximus, temp);

    return maximus;
  }
};

int main(int argc, char *argv[]) {
  string t = "abcabcbb";
  Solution s;
  cout << s.lengthOfLongestSubstring(t) << "\n";

  cout << s.lengthOfLongestSubstring("abba") << "\n";
  return 0;
}

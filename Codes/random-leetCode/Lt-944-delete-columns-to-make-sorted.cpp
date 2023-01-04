#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minDeletionSize(vector<string> &strs) {
    if (strs.size() == 0) {
      return 0;
    }
    int n, m;
    n = strs.size();
    m = strs[0].size();

    int kount = 0;
    for (int i = 0; i < m; i++) {
      // cerr << "-----------\ni = " << i << "\n";
      for (int j = 1; j < n; j++) {
        // cerr << "j = " << j << "\n";
        // cerr << strs[j - 1][i] << " " << strs[j][i] << "\n";
        if (strs[j - 1][i] > strs[j][i]) {
          kount++;
          break;
        }
      }
    }
    return kount;
  }
};

int main(int argc, char *argv[]) {
  vector<string> v1 = {"b", "a", "h"};
  vector<string> v = {"cba", "daf", "ghi"};
  Solution s;
  cout << s.minDeletionSize(v) << "\n";
  return 0;
}

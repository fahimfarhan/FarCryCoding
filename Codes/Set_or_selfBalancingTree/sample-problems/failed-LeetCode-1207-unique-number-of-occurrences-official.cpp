#include <array>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
  bool uniqueOccurrences(vector<int> &arr) {
    int N = arr.size();
    int f[2005];

    for (int i = 0; i < 2005; i++) {
      f[i] = 1000005;
    }

    int m = 0;
    for (auto n : arr) {
      m = n + 1000;
      if (f[m] == 1000005) {
        f[m] = 1;
      } else {
        f[m]++;
      }
    }

    sort(f, f + 2005);

    bool unique = true;
    for (int i = 0; i < N - 1; i++) {
      if (f[i] == f[i + 1]) {
        unique = false;
        break;
      }
    }

    return unique;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> v = {1, 2, 2, 1, 1, 3};
  cout << s.uniqueOccurrences(v) << "\n";
  return 0;
}

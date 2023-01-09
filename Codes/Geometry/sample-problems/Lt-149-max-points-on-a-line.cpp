#include <bits/stdc++.h>
#include <cmath>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int maxPoints(vector<vector<int>> &points) {
    int n = points.size();

    if (n <= 1) {
      return n;
    }

    unordered_map<double, int> mp;

    int maximus =
        2; // INT_MIN; hmm, another corner case. should have seen that before!
    double angle = 0;
    // don't use slope as they may be prone to precision loss...
    int dx = 0, dy = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i != j) {
          dx = points[i][0] - points[j][0];
          dy = points[i][1] - points[j][1];

          angle = atan2(dy, dx);

          mp[angle]++;
        }
      }

      for (auto e : mp) {
        maximus = max(maximus, e.second + 1);
      }

      mp.clear(); // else our counts will be doubled...
    }

    return maximus;
  }
};

int main(int argc, char *argv[]) { return 0; }

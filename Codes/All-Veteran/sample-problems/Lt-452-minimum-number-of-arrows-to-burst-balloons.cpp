#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  static bool comparator(const vector<int> &a, const vector<int> &b) {
    return a[1] < b[1];
  }

public:
  int findMinArrowShots(vector<vector<int>> &points) {
    sort(points.begin(), points.end(), comparator);

    int arrow = 1;

    int xStart = 0, xEnd = 0, currEnd = points[0][1];

    for (auto p : points) {
      xStart = p[0];
      xEnd = p[1];

      if (xStart <= currEnd) {
        // our existing arrows will burst the balloon
      } else {
        // our existing arrows won't burst this balloon. Hence we need a new
        // arrow
        arrow++;
        // update currentEnd, because this is the last balloon so far
        currEnd = xEnd;
      }
    }

    return arrow;
  }
};
int main(int argc, char *argv[]) { return 0; }

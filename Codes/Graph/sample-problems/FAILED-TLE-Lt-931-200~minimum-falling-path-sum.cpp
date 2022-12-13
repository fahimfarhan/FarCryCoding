#include <bits/stdc++.h>
#include <climits>
using namespace std;

/**
 * SPDX-License-Identifier: CC-BY-4.0
 * @author fahimfarhan
 */
#define INF 5000

class Solution {
private:
  int N = 0;
  int END = 0;

  int minimus = 0;

  bool validCell(const int &i, const int &j) {
    if (i < 0) {
      return false;
    }
    if (i >= N) {
      return false;
    }
    if (j < 0) {
      return false;
    }
    if (j >= N) {
      return false;
    }

    return true;
  }

  void backtrack(vector<vector<int>> &matrix, const int &i, const int &j,
                 int &sum) {
    // cerr << "i = " << i << ", j = " << j << ", sum = " << sum << "\n";
    sum += matrix[i][j];

    if (i == END) { // END = N - 1
      // the lowest level is reached
      minimus = min(minimus, sum);
      // cerr << "minimus " << minimus << "\n";
      sum -= matrix[i][j];
      return;
    }

    int j1 = 0;
    int i1 = i + 1;
    for (int k = 0; k < 3; k++) {
      j1 = j + k - 1;
      if (validCell(i1, j1)) {
        backtrack(matrix, i1, j1, sum);
      }
    }
    sum -= matrix[i][j];
  }

public:
  int minFallingPathSum(vector<vector<int>> &matrix) {
    N = matrix.size();
    END = N - 1;
    minimus = INT_MAX;
    int sum = 0;
    for (int i = 0; i < N; i++) {
      backtrack(matrix, 0, i, sum);
    }
    return minimus;
  }
};

int main(int argc, char *argv[]) {

  vector<vector<int>> v;
  // [-19,57],[-40,-5]]
  v.push_back({-19, 57});
  v.push_back({-40, -5});

  Solution s;
  cout << s.minFallingPathSum(v) << "\n";

  v.clear();
  v.push_back({2, 1, 3});
  v.push_back({6, 5, 4});
  v.push_back({7, 8, 9});

  cout << s.minFallingPathSum(v) << "\n";

  return 0;
}

#include <bits/stdc++.h>
#include <climits>
#include <cstring>
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

  int memo[201][201];

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

  int backtrack(vector<vector<int>> &matrix, const int &i, const int &j) {
    if (memo[i][j] != INT_MAX) {
      return memo[i][j];
    }

    if (i == END) { // END = N - 1
      // the lowest level is reached
      return memo[i][j] = matrix[i][j];
    }

    int j1 = 0;
    int i1 = i + 1;

    int minimus = INT_MAX;

    int temp = 0;

    for (int k = 0; k < N; k++) {
      j1 = k; // j + k - 1;
      if (j1 != j) {
        if (validCell(i1, j1)) {
          temp = matrix[i][j] + backtrack(matrix, i1, j1);
          minimus = min(temp, minimus);
        }
      }
    }
    return memo[i][j] = minimus;
  }

public:
  int minFallingPathSum(vector<vector<int>> &matrix) {
    N = matrix.size();
    END = N - 1;
    int minimus = INT_MAX;
    int sum = 0;

    for (int i = 0; i < 101; i++) {
      for (int j = 0; j < 101; j++) {
        memo[i][j] = INT_MAX;
      }
    }

    for (int i = 0; i < N; i++) {
      minimus = min(minimus, backtrack(matrix, 0, i));
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

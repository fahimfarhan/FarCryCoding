#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

const int CALCULATED_IMPOSSIBLE = -2;

class Solution {
private:
  unordered_map<int, int> dp;
  vector<int> squares;

  void preprocess(int n) {
    int temp = 0;
    int m = ceil(sqrt(n));
    for (int i = 1; i <= m; i++) {
      temp = i * i;
      dp[temp] = 1;
      squares.push_back(temp);
    }
  }

public:
  void destructor() {
    dp.clear();
    squares.clear();
  }

  int numSquares(int n) {
    preprocess(n);
    return f(n);
  }

  int f(int n) {
    // base case
    if (n <= 0) {
      return CALCULATED_IMPOSSIBLE;
    }

    if (dp.find(n) != dp.end()) {
      // cerr << "returning from start" << "\n";
      return dp[n];
    }

    int startIndex =
        lower_bound(squares.begin(), squares.end(), n) - squares.begin();

    int m = 0, kount = 0;
    int minimus = INT_MAX;
    for (int i = startIndex; i >= 0; i--) {
      m = n - squares[i];
      kount = f(m);

      if (kount >= 0) {
        minimus = min(minimus, kount + 1);
        // kount_for_m + 1_for_already_taken_square[i],
        // ie, n =  square[i] + n1 + n2 + ... + nkount
      }
    }

    // recursive case
    dp[n] = minimus;
    // cerr << "returning from end";
    return dp[n];
  }

  // I haven't the faintest idea how to solve it. let's start from recursion
};

int main() {
  Solution s;
  cout << s.numSquares(12) << "\n";
  s.destructor();
  cout << s.numSquares(13) << "\n";
  return 0;
}

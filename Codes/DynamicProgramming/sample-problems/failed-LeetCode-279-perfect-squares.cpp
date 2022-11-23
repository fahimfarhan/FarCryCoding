#include <bits/stdc++.h>
#include <cstring>
using namespace std;

class Solution {

private:
  // int dp[10005] = {-1};
  int *squares = nullptr;
  int size = 0;
  int N = 0;

  void preprocess() {
    // memset(dp, -1, sizeof(dp));

    size = ceil(sqrt(N));
    squares = new int[size + 10];

    int temp = 0;

    for (int i = 0; i < size; i++) {
      temp = i * i;
      squares[i] = temp; //  i * i;
      // dp[temp] = 1;
    }

    for (int i = 0; i < 10; i++) {
      squares[i + size] = INT_MAX;
    }
  }

  void destructor() {
    if (squares != nullptr) {
      delete[] squares;
    }
  }

public:
  int numSquares(int n) {
    this->N = n;
    preprocess();
    auto p = f(n, 0);
    destructor();
    if (!p.first)
      return 0;
    return p.second;
  }

  pair<bool, int> f(int n, int kount) {
    pair<bool, int> ret = {false, INT_MAX};
    // base case
    //
    //
    if (n < 0) {
      return ret;
    }
    int startIndex = lower_bound(squares, squares + size, n) - squares;

    for (int i = startIndex; i >= 0; i--) {
      if (squares[i] == n) {
        // base case
        return {true, kount + 1};
      } else if (squares[i] < n) {
        // recursive case
        auto p = f((n - squares[i]), (kount + 1));
        if (p.first == true) {
          ret.first = true;
          if (p.second < ret.second) {
            ret.second = p.second;
          }
        }
      }
    }

    return ret;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  Solution s;
  cout << s.numSquares(12) << "\n";
  cout << s.numSquares(1) << "\n";
  cout << s.numSquares(10) << "\n";

  return 0;
}

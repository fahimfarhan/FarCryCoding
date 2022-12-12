#include <bits/stdc++.h>
#include <cstring>
using namespace std;

class Solution {
private:
  int *memo = nullptr;

public:
  int climbStairs(int n) {
    memo = new int[n + 1];
    memset(memo, -1, sizeof(int) * (n + 1));

    int result = dp(n);

    delete[] memo;
    memo = nullptr;

    return result;
  }

  int dp(int n) {
    if (memo[n] != -1) {
      return memo[n];
    }

    if (n <= 0) {
      return 0;
    }
    if (n == 1) {
      return memo[n] = 1;
    }
    if (n == 2) {
      return memo[n] = 1 /* _ _ 2 small(one) steps */
                       + /* or */
                       1 /* __ one big (two) step */;
      /* so total 2 different ways. don't confuse with how many steps */
    }
    return memo[n] = dp(n - 1) + dp(n - 2);
  }
};

int main(int argc, char *argv[]) { return 0; }

#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

#define ll int32_t
class Solution {

private:
  ll memo[40];

public:
  Solution() {
    memset(memo, -1, sizeof(ll) * 40);
    tribonacci(37);
  }

  ll tribonacci(ll n) { return dp(n); }

  ll dp(ll n) {
    if (n < 0) {
      return 0;
    }

    if (memo[n] != -1) {
      return memo[n];
    }

    if (n == 0) {
      return memo[n] = 0;
    }
    if (n == 1 || n == 2) {
      return memo[n] = 1;
    }

    return memo[n] = dp(n - 1) + dp(n - 2) + dp(n - 3);
  }
};

int main(int argc, char *argv[]) {

  Solution s;
  for (int i = 0; i < 39; i++) {
    cout << i << "  " << s.tribonacci(i) << "\n";
  }

  return 0;
}

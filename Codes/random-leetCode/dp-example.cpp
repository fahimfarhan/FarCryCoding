#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      int result = 0;
      vector<int> dp(amount+1, -2);
      dp[0] = 0;

      result = f(amount, coins, dp);

      return result;
    }

    int f(int amount, const vector<int>& coins, vector<int>& dp) {
      if(amount < 0) {
        return -1;
      }

      if(dp[amount]>-2) {
        return dp[amount];
      }

      int minimus = INT_MAX;
      for(auto c: coins) {
        int temp = f(amount - c, coins, dp);
        if(temp >= 0) {
          minimus = min(minimus, temp);
        }
      }
      dp[amount] = (minimus == INT_MAX)? -1: (1+minimus);
      return dp[amount];
    }
};

int main() {

  return 0;
}
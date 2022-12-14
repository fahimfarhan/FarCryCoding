#include <bits/stdc++.h>
using namespace std;

/**
 * @author fahimfarhan
 * */
class Solution {
private:
  int memo[101];

public:
  int rob(vector<int> &nums) {
    memset(memo, -1, sizeof(int) * 101);
    int lastIndex = nums.size() - 1;

    return dp(nums, lastIndex);
  }

  int dp(vector<int> &nums, int n) {
    // base cases
    if (n < 0) {
      return 0;
    }

    if (memo[n] != -1) {
      return memo[n];
    }

    // case 1: I may steal from this nth house,
    int stealFromNthHouse = nums[n] + dp(nums, n - 2);
    // case 2: or I won't steal from nth house
    int dontStealFromNthHouse = dp(nums, n - 1);

    return memo[n] = max(stealFromNthHouse, dontStealFromNthHouse);
  }
};

int main(int argc, char *argv[]) { return 0; }

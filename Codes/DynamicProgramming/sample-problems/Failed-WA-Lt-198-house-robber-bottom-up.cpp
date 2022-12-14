#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  int memo[101];

public:
  int rob(vector<int> &nums) {
    memset(memo, -1, sizeof(int) * 101);

    // bottom up

    // base cases
    int N = nums.size();
    if (N == 0) {
      return 0;
    }

    if (N == 1) {
      memo[0] = nums[0];
    }

    if (N == 2) {
      memo[1] = max(nums[0], nums[1]);
    }

    for (int i = 2; i < N; i++) {

      // case 1: I may steal from this nth house,
      int stealFromNthHouse = nums[i] + memo[(i - 2)];
      // case 2: or I won't steal from nth house
      int dontStealFromNthHouse = memo[(i - 1)];
      memo[i] = max(stealFromNthHouse, dontStealFromNthHouse);
    }

    return memo[(N - 1)];
  }
};

int main(int argc, char *argv[]) { return 0; }

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  static const int MAX_N = 30005;
  int memo[MAX_N];

  int dp[10005];

public:
  Solution() {
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < 10005; i++) {
      dp[i] = dp[i - 1] + i;
    }
  }

  int subarraysDivByK(vector<int> &nums, int k) {
    int length0 = nums.size();
    int length1 = length0 + 1;

    int result = 0;

    memo[0] = 0;
    memo[1] = nums[0];
    for (int i = 1; i < length0; i++) {
      memo[i + 1] = memo[i] + nums[i];
    }

    for (int i = 0; i < length1; i++) {
      memo[i] %= k;
    }

    unordered_map<int, int> mp;

    for (int i = 1; i < length1; i++) {
      mp[memo[i]]++;
    }

    for (auto e : mp) {
      if (e.second > 1) {
        result += countV3(e.second);
      }
    }

    // int temp = 0;

    return result;
  }

  void v1() {
    /*
    for (int i = 1; i < length1; i++) {
      for (int j = i; j < length1; j++) {
        temp = memo[j] - memo[i - 1];
        if (temp % k == 0) {
          result++;
        }
      }
    }
    */
  }

  int countV3(int i) { return dp[i]; }

  int countV2(int x) {
    if (x <= 1) {
      return x;
    }

    return countV2(x - 1) + x;
  }

  int count(int x) { return ((x + 5) * x - 2) / 4; }
};

int main(int argc, char *argv[]) {

  Solution s;

  for (int i = 0; i < 10; i++) {
    cout << s.countV3(i) << "\n";
  }
  return 0;
}

/*
i
   1
o = 1
i {1, 2}
o  [1, 2, {1, 2}] = 3
i = {1, 2, 3}
o = [1, 2, 3, [1, 2], [2, 3], [1, 2, 3]] = 6
i = {1, 2, 3, 4}
o = [1, 2, 3, 4, [1,2], [2, 3], [3, 4], [1, 2, 3], [2, 3, 4], [1, 2, 3, 4]] = 10
 *
 *
 * 1 3 6 10 ... ...
 *  2 3 4
 *   1 1
 *
 *
 * */

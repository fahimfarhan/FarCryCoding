#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  static const int MAX_N = 30005;
  int memo[MAX_N];

public:
  int subarraysDivByK(vector<int> &nums, int k) {
    int length0 = nums.size();
    int length1 = length0 + 1;

    int result = 0;

    memo[0] = 0;
    memo[1] = nums[0];
    for (int i = 1; i < length0; i++) {
      memo[i + 1] = memo[i] + nums[i];
    }

    int temp = 0;
    for (int i = 1; i < length1; i++) {
      for (int j = i; j < length1; j++) {
        temp = memo[j] - memo[i - 1];
        if (temp % k == 0) {
          result++;
        }
      }
    }

    return result;
  }
};

int main(int argc, char *argv[]) { return 0; }

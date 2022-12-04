#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define SIZE_T 100005

class Solution {
  ll cf[SIZE_T];
  int avgDiff[SIZE_T];
  int N = 0;

  inline void preprocess(vector<int> &nums) {
    N = nums.size();
    // cf = new ll[N + 1];
    // avgDiff = new int[N + 1];

    // memset(avgDiff, 0, sizeof(int) * (N + 1));

    cf[0] = nums[0];

    for (int i = 1; i < N; i++) {
      cf[i] = nums[i] + cf[i - 1];
    }
  }

  /*
  inline void destructor() {
    if (cf != nullptr) {
      delete[] cf;
    }
    if (avgDiff != nullptr) {
      delete[] avgDiff;
    }

    cf = nullptr;
    avgDiff = nullptr;
    N = 0;
  }
  */

public:
  int minimumAverageDifference(vector<int> &nums) {
    preprocess(nums);

    int head = 0, tail = 0;

    int minimus = INT_MAX;
    int idx = -1;

    for (int i = 0; i < N; i++) {
      head = cf[i] / (i + 1); //  floor((cf[i] + 0.0) / (i + 1));
      int deno = N - i - 1;

      tail = 0;
      if (deno != 0) {
        tail = (cf[N - 1] - cf[i]) / deno;
      }

      avgDiff[i] = abs(head - tail);

      if (avgDiff[i] < minimus) {
        minimus = avgDiff[i];
        idx = i;
      }
    }

    // destructor();
    return idx;
  }
};

int main(int argc, char *argv[]) {

  vector<int> v1 = {2, 5, 3, 9, 5, 3};
  vector<int> v2 = {0};

  Solution s;
  cout << "Case #1: " << s.minimumAverageDifference(v1) << "\n";
  cout << "Case #2: " << s.minimumAverageDifference(v2) << "\n";

  return 0;
}

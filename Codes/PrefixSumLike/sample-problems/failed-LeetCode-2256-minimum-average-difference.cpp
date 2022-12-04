#include <bits/stdc++.h>
using namespace std;

class Solution {
  int *cf = nullptr;
  int *avgDiff = nullptr;
  int N = 0;

  inline void preprocess(vector<int> &nums) {
    N = nums.size();
    cf = new int[N + 1];
    avgDiff = new int[N + 1];

    // memset(cf, 0, sizeof(int) * (N + 1));
    memset(avgDiff, 0, sizeof(int) * (N + 1));

    cf[0] = nums[0];
    for (int i = 1; i < N; i++) {
      cf[i] = nums[i] + cf[i - 1];
    }
  }

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

public:
  int minimumAverageDifference(vector<int> &nums) {
    preprocess(nums);

    int head = 0, tail = 0;

    int minimus = INT_MAX;
    int idx = -1;

    cout << "\n";
    for (int i = 0; i < N; i++) {
      head = round((cf[i] + 0.0) / (i + 1));

      int j = N - i - 1;
      int nu = cf[N - 1] - cf[(N - j - 1)];
      int hi = N - 1;
      int lo = N - j - 1;

      // int deno = /* N - 1 - (N - i - 2) = N - 1 - N + i + 2 = */ i + 1;
      int deno = hi - lo;
      cout << "nu = " << nu << ", deno " << deno << "\n";

      int tail = 0;
      if (deno != 0) {
        tail = round((nu + 0.0) / deno);
      }

      avgDiff[i] = abs(head - tail);

      cout << head << " " << tail << " " << avgDiff[i] << "\n";

      if (avgDiff[i] < minimus) {
        minimus = avgDiff[i];
        idx = i;
      }
    }

    /*
    for (int i = 0; i < N; i++) {
      cerr << avgDiff[i] << " ";
    }
    */
    cout << "\n";

    destructor();
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

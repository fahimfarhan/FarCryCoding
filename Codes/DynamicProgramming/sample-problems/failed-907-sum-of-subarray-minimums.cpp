#include <bits/stdc++.h>
using namespace std;

#define INF 30001
#define N_INF -30001
#define MOD 1000000000 + 7

class Solution {
private:
  int **dp = nullptr;
  int N = 0;

  int f(int l, int r) {
    // cerr << "0. f " << l << ", " << r << "\n";
    if ((l > r) || (l >= N) || (r >= N)) {

      //   cerr << "1. f "      << "\n";
      return INF;
    }

    if (dp[l][r] != -1) {
      // cerr << "2. f "<< "\n";
      return dp[l][r];
    }

    int mid = l + (r - l) / 2;

    // cerr << "3. f "<< "\n";
    int minimus = min(f(l, mid), f((mid + 1), r));
    dp[l][r] = minimus;
    return dp[l][r];
  }

  void preprocess(vector<int> &arr) {

    N = arr.size();

    dp = new int *[N + 1];
    for (int i = 0; i <= N; i++) {
      dp[i] = new int[N + 1];

      memset(dp[i], -1, sizeof(int) * (N + 1));
    }

    for (int i = 0; i < N; i++) {
      dp[i][i] = arr[i];
    }
  }

  void destructor() {
    for (int i = 0; i <= N; i++) {
      delete[] dp[i];
    }
    delete[] dp;
  }

  int start() {
    int result = 0;

    int j = 0;
    int temp = 0;
    for (int i = 0; i < N; i++) {
      for (int size = 1; size <= N; size++) {
        j = i + size - 1; // meh...

        cerr << "start i = " << i << ", j = " << j << "\n";
        temp = f(i, j);
        if (temp == INF) {
          continue;
        }
        result = (result + temp) % MOD;
        cerr << "temp = " << temp << ", result = " << result << "\n";
      }
    }
    return result;
  }

public:
  void printer() {
    for (int i = 0; i <= N; i++) {
      for (int j = 0; j <= N; j++) {
        cout << "" << dp[i][j] << " ";
      }
      cout << "\n";
    }
  }

  int sumSubarrayMins(vector<int> &arr) {
    preprocess(arr);
    int result = start();
    destructor();
    return result;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> v = {3, 1, 2, 4};
  vector<int> v2 = {11, 81, 94, 43, 3};
  int a = s.sumSubarrayMins(v);
  cout << a << "\n";
  // s.printer();

  a = s.sumSubarrayMins(v2);
  cout << a << "\n";
  return 0;
}

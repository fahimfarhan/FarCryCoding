#include <bits/stdc++.h>
#include <climits>
#include <cstdlib>
#include <cstring>
using namespace std;

#define INF 1000 + 5

int N = 0, K = 0;
int *h = nullptr;
int *dp = nullptr;
// int dp[100000 + 5];

int f(int n) {
  // base case
  if (n < 1 || N < n) {
    return INF;
  }
  // recursive case
  for (int i = 1; i <= K; i++) {
  }
  return 0;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> K;

  h = new int[N + 2];
  // dp = new int[N + 2];
  // memset(dp, -1, sizeof(dp) * (N + 1));

  dp = (int *)calloc(5, sizeof(int)); // ()calloc(-1, sizeof(dp) * (N + 2));

  for (int i = 1; i <= N; i++) {
    cin >> h[i];
  }

  for (int i = 0; i <= N + 2; i++) {
    // cin >> h[i];
    cout << dp[i] << " ";
  }
  cout << "\n";

  // delete[] dp;
  delete[] h;

  return 0;
}

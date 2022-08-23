#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  /**
   * @brief 
   * 
   * b 00j0b  00j0b  00j0b  00j0b
   * 0 12345  678910 12345
   */

  const int m = 1000000+5; 
  int dp[m] = {0};

  // preprocess
  dp[0] = 1;

  for(int i=5; i <m; i++) {
    dp[i] = 1;
  }

  for(int i=1; i<m; i++) {
    dp[i] = dp[i] + dp[i-1];
  }

  // queries

  int T, N;
  cin>>T;

  for(int t=1; t <=T; t++) {
    cin>>N;
    cout<<"Case #"<<t<<": "<<dp[N-1]<<"\n";  
  }

  return 0;
}
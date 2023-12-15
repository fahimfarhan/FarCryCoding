#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
    int knightDialer(int n) {
        int mCount = 0;
        memset(dp, -1, sizeof(dp));
        //cerr<<"here1"<<"\n";

        int temp = 0;
        for(int i=0; i < 4; i++) {
          for(int j=0; j < 3; j++) {
            temp = r(i, j, n);
            if(temp != -1) {
              mCount = ( mCount + temp ) % MOD;
              cerr<<"mCount: "<<mCount<<"\n";
            }

          }
        }
        //cerr<<"here2"<<"\n";
      
        return mCount;
    }

private:
  int MOD = 1000000000 + 7;
  int dp[4][3][5001] = {-1};
  int mp[4][3] = { {1,2,3}, {4,5,6}, {7,8,9}, {-1, 0, -2} };

  int horizontal[8] = {2,2,-2,-2, 1,1,-1,-1};
  int vertical[8] = {1,-1,1,-1,2,-2,2,-2};

  int r(int i, int j, int n) {
    // invalid cases
    // cerr<<"\nr: "<<i<<" "<<j<<" "<<n<<"\n";
    if( (i < 0) || (j < 0) || (i > 3) || (j > 2) ) {
      return -1;
    }

    if(n <= 0) {
      cerr<<", ";
      return -1;
    }

    if( (i == 3) && (j !=1) ) {
      return -1;
    }

    if(dp[i][j][n] != -1) {
      // return dp[i][j][n];  // todo: undo comment
    }

    cerr<<""<<mp[i][j]<<"";

    int mCount = 1;
    int remainingCount = 0;
    int h = 0, v = 0;
    int n1 = n - 1;
    int temp = 0;
    for(int k=0; k<8; k++) {
      h = horizontal[k]; 
      v = vertical[k];

      temp = r(i+h, j+v, n1);

      if(temp!=-1) {
        remainingCount = (remainingCount % MOD) + (temp% MOD);
      }

    }

    dp[i][j][n] = (mCount + remainingCount) % MOD;

    return dp[i][j][n];
  
  }

};

int main() {
  Solution s;
  int a = s.knightDialer(1);
  cerr<<"\n"<<a<<"\n-----------\n";
  a = s.knightDialer(2);
  cerr<<"\n"<<a<<"\n-----------\n";
  
  return 0;
}
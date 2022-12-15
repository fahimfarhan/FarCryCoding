#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
  int memo[1001][1001] = {};
  string text1 = "", text2 = "";

  public:
    int longestCommonSubsequence(string text1, string text2) {
      // preprocessing
      this->text1 = text1;
      this->text2 = text2;

      for(int i=0; i< 1001; i++) {
        memset(memo[i], -1, sizeof(int) * 1001);
      }
      // dynamic programming
      int n = text1.size();
      int m = text2.size();

       return dp(n-1, m-1);
    }

    int dp(int i, int j) {
      if( (i < 0) || (j < 0) ) {
        return 0;
      }

      if(memo[i][j] != -1) {
        return memo[i][j];
      }

      int localMaximus = 0;
      if(text1[i] == text2[j]) {
        return localMaximus = 1 + dp(i-1, j-1);
      } else {
        localMaximus = max(dp(i-1, j), dp(i, (j-1)));
      }

      return memo[i][j] = localMaximus;
    }
};

int main (int argc, char *argv[]) {
  
  return 0;
}

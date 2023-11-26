#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
  int dp[1000];
  int N = 0;
  vector<int> prices;
public:
    Solution() {}

    int minimumCoins(vector<int>& prices) {
      this->prices = prices;
      this->N = prices.size();
      memset(dp, -1, sizeof(dp));

      return r2(1);
    }

    int r2(const int& idx1) {
      if(idx1 < 1) {
        return 0;
      }

      int idx0 = idx1 - 1;

      if(idx1 > N) {
        return 0;
      }

      if(dp[idx0] != -1) {
        return dp[idx0];
      }

      int nextPurchaseIdx1 = (idx1<<1) | 1; // getFreeIdx+1;

      int minimusCost = INT_MAX;

      for(int i=idx1+1; i <= ((idx1<<1) | 1) ; i++) {
        minimusCost = min(minimusCost, ( prices[idx0] + r2(i)) );
      }
      
       dp[idx0] = minimusCost; // setDp1(idx1, minimusCost);
       return minimusCost;
    }
    
};


int main(int argc, char const *argv[])
{
  /* code */
  Solution s;
  vector<int> a = {3,1,2};
  vector<int> b = {1,10,1,1};

  cout<<s.minimumCoins(a)<<"\n";
  cout<<s.minimumCoins(b)<<"\n";
  return 0;
}

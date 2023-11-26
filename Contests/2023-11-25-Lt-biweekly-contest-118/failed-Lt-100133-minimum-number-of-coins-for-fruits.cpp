#include <bits/stdc++.h>

using namespace std;
class Solution {
private:
  vector<int> dp;
public:
    int minimumCoins(vector<int>& prices) {
      int N = prices.size(); 
      dp.clear();
      dp.resize(N, -1);
      int minCost = r(prices, N, 1);

      return minCost;
    }

    int r(vector<int>& prices, const int& N, int idx1) {
      int cost = 0, minimus = INT_MAX, idx0 = idx1 - 1;

      if(dp[idx0] != -1) {
        return dp[idx0];
      }

      cost = prices[idx0];

      for(int i = idx1 * 2; i >= idx1+1; i--) {
        if(i <= N) {
          minimus = min(minimus, r(prices, N, i));          
        }
      }

      if(minimus != INT_MAX) {
        cost += minimus;
      }

      dp[idx0] = cost;
      return dp[idx0];
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

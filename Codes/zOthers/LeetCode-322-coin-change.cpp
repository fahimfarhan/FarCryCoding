#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  int *dp = nullptr;
  int cSize = 0;
  int start = 0;

  void destructor() {
    if(dp!=nullptr) {
      delete[] dp;
    }
  }

  void preprocess(const int& amount, const vector<int>& coins) {
    // dp[0] = 1; // choose no coins, that's the only 1 way, so ans = 1
    dp[0] = 0; // cz I got WA... :/

    for(auto c: coins) {
      if(c <= amount)
        dp[c] = 1;
    }
  }

  pair<int, bool> existsV1FailedTle(int someAmount, const vector<int>& coins) {
    cerr<<"inside exists "<<someAmount<<"\n";
    if(someAmount < 0) {
      return {-1, false};
    }

    if(dp[someAmount] != -1) {
      return {dp[someAmount], true};
    }

    pair<int, bool> p = {-1, false};
    bool b = false;
    int minimus = INT_MAX;
    for(int i=start; i>=0; i--) {
      auto temp = exists( (someAmount - coins[i]) , coins);
      b = b || temp.second;
      if(temp.second) {
        minimus = min(minimus, temp.first);
      }
    }
    if(b) {
      dp[someAmount] = minimus + 1;
      return {dp[someAmount], true};
    } else
      return p;
  }


pair<int, bool> existsV2FailedWa(int someAmount, const vector<int>& coins) {
    cerr<<"inside exists "<<someAmount<<"\n";
    if(someAmount < 0) {
      return {-1, false};
    }

    if(dp[someAmount] != -1) {
      return {dp[someAmount], true};
    }

    pair<int, bool> p = {-1, false};
    bool b = false;
    int minimus = INT_MAX;
    for(int i=start; i>=0; i--) {
      int d = someAmount / coins[i];
      if(d == 0) {
        continue;
      }
      auto temp = exists( (someAmount - d*coins[i]) , coins);
      b = b || temp.second;
      if(temp.second) {
        minimus = min(minimus, temp.first + d);
      }
    }
    if(b) {
      dp[someAmount] = minimus + 1;
      return {dp[someAmount], true};
    } else
      return p;
  }

  pair<int, bool> exists(int someAmount, const vector<int>& coins) {
    cout<<"inside exists "<<someAmount<<"\n";
    if(someAmount < 0) {
      return {-1, false};
    }

    if(dp[someAmount] != -1) {
      return {dp[someAmount], true};
    }

    pair<int, bool> p = {-1, false};
    bool b = false;
    int minimus = INT_MAX;
    for(int i=start; i>=0; i--) {
      auto temp = exists( (someAmount - coins[i]) , coins);
      b = b || temp.second;
      if(temp.second) {
        minimus = min(minimus, temp.first);
      }
    }
    if(b) {
      dp[someAmount] = minimus + 1;
      return {dp[someAmount], true};
    } else
      return p;
  }



public:
  int coinChange(vector<int>& coins, int amount) {
    int minimus = 0;
    cSize = coins.size();
    sort(coins.begin(), coins.end());

    dp = new int[amount+5];


    for(int i=0; i<=amount; i++) {
      dp[i] = -1;
    }

    preprocess(amount, coins);
    start = -1;
    for(int i=cSize-1; i>=0; i--) {
      if(coins[i] <= amount) {
        start = i;
        break;
      }
    }
    
    auto p = exists(amount, coins);
    minimus = p.first;

    destructor();
    return minimus;
  }
};

int main() {
  Solution s;

// [186,419,83,408]
// 6249

  vector<int> v = {186,419,83,408};
  cout<<s.coinChange(v, 6249)<<"\n";
  return 0;
}
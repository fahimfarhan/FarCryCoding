# include <bits/stdc++.h>
using namespace std;

class Model {
public:
  int startTime;
  int endTime;
  int profit;

  Model(int st, int et, int pt) {
    this->startTime = st;
    this->endTime = et;
    this->profit = pt;
  }

  bool operator < (const Model& model) const
    {
        return (startTime < model.startTime);
    }

};

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int N = startTime.size();
        vector<Model> v;
        // int dp[50000+1];
        memset(dp, -1, sizeof(dp));
        
        for(int i = 0; i < N; i++) {
          v.push_back(Model(startTime[i], endTime[i], profit[i]));
        }

        // sort
        sort(v.begin(), v.end());
        // dp
        return f(v, 0, 0);
    }

private:
  int dp[50000+1];

  int f(vector<Model>& v, int idx, int profitSoFar) {
    int N = v.size();
    // base case:
    if(idx >= N ) {
      return 0;
    }

    if(dp[idx] != -1) { return dp[idx]; }

    int maximus;
    // contains item idx
    int profitSoFar1 = profitSoFar + v[idx].profit;
    int j = idx+1;

    // while ( (j < N) &&  v[j].startTime < v[idx].endTime) {
    //   /* code */
    //   j++;
    // }

    Model val(v[idx].endTime, 0, 0);
    vector<Model>::iterator it = lower_bound(v.begin(), v.end(), val);
    j = it - v.begin();

    int p1 = v[idx].profit + f(v, j, profitSoFar1);

    // does not contain item idx
    int p2 = f(v, (idx+1), profitSoFar);
    
    maximus = max(p1, p2);
    dp[idx] = maximus;
    return maximus;
  }        

  int recursion(vector<Model>& v, int idx, int profitSoFar) {
    int N = v.size();
    // base case:
    if(idx >= N ) {
      return 0;
    }

    int maximus;
    // contains item idx
    int profitSoFar1 = profitSoFar + v[idx].profit;
    int j = idx+1;

    while ( (j < N) &&  v[j].startTime < v[idx].endTime) {
      /* code */
      j++;
    }
    

    int p1 = v[idx].profit + recursion(v, j, profitSoFar1);

    // does not contain item idx
    int p2 =  recursion(v, (idx+1), profitSoFar);
    
    maximus = max(p1, p2);

    return maximus;
  }

};

int main(int argc, char const *argv[])
{
  /* code */
  int dp[50000+1];
  memset(dp, -1, sizeof(dp));
  
  for(int i=0; i<50000+1; i++) {
          // for(int j=0; j<10; j++) {
    cout<<dp[i]<<" ";
          // } cout<<"\n";
  }
  return 0;
}

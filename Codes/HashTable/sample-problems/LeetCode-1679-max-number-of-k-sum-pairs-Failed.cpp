#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
      unordered_map<int, int> mp;
      int n = nums.size();
      for(int i = 0; i < n; i++) {
        mp[nums[i]]++;
      }      

      int result = 0;
      int minimus = 0;
      
      for(int i=0; i<n; i++) {
        cerr<<"mp[nums["<<i<<"]] = "<<mp[nums[i]] << " " <<"mp[k - nums["<<i<<"]] = "<<mp[k - nums[i]]<<"\n";
        minimus = min(mp[nums[i]], mp[k - nums[i]]);
        result += minimus;
        mp[nums[i]] -= minimus;
        mp[k - nums[i]] -= minimus;
        cerr<<"minimus "<<minimus<<"\n";
      }
      return result;
    }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  vector<int> v = {3,1,3,4,3};
  Solution s;
  int out = s.maxOperations(v, 6);
  cout<<out<<"\n";
  return 0;
}
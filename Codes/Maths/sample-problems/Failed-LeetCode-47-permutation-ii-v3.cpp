#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      vector<vector<int>> result;
      sort(nums.begin(), nums.end());

      result.push_back(nums);
      
      int n = nums.size();
      for(int i=0; i<n-1; i++) {
        for(int j = 0; j < n - i - 1; j ++) {
          if(nums[j] < nums[j + 1]) {
            swap(nums[j], nums[j+1]);
            vector<int> cloneOfNums(nums);
            result.push_back(cloneOfNums);
          }
        }
      }
      return result;
    }
};

int main() {
  vector<int> v = {2, 2, 1, 1};
  Solution s;
  auto out = s.permuteUnique(v);
  for(auto i: out) {
    for(auto j: i) {
      cout<<j<<" ";
    }cout<<"\n";
  }
  return 0;
}
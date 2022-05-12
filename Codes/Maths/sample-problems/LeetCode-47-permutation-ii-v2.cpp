#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int> > result;

    vector<int> v;
    set<vector<int>> us;

    backTrack(nums, v, us);

    for(auto u: us) {
      result.push_back(u);
    }

    return result;
  }

private:
  const int invalid_num = -69;

  void backTrack(vector<int>& nums, vector<int>& v, set<vector<int>>& us) {
    if(v.size() == nums.size()) {
      vector<int> cloneOfV(v);
      us.insert(cloneOfV);
      return;
    }

    int size = nums.size();
    for(int i=0; i<size; i++) {
      if(nums[i] != invalid_num) {
        int u = nums[i];
        nums[i] = invalid_num;
        v.push_back(u);

        backTrack(nums, v, us);
      
        nums[i] = u;
        v.pop_back();
      }
    }

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
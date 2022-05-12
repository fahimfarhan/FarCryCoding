#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      vector<vector<int>> result;
      sort(nums.begin(), nums.end());
      do {
        vector<int> v(nums);
        result.push_back(v);
      } while (next_permutation(nums.begin(), nums.end()));
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
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
      int result = 0, complement = 0;      
      unordered_map<int, int> mp;

      for(auto i : nums) {
        complement = k - i;
        if(mp[complement] > 0) {
          result++;
          mp[complement]--;
        } else {
          mp[i]++;
        }
      }
      
      return result;
    }
};

int main() {

  return 0;
}
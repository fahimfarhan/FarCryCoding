#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      unordered_map<int, int> mp;
      int N = nums.size();
      int num = 0;
      bool exists = false;
      for(int i=0; i<N; i++) {
        num = nums[i];
        auto it = mp.find(num);
        exists = it != mp.end();
        if(exists) {
          if( (i - it->second) <= k) {
            return true;
          }
        }
        mp[num] = i;
      }
      return false;        
    }
};

int main() {

  return 0;
}

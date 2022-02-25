#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      return false;
    }

    bool failedTleContainsNearbyDuplicateV2(vector<int>& nums, int k) {
      int N = nums.size();
      if(N < 2) {
        return false;
      }

      int j = 0;
      unordered_map<int, int> mp; // slidingWindowMap;
      int n = 0;

      int exceptionalLimit = min(N, k+1);

      for(int i=0; i<exceptionalLimit; i++) {
        n = nums[i];
        mp[n]++;
        if(mp[n] == 2) {
          return true;
        }
      }

      for(int i=k+1; i<N; i++) {
        j = i - k;
        int jOutSideSildingWindow = j - 1;
        n = nums[jOutSideSildingWindow];
        mp[n]--;
        
        cerr<<" j = "<<jOutSideSildingWindow<<", muns[i] = "<<n<<", mp[n] = "<<mp[n]<<"\n";        
        n = nums[i];
        mp[n]++;

        cerr<<" i = "<<i<<", muns[i] = "<<n<<", mp[n] = "<<mp[n]<<"\n";        
        if(mp[n] == 2) {
          return true;
        }
      }
      return false;
    }
  
    bool failedTleContainsNearbyDuplicate(vector<int>& nums, int k1) {
      int N = nums.size();
      int j = 0;
      for(int k = 1; k <= k1; k++) {
        for(int i=0; i<(N-k); i++) {
          j = i + k;
          if(nums[i] == nums[j]) {
            return true;
          }
        }
      }
      return false;
    }

};

int main() {
  vector<int> v = {1,2,3,1};
  Solution s;
  cout<<s.containsNearbyDuplicate(v, 3)<<"\n";
  
  vector<int> v1 = {1};
  cout<<s.containsNearbyDuplicate(v1, 1)<<"\n";
  

  vector<int> v2 = {1,2};
  cout<<s.containsNearbyDuplicate(v2, 1)<<"\n";


  cout<<s.containsNearbyDuplicate(v2, 2)<<"\n";

  vector<int> v3 = {4,1,2,3,1,5};
   // 3
  cout<<s.containsNearbyDuplicate(v3, 3)<<"\n";

  return 0;
}

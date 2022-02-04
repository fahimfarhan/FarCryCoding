#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
      unordered_map<int, int> mp;
      mp[0] = -1;  // why is this -1?

      int maximus = INT_MIN;
      int N = nums.size();
      int cf = 0; // cumulative frequency
      bool exists = false;

      for(int i=0; i<N; i++) {
        if(nums[i] == 0) {
          cf--;
        } else {
          cf++;
        }

        exists = mp.find(cf) != mp.end();
        if(exists) {
          int end = i;
          int start = mp[cf];

          int currentSegmentLength = end - start; // + 1;  // why didnot we add 1 ?
          maximus = max(maximus, currentSegmentLength);
        } else {
          mp[cf] = i;
        }
      }
      return maximus;      
    }
};

int main() {
  Solution s;

  vector<int> test1 = {0, 1};
  vector<int> test2 = {0, 1, 0}; // failed!
  vector<int> test3 = {0, 1, 1, 1, 0, 0, 1, 0, 0, 1};

  cout<<s.findMaxLength(test1)<<"\n";
  cout<<s.findMaxLength(test2)<<"\n";
  cout<<s.findMaxLength(test3)<<"\n";
  return 0;
}
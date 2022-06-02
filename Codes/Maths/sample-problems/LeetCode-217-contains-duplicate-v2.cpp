#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        bool duplicateExists = false;
        int n = nums.size();
        for(int i=1; i<n; i++) {
          if(nums[i] == nums[i-1]) {
            duplicateExists = true;
            break;
          }
        }
        return duplicateExists;
    }
};

int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}

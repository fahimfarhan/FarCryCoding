#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
      vector<int> temp(nums); 

      sort(temp.begin(), temp.end());
      int n = temp.size();
      int l = 0;
      int r = 0;      
    
      bool isUnsorted = false;
      for(int i=0; i<n; i++) {
        if(nums[i] != temp[i]) {
          isUnsorted = true;
          l = i; 
          break;
        }
      }

      for(int i=n-1; i>=0; i--) {
        if(nums[i]!=temp[i]) {
          isUnsorted = true;
          r = i;
          break;
        }
      }

      if(isUnsorted)
        return (r - l + 1);
      return 0;
    }
};

int main() {


  return 0;
}
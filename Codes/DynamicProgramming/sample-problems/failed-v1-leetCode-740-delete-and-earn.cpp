#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return topToBottomRecursion(nums, nums.size());
    }

    int topToBottomRecursion(vector<int>& nums, const int& numsSize) {
      if(numsSize <= 0) {
        return 0;
      }
      else if(numsSize == 1) {
        return nums[0];
      }

      int optionOne = nums[numsSize-1] + topToBottomRecursion(nums, numsSize - 2);
      int optionTwo = topToBottomRecursion(nums, numsSize - 1);

      // cerr<<"op1 = "<<optionOne<<", op2 = "<<optionTwo<<"\n";
      int maximus = max(optionOne, optionTwo);
      return maximus;
    }
};


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  vector<int> v1 = {3, 4, 2};
  vector<int> v2 = {2,2,3,3,3,4};

  Solution s;

  cout<<s.deleteAndEarn(v1)<<"\n---------\n";
  cout<<s.deleteAndEarn(v2)<<"\n";


  return 0;
}

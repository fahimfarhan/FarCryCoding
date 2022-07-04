#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int secondPos = -1;
        int N = nums.size(); //   N = size/2 ? o.O

        for(int i=0; i<N; i++) {
          int firstNum = nums[i];
          int secondNum = target - firstNum;

          int tempPos;
        }
        return result;
    }
};

int main() {

  return 0;
}
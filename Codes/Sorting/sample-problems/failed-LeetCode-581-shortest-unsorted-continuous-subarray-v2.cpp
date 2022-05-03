#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findUnsortedSubarray(vector<int>& nums) {
    int l = 0, r = 0, n = nums.size();
    bool isUnsorted = false;
    int extrema, extremaPos;
    // find lower bound
    extrema = INT_MAX;
    extremaPos = INT_MAX;

    for(int i = 0; i < n; i++) {
      extrema = INT_MAX;
      extremaPos = INT_MAX;

      for(int j = i; j < n; j++) {
        if(nums[j] < extrema) {
          extrema = nums[j];
          extremaPos = j;
        }
      }

      if(i != extremaPos) {
        // swap(nums[i], nums[extremaPos]);
        isUnsorted = true;
        l = extremaPos;
        break; 
      }
    }

    // find upper bound
    for(int i = n-1; i >= 0; i--) {
      extrema = INT_MIN;
      extremaPos = INT_MIN;

      for(int j = i; j >= 0; j--) {
        if(nums[j] > extrema) {
          extrema = nums[j];
          extremaPos = j;
        }
      }

      if(i != extremaPos) {
        // swap(nums[i], nums[extremaPos]);
        isUnsorted = true;
        r = extremaPos;
        break; 
      }
    }
    // return 
    if(isUnsorted) return (r - l + 1);
    return 0;
  }
};

int main() {


  return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    /**
     * V1
     * time complexity O(n^3)
     * space complexity O(1)
     * 
    */
    bool find132patternV1(vector<int>& nums) {
      int n = nums.size();
      // bool exists = false;
      for(int i = 0; i < n; i++) {
        for(int j=i+1; j < n; j++) {
          for(int k = j+1; k < n; j++) {
            if(nums[i] < nums[k] && nums[k] < nums[j]) {
              // exists = true;
              return true;
            }
          }
        }
      }
      return false;
    }
    

    /**
     * V2
     * Slight improvement
     * time complexity O(n^2)
     * space complexity O(1)
     * 
     * replace one for loop with minimus
    */
    bool find132patternV2(vector<int>& nums) {
      int minimus = nums[0];

      int n = nums.size();

      for(int j = 0; j < n; j++) {
        for(int k = j + 1; k < n; k++) { 
            if(nums[minimus] < nums[k] && nums[k] < nums[j]) {
              // exists = true;
              return true;
            }
        }
        minimus = min(minimus, nums[j]);
      }
      return false;
    }


    /**
     * time complexity BigO(N)
     * space complexity BigO(N)
     * 
    */
    bool find132patternV3(vector<int>& nums) {
      stack<int> st;
      int thirdNumber = INT_MIN;
      int n = nums.size();
      for(int i=n-1; i >=0; i--) {
        if(nums[i] < thirdNumber) {
          return true;
        }
        while( (!st.empty()) && (st.top() < nums[i]) ) {
          thirdNumber = st.top();
          st.pop();
        }
        st.push(nums[i]);
      } 
      return false;     
    }
    
    /**
     * time complexity BigO(N)
     * space complexity BigO(N)
     * 
    */
    bool find132pattern(vector<int>& nums) {
      int N = nums.size();
      int thirdNumber = INT_MIN;
      stack<int> stForSecondNumber; // stores the largest number

      for(int i = N-1; i >= 0; i--) {
        if(nums[i] < thirdNumber) {
          return true;
        }
        while ( (!stForSecondNumber.empty()) && (stForSecondNumber.top() < nums[i]) ) {
          thirdNumber = max(thirdNumber, stForSecondNumber.top());
          stForSecondNumber.pop();
        }
        stForSecondNumber.push(nums[i]);
        
      }

      return false;
    }
};

int main() {

  return 0;
}
#include <bits/stdc++.h>
using namespace std;

class NumArray {
private:
	int *dp = nullptr;	

public:
    NumArray(vector<int>& nums) {
        
        int size = nums.size(); 
        dp = new int[size+1];
        dp[0] = nums[0];

        for(int i=1; i<size; i++) {
        	dp[i] = dp[i-1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0) 
        	return dp[right];
        return dp[right] - dp[left-1];
    }

    ~NumArray() {
    	if(dp != nullptr) delete[] dp;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

int main() {

	return 0;
}
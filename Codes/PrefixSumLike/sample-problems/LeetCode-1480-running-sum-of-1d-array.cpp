#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        if(nums.empty()) {
            vector<int> v;
            return v;
        }

        int N = nums.size();
        vector<int> dp(N, 0);
        dp[0] = nums[0];
        
        for(int i=1; i<N; i++) {
            dp[i] = nums[i] + dp[i-1];
        }
        return dp;
    }
};

int main() {

    return 0;
}
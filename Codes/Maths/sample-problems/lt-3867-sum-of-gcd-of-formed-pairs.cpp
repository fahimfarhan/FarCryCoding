#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long gcdsum = 0;

        int N = nums.size();
        // step 1: create prefixGcd, O(n)xO(lg(n)) = O(nlg(n))
        vector<int> prefixGcd(N, 0);

        int mxi = nums[0];
        prefixGcd[0] = gcd(nums[0], mxi);

        for(int i = 1; i < N; i++) { // O(n)
            mxi = max(mxi, nums[i]);
            prefixGcd[i] = gcd(nums[i], mxi); // O(lg(n))
        }

        // step 2: sort prefixGcd in non-decreasing order, O(nlg(n))
        sort(prefixGcd.begin(), prefixGcd.end());

        int mid = N/2;
        int m = 0;

        // step 3: form pairs, compute gcd, and add to gcdsum, O(n/2)xO(lg(n)) = O(nlg(n)/2)
        for(int i = 0; i < mid; i++) { //  O(n/2)
            m = gcd(prefixGcd[i], prefixGcd[N - 1 - i]); // O(lg(n))
            gcdsum += m;
        }

        // step 4: return gcdsum
        return gcdsum;        
    }
};

int main() {

    return 0;
}
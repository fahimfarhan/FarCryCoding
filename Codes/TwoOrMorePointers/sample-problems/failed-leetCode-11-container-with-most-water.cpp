#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int N = height.size();
        int maximus = mArea(height, 0, (N-1) );
        return maximus;
    }

private:
    int mArea(vector<int>& height, int start, int end) {
        cerr<<"start "<<start <<" end "<<end<<"\n";
        if(start == end) {
            return 0;
        }
        int dx = end - start;
        int dy = min(height[start], height[end]);

        if(dx == 1) {
            return dy; // min(height[start], height[end]);
        }

        int mid = (start + end ) / 2;
        int left = mArea(height, start, mid);
        int right = mArea(height, mid, end);
        // combined...
        int combined = dx * dy;
        return max(combined, max(left, right));
    }
};


int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0); 
    cout.tie(0);

    vector<int> h1 = {1,8,6,2,5,4,8,3,7};
    Solution s;
    int a = s.maxArea(h1);
    cout<<a<<"\n";
    return 0;
}
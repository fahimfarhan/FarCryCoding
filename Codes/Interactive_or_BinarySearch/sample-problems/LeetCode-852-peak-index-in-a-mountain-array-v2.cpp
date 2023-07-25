#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0, r = arr.size(), mid;
        while(l < r) {
            mid = l + (r - l)>>1;
            if(arr[mid] < arr[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}
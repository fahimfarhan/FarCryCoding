#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;
        int end = arr.size() - 1;
        int mid = 0;
        int where = 0;
        while(true) {
            mid = (start + end) / 2;
            where = peak(arr, mid);
            if(where == 0) {
                break;
            } else if(where == -1) {
                start = mid;
            } else {
                end = mid;
            }
        }
        return mid;
    }
private:
    int peak(vector<int>& arr, int i) {
        int prev = i-1;
        int next = i+1;
        int N = arr.size();

        if(prev == -1) {
            if(arr[i] > arr[next]) {
                return 0;
            } else {
                return -1;
            }
        }

        if(next == N) {
            if(arr[prev] < arr[i]) {
                return 0;
            } else {
                return 1;
            }
        }

        if( ( arr[prev] < arr[i] ) && ( arr[i] < arr[next]) ) {
            return -1;
        } else if( (arr[prev] > arr[i]) && (arr[i] > arr[next]) ) {
            return 1;
        } else {
            return 0;
        }

    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

inline void mySwap(int* a, int* b) {
  (*a) = (*a) ^ (*b);
  (*b) = (*a) ^ (*b);
  (*a) = (*a) ^ (*b);
}

void foo() {
  int n = 10;
  int *p = &n;

  n = *p;
}

void selectionSort(vector<int>& nums) {
  int n = nums.size();

  int minimusPos, minimus;
  for(int i = 0; i < n; i++) {
    minimus = INT_MAX;
    minimusPos = INT_MAX;
    for(int j=i; j<n; j++) {
      if(nums[j] < minimus) {
        minimus = nums[j];
        minimusPos = j;  
      }
    }

    if(nums[i] != nums[minimusPos]) {
      // cout<<"before "<<nums[i]<<" "<<nums[minimusPos]<<"\n";
      mySwap(&nums[i], &nums[minimusPos]);
      // cout<<"after "<<nums[i]<<" "<<nums[minimusPos]<<"\n";
    }
  }
}

int main() {
  vector<int> v = {9,8,7,6,5,4,3,2,1};
  selectionSort(v);

  for(auto i: v) {
    cout<<i<<" ";
  } cout<<"\n";

  return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
      int N = nums.size();

      if(N == 0) 
        return 0;

      int sumOfXors = 0;

      int totalNumOfSubSets = 1 << N;
      // cout<<totalNumOfSubSets<<" = tot\n";
      
      for(int i=0; i<totalNumOfSubSets; i++) {
        int tempXor = 0;
        for(int j = 0; j < N; j++) {
          int parity = 1 << j;
          if( (i&parity) != 0) {
            tempXor = tempXor ^ nums[j];
          }
        }
        // cout<<"\n";
        sumOfXors += tempXor;
      }
      return sumOfXors;
    }

    void generateAllSubSets() {
      char ch[] = {'a', 'b', 'c', 'd'};
      int N = 4;
      int totalNumOfSubSets = 1 << N;
      cout<<totalNumOfSubSets<<" = tot\n";
      
      for(int i=0; i<totalNumOfSubSets; i++) {
        for(int j = 0; j < N; j++) {
          int parity = 1 << j;
          if( (i&parity) != 0) {
            cout<<ch[j]<<", ";
          }
        }cout<<"\n";
      }
    }
};

int main() {
  Solution s;
  vector<int> v1 = {1,3}, v2 = {5,1,6}, v3 = {3,4,5,6,7,8};

  cout<<s.subsetXORSum(v1)<<"\n";
  cout<<s.subsetXORSum(v2)<<"\n";
  cout<<s.subsetXORSum(v3)<<"\n";
 
  s.generateAllSubSets();
  /*
  1     1
  10    2
  100   4
  111   7
  1000  8
  1111  15
  10000 16
  */
  return 0;
}
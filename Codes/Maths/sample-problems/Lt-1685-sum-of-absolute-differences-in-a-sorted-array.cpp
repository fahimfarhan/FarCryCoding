#include <bits/stdc++.h>

using namespace std;

// #define ll long long int

class Solution {
public:
  vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    int N = nums.size();
    vector<int> cf(N, 0);

    cf[0] = nums[0];
    for(int i=1; i<N; i++) {
      cf[i] = cf[i-1] + nums[i];
    }

    // {0 --- (i-1){}, {i} ,   {(i+1) ... (N-1)}
    //       i-1          1           N - i 
    vector<int> output(N, 0);
    // int prefix = 0, suffix = 0;
    // int sum = 0;
    for(int i=0; i < N; i++) {
      // prefix = 0,  suffix = 0;

      if(i > 0) {
        output[i] += ( i*nums[i] - cf[i-1]);
      }
      // prefix = ((int)(i != 0)) *( i*nums[i] - cf[i-1]);
      
      output[i] += (cf[N-1] - cf[i]) - ( (N - 1) - (i + 1) + 1) * nums[i];

      // output[i] = prefix + suffix;

      // output[i] = sum;
    }
    return output;
  }



};

int main(int argc, char const *argv[])
{
  /* code */
  Solution s;

  vector<int> a = {2, 3, 5};
  auto result = s.getSumAbsoluteDifferences(a);
  
  for(auto x: result) {
    cout<<x<<" ";
  }cout<<"\n";
  
  return 0;
}


    // brute force TLE
    // vector<int> getSumAbsoluteDifferencesTLE(vector<int>& nums) {
    //   vector<int> output;

    //   int N = nums.size();
    //   int absSum = 0;
    //   for(int i=0; i<N; i++) {
    //     absSum = 0;
    //     for(int j=0; j < N; j++) {
    //       absSum += abs( nums[i] - nums[j] );
    //     }
    //     output.push_back(absSum);
    //   }
    //   return output;
    // }

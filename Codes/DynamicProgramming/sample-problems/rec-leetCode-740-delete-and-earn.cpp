#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;


class Solution {
private:
  const int SIZE_N = 20000+1;
  //unordered_map<int, int> mpNumToCount;
  int *mpNumToCount;
  unordered_map<int, int> mpNumToGain;
public:
    int deleteAndEarn(vector<int>& nums) {
      int maximus = 0;

      int a[20001] = {0};
      mpNumToCount = a; //new int[SIZE_N];

      for(auto i: nums) {
        mpNumToCount[i]++;
        maximus = max(maximus, i);
      }
      int result = 0;
      // main logic
      result = topToBottomRecursionV2(maximus); // topToBottomRecursionV2(maximus); 

      mpNumToCount = nullptr;
      return result;
    }

    int topToBottomDp(int num) {
      // case 1: return from dp cache
      auto cache = mpNumToGain.find(num);
      if(cache != mpNumToGain.end() ) {
        return cache->second;
      }
      // case 2: base cases
      if(num <= 0) {
        return 0;
      }

      else if(num == 1) {
        int m = num * mpNumToCount[num];
        mpNumToGain[num] = m;
        return m;
      }

      
      // op1: we take `num`
      int optionOne = num * mpNumToCount[num] + topToBottomDp(num-2);
      // op2: we don't take `num`
      int optionTwo = topToBottomDp(num-1);

      int maximus = max(optionOne, optionTwo);
      mpNumToGain[num] = maximus;
      return maximus;
    }


    int topToBottomRecursionV2(int num) {  // num = rightMostNumber
      if(num <= 0) {
        return 0;
      }

      else if(num == 1) {
        return num * mpNumToCount[num];
      }
      // op1: we take `num`
      int optionOne = num * mpNumToCount[num] + topToBottomRecursionV2(num-2);
      // op2: we don't take `num`
      int optionTwo = topToBottomRecursionV2(num-1);

      int maximus = max(optionOne, optionTwo);
      return maximus;
    } 

    int topToBottomRecursion(vector<int>& nums, const int& numsSize) {
      if(numsSize <= 0) {
        return 0;
      }
      else if(numsSize == 1) {
        return nums[0];
      }

      int optionOne = nums[numsSize-1] + topToBottomRecursion(nums, numsSize - 2);
      int optionTwo = topToBottomRecursion(nums, numsSize - 1);

      // cerr<<"op1 = "<<optionOne<<", op2 = "<<optionTwo<<"\n";
      int maximus = max(optionOne, optionTwo);
      return maximus;
    }
};


template<typename T>
vector<T> sliceV2(vector<T> const &v, int m, int n) {
    auto first = v.cbegin() + m;
    auto last = v.cbegin() + n + 1;
 
    std::vector<T> vec(first, last);
    return vec;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  vector<int> v1 = {3, 4, 2};
  vector<int> v2 = {2,2,3,3,3,4};
  vector<int> v3 = {3, 1};
  vector<int> v4 = {12,32,93,17,100,72,40,71,37,92,58,34,29,78,11,84,77,90,92,35,12,5,27,92,91,23,65,91,85,14,42,28,80,85,38,71,62,82,66,3,33,33,55,60,48,78,63,11,20,51,78,42,37,21,100,13,60,57,91,53,49,15,45,19,51,2,96,22,32,2,46,62,58,11,29,6,74,38,70,97,4,22,76,19,1,90,63,55,64,44,90,51,36,16,65,95,64,59,53,93};
  Solution s;

  auto start = high_resolution_clock::now();
  cout<<s.deleteAndEarn(v1)<<"\n"; // ---------\n";
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout<<"timeMicroSec: "<<duration.count()<<"\n";

  start = high_resolution_clock::now();
  cout<<s.deleteAndEarn(v2)<<"\n"; //---------\n";
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  cout<<"timeMicroSec: "<<duration.count()<<"\n";

  start = high_resolution_clock::now();
  cout<<s.deleteAndEarn(v3)<<"\n";
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  cout<<"timeMicroSec: "<<duration.count()<<"\n";




  vector<int> v5 = {1,3,5,7,9, 11, 13, 43}; // sliceV2(v4, 0, 5); // std::subList(v4.begin(), v4.begin() + 10);
  start = high_resolution_clock::now();
  cout<<s.deleteAndEarn(v5)<<"\n";
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  cout<<"timeMicroSec: "<<duration.count()<<"\n";

  // start = high_resolution_clock::now();
  cout<<"v4size = "<<v4.size()<<"\n";
  return 0;
}

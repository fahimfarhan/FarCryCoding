#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      unordered_set<int> uset;
      for(auto num: nums) {
        uset.insert(num);      
      }

      int longestStreak = 0;

      int currentNum = 0;
      int currentStreak = 1;
      for(auto num: uset) {
        if(uset.find(num-1) == uset.end()) {  // if num-1 does not exist...
          currentNum = num;
          currentStreak = 1;

          while (uset.find(currentNum + 1) != uset.end() ) {
            /* code */
            currentNum++;
            currentStreak++;
          }

          longestStreak = max(longestStreak, currentStreak);
          
        }
      }

      return longestStreak;
    }
};

int main() {

  return 0;
}
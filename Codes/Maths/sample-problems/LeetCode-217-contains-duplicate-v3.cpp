#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
      bool duplicateExists = false;
      unordered_set<int> us;
      for(auto i: nums) {
        us.insert(i);
      }

      duplicateExists = us.size() < nums.size();

      return duplicateExists;
    }
};

int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}

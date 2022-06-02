#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        bool duplicateExists = false;
        for(auto i: nums) {
          mp[i]++;
          if(mp[i]>1) {
            duplicateExists = true;
            break;
          }
        }
        return duplicateExists;
    }
};

int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<string>> partition(string s) {

    vector<vector<string>> result;
    vector<string> currentList;

    stringSize = s.size();
    for (int i = 0; i < 20; i++) {
      memset(dp[i], 0, sizeof(bool) * 20);
    }

    dfs(result, s, 0, currentList);

    return result;
  }

private:
  int stringSize = 0;
  bool dp[20][20];

  void dfs(vector<vector<string>> &result, string s, int startIdx,
           vector<string> currentList) {

    if (startIdx >= s.size()) {
      result.push_back(currentList);
    }

    // int size = s.size();
    int tempLength = 0;
    for (int endIdx = startIdx; endIdx < stringSize; endIdx++) {
      // if (isPalindrome(s, startIdx, endIdx)) {  // in the dp version, we
      // don't need isPalindrome()
      // bool condition1 = s[startIdx] == s[endIdx];
      // bool condition2 = endIdx - startIdx <= 2;
      // bool condition3 = dp[startIdx + 1][endIdx - 1];
      if (s[startIdx] == s[endIdx] &&
          (endIdx - startIdx <= 2 || dp[startIdx + 1][endIdx - 1])) {
        dp[startIdx][endIdx] = true;
        tempLength = endIdx - startIdx + 1;
        currentList.push_back(s.substr(startIdx, tempLength));
        dfs(result, s, (endIdx + 1), currentList);
        currentList.pop_back();
      }
    }
  }

  bool isPalindrome(const string &s, int low, int hi) {
    while (low < hi) {
      if (s[low] != s[hi]) {
        return false;
      }
      low++;
      hi--;
    }
    return true;
  }
};

int main(int argc, char *argv[]) { return 0; }

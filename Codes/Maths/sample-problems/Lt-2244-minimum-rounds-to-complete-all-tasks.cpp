#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
private:
  unordered_map<int, int> dp;

  int myMinimumRounds(int n) {

    if (dp.find(n) != dp.end()) {
      return dp[n];
    }

    if (n == 0) {
      return 0;
    }
    if (n == 1 || n < 0) {
      return -1;
    }

    int minimus = 0;
    int afterCompletingTwoTasks = myMinimumRounds(n - 2);
    int afterCompletingThreeTasks = myMinimumRounds(n - 3);

    if (afterCompletingTwoTasks == -1 && afterCompletingThreeTasks != -1) {
      return afterCompletingThreeTasks + 1;
    }

    if (afterCompletingTwoTasks != -1 && afterCompletingThreeTasks == -1) {
      return afterCompletingTwoTasks + 1;
    }

    minimus =
        min((afterCompletingTwoTasks + 1), (afterCompletingThreeTasks + 1));
    return dp[n] = minimus;
  }

public:
  int minimumRounds(vector<int> &tasks) {
    unordered_map<int, int> mp;

    int n = tasks.size();
    for (int i = 0; i < n; i++) {
      mp[tasks[i]]++;
    }

    int count = 0;
    int q = 0, r = 0;

    int setOfTwoTasks = 0;
    int setOfThreeTasks = 0;

    int temp = 0;
    for (auto e : mp) {
      temp = myMinimumRounds(e.second);
      if (temp == -1) {
        count = -1;
        break;
      } else {
        count += temp;
      }
    }

    return count;
  }
};

int main(int argc, char *argv[]) { return 0; }

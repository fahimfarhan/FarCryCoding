#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
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

    for (auto e : mp) {
      if (e.second == 1) {
        count = -1;
        break;
      } else if (e.second == 2) {
        setOfThreeTasks = 0;
        setOfTwoTasks = 1;
      } else {
        q = e.second / 3;
        r = e.second % 3;

        setOfThreeTasks = q;
        if (r == 0) {
          setOfTwoTasks = 0;
        } else if (r == 1) {
          setOfThreeTasks--;
          setOfTwoTasks = 1;

          // I missed this corner case!
          if (setOfThreeTasks == 0) {
            // this means {x, x, x}, {x} => {x, x} , {x, x}, ie, set of 2 tasks
            // = 2
            setOfTwoTasks = 2;
          }

        } else if (r == 2) {
          setOfTwoTasks = 1;
        }
      }
      count += (setOfTwoTasks + setOfThreeTasks);
    }

    return count;
  }
};

int main(int argc, char *argv[]) { return 0; }

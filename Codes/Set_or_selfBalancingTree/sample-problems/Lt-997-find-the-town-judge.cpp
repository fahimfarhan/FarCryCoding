#include <bits/stdc++.h>
using namespace std;

class Solution {

  int findJudge(int n, vector<vector<int>> &trust) {
    unordered_map<int, int>
        mp; // everybody trusts, ie, mapOfPersonToTrustCount;

    unordered_set<int> st;

    for (int i = 1; i <= n; i++) {
      mp[i] = 0;
    }

    for (auto v : trust) {
      mp[v[1]]++;
      st.insert(v[0]);
    }

    bool condition1 = 0, condition2 = 0;
    int result = -1;
    for (auto e : mp) {
      // condition1: e.first has everybody's trust, ie,...
      condition1 = e.second == n - 1;

      // condition2: e.first trusts nobody, not even himself, ie ...
      condition2 = st.find(e.first) == st.end();
      if (condition1 && condition2) {
        result = e.first;
        break;
      }
    }

    return result;
  }

  int findJudgeV1Failed(int n, vector<vector<int>> &trust) {
    set<int> st;
    for (auto v : trust) {
      st.insert(v[1]);
    }

    if (st.size() != 1) {
      return -1;
    }

    auto it = st.begin();
    int result = *it;
    return result;
  }
};

int main(int argc, char *argv[]) { return 0; }

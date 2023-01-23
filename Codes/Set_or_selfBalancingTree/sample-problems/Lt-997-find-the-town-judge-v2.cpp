#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  int mp[1005];
  // unordered_set<int> st;

  int trustsSomeOne[1005];

public:
  int findJudge(int n, vector<vector<int>> &trust) {
    int result = -1;
    bool condition1 = 0, condition2 = 0;

    memset(mp, 0, sizeof(int) * 1005);
    memset(trustsSomeOne, 0, sizeof(int) * 1005);

    for (auto v : trust) {
      mp[v[1]]++;
      trustsSomeOne[v[0]] = true; //(v[1] == v[0]);
    }

    for (int i = 1; i <= n; i++) {
      condition1 = mp[i] == n - 1;
      condition2 = !trustsSomeOne[i]; // st.find(i) == st.end();

      if (condition1 && condition2) {
        result = i;
        break;
      }
    }

    return result;
  }
};

int main(int argc, char *argv[]) { return 0; }

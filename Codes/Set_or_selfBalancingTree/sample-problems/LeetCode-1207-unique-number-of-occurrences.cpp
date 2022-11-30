#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
  bool uniqueOccurrences(vector<int> &arr) {
    unordered_map<int, int> mp;
    unordered_set<int> setOfKeys;
    unordered_set<int> setOfValues;

    int N = arr.size();
    for (int i = 0; i < N; i++) {
      mp[arr[i]]++;
    }

    for (auto e : mp) {
      // cerr << e.first << " " << e.second << "\n";
      setOfKeys.insert(e.first);
      setOfValues.insert(e.second);
    }

    if (setOfKeys.size() == setOfValues.size()) {
      return true;
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> v = {1, 2, 2, 1, 1, 3};
  cout << s.uniqueOccurrences(v) << "\n";
  return 0;
}

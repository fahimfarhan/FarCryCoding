#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

class Solution {
public:
  int totalFruit(vector<int> &fruits) {
    // all sub arrays
    int N = fruits.size();
    int maximus = INT_MIN;
    unordered_set<int> fruitType;

    for (int i = 0; i < N; i++) {
      for (int j = i; j < N; j++) {
        fruitType.clear();
        for (int k = i; k <= j; k++) {
          fruitType.insert(fruits[k]);
        }
        if (fruitType.size() < 3) {
          maximus = max(maximus, j - i + 1);
        }
      }
    }
    return maximus;
  }
};

int main() { return 0; }

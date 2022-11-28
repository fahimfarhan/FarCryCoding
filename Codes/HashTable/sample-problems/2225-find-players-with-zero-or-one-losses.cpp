#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> findWinners(vector<vector<int>> &matches) {
    vector<vector<int>> v;

    unordered_map<int, int> losers;

    int winner = 0, loser = 0;
    for (auto players : matches) {
      winner = players[0];
      loser = players[1];

      losers[loser]++;
      if (losers.find(winner) == losers.end()) {
        losers[winner] = 0;
      }
    }

    vector<int> winner0;
    vector<int> winner1;

    for (auto e : losers) {
      int player = e.first;
      int lossCount = e.second;

      if (lossCount == 0) {
        winner0.push_back(player);
      } else if (lossCount == 1) {
        winner1.push_back(player);
      }
    }

    sort(winner0.begin(), winner0.end());
    sort(winner1.begin(), winner1.end());

    v.push_back(winner0);
    v.push_back(winner1);

    return v;
  }
};

int main(int argc, char *argv[]) { return 0; }

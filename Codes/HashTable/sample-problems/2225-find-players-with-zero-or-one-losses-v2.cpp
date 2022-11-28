#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> findWinners(vector<vector<int>> &matches) {
    vector<vector<int>> v;

    int SIZE = 100000 + 5;
    int losers[SIZE];
    memset(losers, -1, sizeof(int) * SIZE);

    int winner = 0, loser = 0;
    for (auto players : matches) {
      winner = players[0];
      loser = players[1];

      if (losers[loser] == -1) {
        losers[loser] = 1;
      } else {
        losers[loser]++;
      }
      if (losers[winner] == -1) {
        losers[winner] = 0;
      }
    }

    vector<int> winner0;
    vector<int> winner1;

    int player, lossCount;

    for (int i = 0; i < SIZE; i++) {
      player = i;
      lossCount = losers[i];

      if (lossCount == 0) {
        winner0.push_back(player);
      } else if (lossCount == 1) {
        winner1.push_back(player);
      }
    }

    v.push_back(winner0);
    v.push_back(winner1);

    return v;
  }
};

int main(int argc, char *argv[]) { return 0; }

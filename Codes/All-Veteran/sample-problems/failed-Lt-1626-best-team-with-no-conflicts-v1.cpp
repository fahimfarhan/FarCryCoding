#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int bestTeamScore(vector<int> &scores, vector<int> &ages) {
    vector<pair<int, int>> ageScorePair;
    for (int i = 0; i < scores.size(); i++) {
      ageScorePair.push_back({ages[i], scores[i]});
    }

    sort(ageScorePair.begin(), ageScorePair.end());

    vector<vector<int>> dp(scores.size(), vector<int>(scores.size(), -1));

    return topDownDp(dp, ageScorePair, -1, 0);
  }

private:
  int topDownDp(vector<vector<int>> &dp, vector<pair<int, int>> &agesScorePair,
                int prev, int index) {
    // base case
    if (index >= agesScorePair.size()) {
      return 0;
    }

    if (dp[prev + 1][index] != -1) {
      return dp[prev + 1][index];
    }
    // recursive cases
    // if we the player is addeble, there will be 2 branches:
    // (1) We take him,
    // or (2) We don't take him
    if (prev == -1 ||
        agesScorePair[index].second >= agesScorePair[prev].second) {
      return dp[prev + 1][index] =
                 max(topDownDp(dp, agesScorePair, prev, (index + 1)),
                     agesScorePair[index].second +
                         topDownDp(dp, agesScorePair, index, (index + 1)));
    }

    return 0;
  }
};

int main(int argc, char *argv[]) { return 0; }

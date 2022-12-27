#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maximumBags(vector<int> &capacity, vector<int> &rocks,
                  int additionalRocks) {

    int N = capacity.size();
    if (N == 0) {
      return 0;
    }

    for (int i = 0; i < N; i++) {
      capacity[i] -= rocks[i];
    }

    sort(capacity.begin(), capacity.end());

    int kount = 0;
    for (int i = 0; i < N; i++) {
      if (capacity[i] <= additionalRocks) {
        kount++;
        additionalRocks -= capacity[i];
      } else {
        break;
      }
    }

    return kount;
  }
};

int main(int argc, char *argv[]) { return 0; }

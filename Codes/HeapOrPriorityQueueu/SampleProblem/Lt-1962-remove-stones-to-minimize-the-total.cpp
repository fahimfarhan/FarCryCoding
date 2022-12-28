#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minStoneSum(vector<int> &piles, int k) {
    priority_queue<int> pq;

    for (auto p : piles) {
      pq.push(p);
    }

    int top = 0;
    for (int i = 0; i < k; i++) {
      top = pq.top();
      pq.pop();
      top -= (top >> 1); // top = top - top/2;
      pq.push(top);
    }

    top = 0;
    while (!pq.empty()) {
      top += pq.top();
      pq.pop();
    }

    return top;
  }
};

int main(int argc, char *argv[]) { return 0; }

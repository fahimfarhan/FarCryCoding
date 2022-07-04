#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
      int N = heights.size();
      int i = 0;
      int delta = 0;
      priority_queue<int> pq;

      for(i=0; i<N-1; i++) {
        delta = heights[i+1] - heights[i];
        if(delta > 0) {
          if(bricks >= delta) {
            bricks -= delta;
            pq.push(delta);
          } else if(ladders > 0) {
            if(!pq.empty() && delta < pq.top()) {
              bricks+=pq.top();
              pq.pop();

              bricks-=delta;
              pq.push(delta);

              ladders--;
            } else {
              ladders--;
            }
          } else {
            break;
          }
        }
      }
      return i;
    }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  return 0;
}
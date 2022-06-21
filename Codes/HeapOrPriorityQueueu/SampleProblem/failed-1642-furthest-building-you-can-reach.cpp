#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
      int N = heights.size();
      int currPos = 0;

      for(int i=0; i<N-1; i++) {
        if(heights[i] >= heights[i+1]) {
          currPos++;
        } else {
          int delta = heights[i+1] - heights[i];

          if(delta <= bricks) {
            currPos++;
            bricks-=delta;
          } else if(ladders > 0) {
            currPos++;
          } else {
            break;
          }
        }
      }
      return currPos;      
    }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  return 0;
}
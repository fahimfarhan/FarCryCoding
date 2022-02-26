#include <bits/stdc++.h>
using namespace std;


#define INF INT_MAX - 1

class Solution {
private:
  int **cache;
  int endingMask;
  int numberOfNodes;
  void destructor() {
    for(int i=0; i<=numberOfNodes; i++) {
      delete[] cache[i];
    }
    delete[] cache;
  }

  int dp(int node, int mask, const vector<vector<int>>& graph) {
    if(cache[node][mask] != 0) {
      return cache[node][mask];
    }

    // base case
    if( (mask & (mask-1)) == 0 ) {
      // base case = mask only has a single "1", which 
      // means only one node has been visited (the current node)
      return 0;
    }

    cache[node][mask] = INF;
    for(int neighbour: graph[node]) {
      if( (mask & (1 << neighbour)) != 0 ) {
        int alreadyVisited = dp(neighbour, mask, graph);
        int notVisited = dp(neighbour, mask ^ (1 << node), graph);

        int betterOption = min(alreadyVisited, notVisited);
        cache[node][mask] = min(cache[node][mask], betterOption + 1);
      }
    } 

    return cache[node][mask];
  }

public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        numberOfNodes = n;
        endingMask = (1 << n) - 1;
        cache = new int*[n+1];
        for(int i=0; i<=n; i++) {
          cache[i] = new int[endingMask + 1];
        }

        for(int i=0; i<=n; i++) {
          for(int j=0; j<=endingMask; j++) {
            cache[i][j] = 0;
          }
        }

        int best = INT_MAX;
        for(int node = 0; node < n; node++) {
          best = min(best, dp(node, endingMask, graph));
        }


        destructor();
        return best;
    }
};

int main() {


  return 0;
}
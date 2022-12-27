#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
private:
  static const int SIZE_N = 30005; // infinity > max possible value of n
  // int graph[SIZE_N][SIZE_N];

  int **graph = nullptr;

public:
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
    vector<int> output;

    graph = new int *[n + 1];
    for (int i = 0; i <= n; i++) {
      graph[i] = new int[n + 1];
    }

    // cerr << "line 1\n";
    // preprocess
    int inf = SIZE_N;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j) {
          graph[i][i] = 0;
        } else {
          graph[i][j] = inf;
        }
      }
    }

    // cerr << "line 2\n";
    for (auto e : edges) {
      graph[e[0]][e[1]] = 1;
      graph[e[1]][e[0]] = 1;
    }

    // cerr << "line 3\n";
    // floyd warshall algo
    //
    int tempDistance = 0;
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          tempDistance = graph[i][k] + graph[k][j];
          if (tempDistance < graph[i][j]) {
            graph[i][j] = tempDistance; // graph[i][k] + graph[k][j];
          }
        }
      }
    }

    // cerr << "line 4\n";
    for (int i = 0; i < n; i++) {
      tempDistance = 0;
      for (int j = 0; j < n; j++) {
        if (graph[i][j] != inf) {
          tempDistance += graph[i][j];
        }
      }

      // cerr << "line 5\n";
      output.push_back(tempDistance);
    }

    for (int i = 0; i <= n; i++) {
      delete[] graph[i];
    }
    delete[] graph;

    return output;
  }
};

int main(int argc, char *argv[]) {

  vector<vector<int>> edges;
  edges.push_back({1, 0});
  cerr << "line 0.1\n";
  Solution s;

  cerr << "line 0.2\n";
  auto v1 = s.sumOfDistancesInTree(2, edges);
  cout << "case #" << 1 << "\n";
  for (auto i : v1) {
    cout << i << " ";
  }
  cout << "\n";
  return 0;
}

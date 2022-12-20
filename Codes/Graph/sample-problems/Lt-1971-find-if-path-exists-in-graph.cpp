// @author: fahimfarhan

#include <bits/stdc++.h>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
private:
  int n = 0;
  vector<int> *graph = nullptr;
  bool *visited = nullptr;

  bool dfs(int u, int dest) {
    visited[u] = true;

    bool valid = false;

    if (u == dest) {
      return true;
    }

    // int v = 0;
    for (auto v : graph[u]) {
      if (!visited[v]) {
        valid = dfs(v, dest);
        if (valid) {
          break;
        }
      }
    }

    return valid;
  }

public:
  bool validPath(int n, vector<vector<int>> &edges, int source,
                 int destination) {
    // init variables
    bool valid = false;

    this->n = n;
    graph = new vector<int>[n + 1];
    visited = new bool[n + 1];
    // preprocess variables
    memset(visited, 0, sizeof(bool) * (n + 1));
    int u, v;
    for (auto e : edges) {
      u = e[0];
      v = e[1];

      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    // run dfs
    valid = dfs(source, destination);

    // free up memory
    delete[] graph;
    delete[] visited;

    graph = nullptr;
    visited = nullptr;
    n = 0;
    return valid;
  }
};

int main(int argc, char *argv[]) { return 0; }

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  int N = 0;
  bool unlocked[1005];
  bool visited[1005];

  void dfs(vector<vector<int>> &rooms, int u = 0) {
    visited[u] = true;

    for (auto v : rooms[u]) {
      unlocked[v] = true;
    }
    // int v = 0;
    for (auto v : rooms[u]) {
      if ((!visited[v]) && unlocked[v]) {
        dfs(rooms, v);
      }
    }
  }

public:
  bool canVisitAllRooms(vector<vector<int>> &rooms) {
    this->N = rooms.size();
    memset(unlocked, 0, sizeof(bool) * (1001));
    memset(visited, 0, sizeof(bool) * (1001));

    unlocked[0] = true;
    // bool canVisit = true;
    dfs(rooms);

    int m = 0;
    for (int i = 0; i < N; i++) {
      if (unlocked[i]) {
        m++;
      }
    }
    return (m == N);
  }
};

int main(int argc, char *argv[]) { return 0; }

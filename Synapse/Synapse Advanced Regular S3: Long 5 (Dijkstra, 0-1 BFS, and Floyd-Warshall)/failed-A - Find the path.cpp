#include <bits/stdc++.h>
using namespace std;

#define IS_ONE_BASED_INDEXING true
#define DEBUG true
#define DIRECTED false

class Graph {
private:
  
public:
  int N, M, u, L, K;
  vector<vector<pair<int, int> > > g;
  
  Graph() {}

  void initGraph() {
    cin>>N>>M>>u>>L>>K;
    // isVisited.resize(N+1, false);

    g.resize(N+10);

    int u, v, w;
    for(int i=0; i<M; i++) {
      cin>>u>>v>>w;
      if(IS_ONE_BASED_INDEXING) {
        u--;
        v--;
      }
      g[u].push_back({v, w});
      
      if(!DIRECTED) {
        g[v].push_back({u, w});
      }
    }
  }

  ~Graph() {
    g.clear();
    if(DEBUG) {
      cerr<<"destructing the graph object\n";
    }
    // isVisited.clear();
  }
};



class Dfs {
private:
  Graph *graph = nullptr;
  vector<bool> isVisited;
  
  int maximus = INT_MIN;
  vector<int> unsortedWeights;
  vector<int> sortedWeights;

public:
  Dfs(Graph *g) {
    this->graph = g;
    isVisited.resize(this->graph->N+10, false);
  }

  int result() {
    return maximus;
  }

  void dfs() {
    for(int u=0; u<graph->N; u++) {
      if(!isVisited[u]) {
        dfsVisit(u, 0);
      }
    }
  }

  void dfsVisit(const int& u, const int& w) {
    if(DEBUG) {
      cerr<<"Visiting "<<u<<", depth = "<<unsortedWeights.size()<<", L = "<<graph->L<<"\n";
    }

    if(w > 0) {
      unsortedWeights.push_back(w);
    }


    if(unsortedWeights.size() == graph->L) {
      sortedWeights = vector<int>(unsortedWeights);
      sort(sortedWeights.begin(), sortedWeights.end());

      int kth = sortedWeights[graph->K];
      maximus = max(maximus, kth);
    }

    isVisited[u] = true;


    for(auto e: this->graph->g[u]) {
      if(!isVisited[e.first]) {
        dfsVisit(e.first, e.second);
      }
    }
    if(w > 0) {
      unsortedWeights.pop_back();
    }
  }

  ~Dfs() {
    this->graph = nullptr;
    isVisited.clear();
    if(DEBUG) {
      cerr<<"destructing the dfs object\n";
    }
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int T;
  cin>>T;
  while(T--) {
    Graph g;
    g.initGraph();

    Dfs dfs(&g);
    dfs.dfsVisit(g.u, 0);
    cout<<dfs.result()<<"\n";
  }

  return 0;
}
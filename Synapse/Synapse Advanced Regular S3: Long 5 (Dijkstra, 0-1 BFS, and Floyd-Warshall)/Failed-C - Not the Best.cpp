#include <bits/stdc++.h>
using namespace std;

#define IS_ONE_BASED_INDEXING true
#define DEBUG false
#define DIRECTED false

class Graph {
private:
  
public:
  int N, M;
  vector<vector<pair<int, int> > > g;
  
  Graph() {}

  void initGraph() {
    cin>>N>>M;
    // isVisited.resize(N+1, false);

    g.resize(N+10);
    
    if(DEBUG) { cerr<<"initGraph 1\n"; }

    int u, v, w;
    for(int i=0; i<M; i++) {
      cin>>u>>v>>w;

      if(DEBUG) { cerr<<"initGraph 2\n"; }

      if(IS_ONE_BASED_INDEXING) {
        u--;
        v--;
      }
      g[u].push_back({v, w});
      if(DEBUG) { cerr<<"initGraph 4\n"; }
      
      if(!DIRECTED) {
        g[v].push_back({u, w});
        if(DEBUG) { cerr<<"initGraph 5\n"; }
      }
      if(DEBUG) { cerr<<"initGraph 6\n"; }

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

  int distance = 0;
  priority_queue<int> pq;

public:
  Dfs(Graph *g) {
    this->graph = g;
    isVisited.resize(this->graph->N+1, false);
  
    distance = 0;
  }

  void dfs() {
    for(int u=0; u<graph->N; u++) {
      if(!isVisited[u]) {
        dfsVisit(u);
      }
    }
  }

  void dfsVisit(const int& u) {
    if(DEBUG) {
      cerr<<"Visiting "<<u<<"\n";
    }
    
    isVisited[u] = true;
    int v, w;
    for(auto edge: this->graph->g[u]) {
      v = edge.first;
      w = edge.second;

      if(!isVisited[v]) {
        distance += w;
        if(v == graph->N-1) {
          pq.push(-distance);
        }
        dfsVisit(v);
        distance -= w;
      }
    }
    isVisited[u] = false;
  }

  int secondBestDistance() {
    while (!pq.empty()){
      cout<<-pq.top()<<" ";
      pq.pop();
    }

    cout<<"\n";
    
    return -1;
    // if(pq.empty()) {
    //   return -1;
    // }
    // pq.pop();
    // if(pq.empty()) {
    //   return -1;
    // }
    // return pq.top();
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

  int T, N, R;
  cin>>T;
  for(int t = 1; t <= T; t++) {
    Graph g;
    g.initGraph();

    Dfs dfs(&g);
    dfs.dfsVisit(0);
    cout<<"Case "<<t<<": "<<dfs.secondBestDistance() <<"\n";
  }

  return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define IS_ONE_BASED_INDEXING false
#define DEBUG true
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

    g.resize(N+1);

    int u, v, w;
    for(int i=0; i<M; i++) {
      cin>>u>>v>>w;
      // if(IS_ONE_BASED_INDEXING) {
      //   u--;
      //   v--;
      // }
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

public:
  Dfs(Graph *g) {
    this->graph = g;
    isVisited.resize(this->graph->N+1, false);
  }

  void dfs() {
    for(int u=0; u<graph->N; u++) {
      if(!isVisited[u]) {
        dfsVisit(u);
      }
    }
  }

  void dfsVisit(const int& u) {
    isVisited[u] = true;
    if(DEBUG) {
      cerr<<"Visiting "<<u<<"\n";
    }


    for(auto v: this->graph->g[u]) {
      if(!isVisited[v.first]) {
        dfsVisit(v.first);
      }
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

class Bfs{
private:
  Graph *graph = nullptr;
  vector<bool> isVisited;
  queue<pair<int, int> > q;

public:
  Bfs(Graph *g) {
    this->graph = g;
    this->isVisited.resize(this->graph->N+1, false);
  }

  void bfs() {
    for(int i=0; i<graph->N; i++) {
      if(!isVisited[i]) {
        bfsVisit(i);
      }
    }
  }

  void bfsVisit(int node) {
    q.push({node, 0});

    while (!q.empty()) {
      /* code */
      auto p = q.front();
      q.pop();

      int u = p.first;
      int depth = p.second;
      int nextDepth = depth + 1;
      isVisited[u] = true;

      if(DEBUG) {
        cerr<<"bfs visiting node = "<<u<<", depth =  "<<depth<<"\n";
      }

      for(auto v: graph->g[u]) {
        if(!isVisited[v.first]) {
          q.push({v.first, nextDepth});
        }
      }
    }
  }

  ~Bfs() {
    this->graph = nullptr;
    isVisited.clear();
    if(DEBUG) {
      cerr<<"destructing the bfs object\n";
    }
  }
};


/**
 * @brief 
 * finds the shortest path from *one* source node to all other nodes
 * 
 * @input
 * G = (V, E), source s
 * 
 * @output:
 * for all nodes u reachable from s, return dist(u), and path P(s, ..., ,p(p(u)), p(u), u)
 * 
 * 
 * for all u in V
 *    dis[u] = INT
 *    prev[u] = null
 * 
 * dis[s] = 0
 * 
 * H = priorityQueue(V) using dist-value as key
 * 
 * while(H!=empty) {
 *    u = deleteMon(H)
 *    for(all edges (u, v) in E) {
 *        if( dis[u] + w(u,v) <  dis[v] ) {
 *        
 *          dis[v] = dis[u] + w(u,v)
*            prev[v] = u
            decreaseKy(H, v)
 *        } 
 *    }
 * 
 * 
 * }
 * 
 * @procedure
 * 
 */
class Djkstra {
private:
  Graph *graph = nullptr;
  vector<int> isVisited;
  vector<int> distance;
  vector<int> parent;
  
  int src = 0;

  // for sparce graph
  set<pair<int, int> > s;
    
public:
  Djkstra(Graph *graph, int src) {
    this->graph = graph;
    this->src = src;

    int n = graph->N;
    int inf = 100000;
    distance.resize(n+1, inf);
    isVisited.resize(n+1, false);
    parent.resize(n+1, INT_MAX);

    distance[this->src] = 0;
    parent[this->src] = -1;
  }

  /**
   * @brief 
   * to my futute self: you've probably forgotten what is happening here.
   * 
   * Don't try to reinvent the wheel.
   * 
   * 1st I wrote relaxationNormal(u)
   * 
   * next I wrote findCurrentMinimaAndRelaxationNormal() to find the node with minimum distance.
   * 
   * Finally, I wrote djkstraNormal(), bcz we need to find distance for all nodes.
   * 
   */
  void djkstraNormal() {
    for(int i=0; i<graph->N; i++) {
      findCurrentMinimaAndRelaxationNormal();
    }

  }

  void findCurrentMinimaAndRelaxationNormal() {
    int curr = -1;
    for(int i=0; i<graph->N; i++) {
      if(!isVisited[i]) {
        if(curr == -1) {
          curr = i;
        } else if(distance[i] < distance[curr]) {
          curr = i;
        }
      }
    }

    relaxationNormal(curr);
  }

  void relaxationNormal(const int& u) {
    // cout<<"relaxing "<<u<<"\n";
    isVisited[u] = true;
    int v, w;
    for(auto edge: graph->g[u]) {
      v = edge.first;
      w = edge.second;
      // cout<<"u = "<<u<<" v = "<<v<<" w = "<<w<<" dis[u] = "<<distance[u]<<" dis[v] = "<<distance[v]<<"\n";
      if(distance[u] + w < distance[v]) {
        distance[v] = distance[u] + w;
        parent[v] = u;
      }
    }
  }


  void djkstraUsingSet() {
    s.insert({distance[src], src});

    while(!s.empty()) {
      int u = s.begin()->second;
      s.erase({distance[u], u});
      relaxationUsingSet(u);
    }
  }

  void relaxationUsingSet(const int& u) {
    int v, w;
    for(auto edge: graph->g[u]) {
      v = edge.first;
      w = edge.second;

      if(distance[u] + w < distance[v]) {
        s.erase({distance[v], v});
        distance[v] = distance[u] + w;
        parent[v] = u;
        s.insert({distance[v], v});
      }
    }
  }

  void printer() {
    cout<<"Distances\n";
    for(int i=0; i<graph->N; i++) {
      cout<<i<<" "<<distance[i]<<"\n";
    }

    cout<<"Parents\n";
    for(int i=0; i<graph->N; i++) {
      cout<<i<<" "<<parent[i]<<"\n";
    }
    cout<<"Paths\n";
    for(int i=0; i<graph->N; i++) {
      cout<<i<<": "; path(i); cout<<"\n";
    }
  }

  void path(const int& u) {
    if(u < 0) {
      return;
    }
    path(parent[u]);
    cout<<"->"<<u;
  }

  ~Djkstra() {
    this->graph = nullptr;
    isVisited.clear();
    distance.clear();
    parent.clear();

    if(DEBUG) {
      cerr<<"destructing the Djkstra object\n";
    }
  }
};


void prototype(Graph *graph) {
    // Dfs dfs(graph);
    // dfs.dfs();

    // Bfs bfs(graph);
    // bfs.bfs();

    Djkstra djkstra(graph, 0);
    // djkstra.printer();
    djkstra.djkstraUsingSet();
    djkstra.printer();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  Graph graph;
  graph.initGraph();

  prototype(&graph);

  return 0;
}
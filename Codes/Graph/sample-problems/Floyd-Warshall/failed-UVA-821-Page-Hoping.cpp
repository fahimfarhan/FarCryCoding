#include <bits/stdc++.h>
using namespace std;

#define IS_ONE_BASED_INDEXING false
#define DEBUG true
#define DIRECTED false
#define IS_WEIGHTED false

#define LOCAL_INF 10001

class FloydWarshall {
private:
  vector<pair<int, int> > edges;
  int graph[101][101];
  int maximus = -1;
  int numberOfEdges = 0;
  int numberOfNodes = 0;

  int isNode[101] = {0};

public:
  FloydWarshall() {}

  bool pageHoping(const int& t) {
    for(int i = 0; i<101; i++) {
      for(int j=0; j<101; j++) {
        graph[i][j] = LOCAL_INF;
      }
    }

    int u, v;
    numberOfEdges = 0;
    while( (cin>>u>>v) && (u!=0 && v!=0) ) {
      graph[u][v] = 1; // not the other way around since this is a directed graph
      isNode[u] = 1;
      isNode[v] = 1;
      numberOfEdges++;    
    }

    if(numberOfEdges == 0) {
      return false;
    }

    for(int i=1; i <101; i++) {
      if(isNode[i]) {
        numberOfNodes++;
        maximus = i;
      }
    }

    // apply floyd warshall
    for(int k=1; k<=maximus; k++) {
      if(!isNode[k]) {
        continue;
      }
      for(int i=1; i<=maximus; i++) {
        if(!isNode[i]) {
          continue;
        }
        for(int j=1; j<=maximus; j++) {
          if(!isNode[j]) {
            continue;
          }
          if(graph[i][k] + graph[k][j] < graph[i][j]) {
            graph[i][j] = graph[i][k] + graph[k][j];
          }
        }
      }
    }

    // totalNumOfPairs =  denominator = maximus P 2 = 
    int numOfPairs = (maximus * (maximus - 1)); // nPr = n! / (n-r)!
    

    int sumOfWeights = 0;
    for(int i=1; i<=maximus; i++) {
      for(int j=1; j<=maximus; j++) {
        if( (i != j) && (graph[i][j] != LOCAL_INF) ) {
          sumOfWeights += graph[i][j];
        }
      }  
    }

    double average = (sumOfWeights + 0.0) / numOfPairs;

    if(DEBUG) {
      cout<<"sumOfWeights "<<sumOfWeights<<" numOfPairs "<<numOfPairs<<" average "<<average<<"\n";
    }


    cout<<"Case "<<t<<": average length between pages = "<<average<<" clicks\n";
    return true;
  }

  ~FloydWarshall() {}
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t = 0;
  while(true) {
    t++;
    FloydWarshall fw;
    bool b = fw.pageHoping(t);
    if(!b) {
      break;
    }
  }

  return 0;
}
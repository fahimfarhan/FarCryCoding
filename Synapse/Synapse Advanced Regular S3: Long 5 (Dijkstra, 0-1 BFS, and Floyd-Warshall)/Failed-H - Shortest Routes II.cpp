#include <bits/stdc++.h>
using namespace std;

#define debug false
#define ll long long int

ll w[505][505];

#define inf 1000000001


ll n, m, q, a, b, c;


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin>>n>>m>>q;

  for(int i=0; i<505; i++) {
    for(int j=0; j<505; j++) {
      w[i][j] = inf;
    }
  }

  for(int i=0; i<=n; i++) {
    w[i][i] = 0;    // <------- this helped me to pass test cases 6, 7, 8
  }

  for(int i=0; i<m; i++) {
    cin>>a>>b>>c;
    w[a][b] = min(w[a][b], c);   // <-- this solved test cases 9, 10
    w[b][a] = min(w[b][a], c);   // <-- this solved test cases 9, 10
  }


  // preprocess all pair shortest paths
  for(int k=1; k<=n; k++) {
    for(int i=1; i<=n; i++) {
      for(int j=1; j<=n; j++) {
        if( (w[i][k] < inf) && (w[k][j] < inf) ) {
          w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
        }
      }
    }
  }


  if(debug) {
    for(int i=0; i<6; i++) {
      for(int j=0; j<6; j++) {
        cout<<w[i][j]<<" ";
      } cout<<"\n";
    }  
  }


  // answer queries in constant time
  for(int t=0; t<q; t++) {
    cin>>a>>b;
    if( (w[a][b] > inf) || (w[a][b] >= abs(inf)) || (w[a][b] < 0) ) {
      cout<<-1<<"\n";
    } else {
     cout<<w[a][b]<<"\n";
    }

  }

  return 0;
}
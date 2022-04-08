#include <bits/stdc++.h>
using namespace std;

int g[5][5] = {
  {0,1,1,0,1 },
  {1,0,1,0,1 },
  {1,1,0,1,1 },
  {0,0,1,0,1 },
  {1,1,1,1,0 }
};

int result[9] = {0};

void backTrack(int indexForResult, int u) {
  result[indexForResult] = u;
  if(indexForResult == 8) {
    for(int i=0; i<9; i++) {
      cout<<(result[i]+1)<<"";  // plus one to convert from zero based into one based indexing
    }
    cout<<"\n";
    return;
  }


  for(int i=0; i<5; i++) {
    if(g[u][i] == 1) {
      g[u][i] = 0;
      g[i][u] = 0;

      backTrack(indexForResult+1, i);

      g[u][i] = 1;
      g[i][u] = 1;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  backTrack(0,0);


  return 0;
}
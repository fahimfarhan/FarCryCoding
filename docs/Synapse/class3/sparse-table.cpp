#include <bits/stdc++.h>
using namespace std;


/**
 * @brief 
 * @param left0 = Q[l, r], the left limit 
 * @param len = r - l + 1
 * @return int 
 */
int f(int **st, const int& left0, const int& len) {
  if(len == 0) {  // base case
    return INT_MAX;
  }
  int msb = log2(len);
  int j = 1 << msb;
  int nextLen = len - j;
  int nextleft0 = left0 + j;

  int temp = st[msb][left0];

  int minimus = min(temp, f(st, nextleft0, nextLen));
  return minimus;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  bool debug = false;

  int N, x, Q, l1, r1, l0, r0, result, len;
  vector<int> a;

  cin>>N;
  
  int lgN = ceil(log2f(N));
  int araSize = 1 << lgN;
  
  a.resize(araSize, INT_MAX);  // since we want the ranged minimum!

  for(int i=0; i<N; i++) {
    cin>>a[i];
  }

  // todo: preprocess
  int **st;
  st = new int*[lgN+1];    // <---------  lgN + 1,  Watch out!
  for(int i=0; i<=lgN; i++) {  // <----- i<=lgN,  Watch out!
    st[i] = new int[N+1];
  }

  // base case:
  for(int i=0; i<N; i++) {
    st[0][i] = a[i];
  }
  
  // recursive cases

  for(int i=1; i<=lgN; i++) {   // <--- i <= lgN, watch out!
    for(int j=0; j<N; j++) {
      // st[i][j] = min( st[i-1][j] , st[i-1][j + (int)pow(2, i-1) + 1] );
      st[i][j] = min( st[i-1][j] , st[i-1][j + 1 + (1 << (i-1) ) ] );
    }
  }

  // debug
  if(debug) {
    for(int i=0; i<=lgN; i++) {   // <--- i <= lgN, watch out!
      for(int j=0; j<N; j++) {
      // st[i][j] = min( st[i-1][j] , st[i-1][j + (int)pow(2, i-1) + 1] );
      // st[i][j] = min( st[i-1][j] , st[i-1][j + 1 + (1 << (i-1) ) ] );
        cout<<st[i][j]<<" ";
      }cout<<"\n";
    }
  }


  // todo: queries

  cin>>Q;
  for(int q=0; q<Q; q++) {
    cin>>l1>>r1;
    l0 = l1 - 1;
    r0 = r1 - 1;

    len = r0 - l0 + 1;
    result = f(st, l0, len);
    cout<<result<<"\n";
  }

  for(int i=0; i<lgN; i++) {
    delete[] st[i];
  } delete[] st;

  return 0;
}
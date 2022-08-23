#include <bits/stdc++.h>
using namespace std;

int main() {

  int N, *a, **st;
  cin>>N;
  int K = ceil(log2(N));

  // cout<<K<<"\n";
  a = new int[N+1];
  st = new int*[K];
  for(int i=0; i<K; i++) {
    st[i] = new int[N];
  }

  for(int i=0; i<N; i++) {
    cin>>a[i];
  }

  // preprocess
  for(int i=0; i<N; i++) {
    st[0][i] = a[i];
  }

  for(int len=1; len<K; len++) {
    for(int j=0; j<N; j++) {
      int rightStart = (j + 2 << len);
      if( rightStart > N  ) {
        break;
      }

      st[len][j] = min( st[len-1][j] , st[len-1][rightStart] );
    }
  }

  int Q;
  cin>>Q;

  int l, r;
  int answer = INT_MAX;
  for(int q=0; q<Q; q++) {
    /* code */
    cin>>l>>r;
    l--;
    r--;

    answer = INT_MAX;

    for(int k = K-1; k>=0; k--) {
      if ((1 << k) <= (r - l + 1) ) {
        answer = min(answer, st[k][l]);
        l += (1 << k);
      }
    }
  
    cout<<"ans = "<<answer<<"\n";
  
  }
  



  for(int i=0; i<K; i++) {
    delete[] st[i]; //  = new int[N];
  }

  delete[] st;

  delete[] a;
  return 0;
}
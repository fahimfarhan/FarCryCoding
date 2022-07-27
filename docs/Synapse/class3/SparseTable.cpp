#include <bits/stdc++.h>
using namespace std;

int main() {

  int N, *a, **st;
  cin>>N;
  float K = ceil(log2(N));

  cout<<K<<"\n";
  a = new int[N+1];
  st = new int*[K];
  for(int i=0; i<K; i++) {
    st[i] = new int[N];
  }

  for(int i=0; i<N; i++) {
    cin>>a[i];
  }

  // preprocess



  for(int i=0; i<K; i++) {
    delete[] st[i]; //  = new int[N];
  }

  delete[] st;

  delete[] a;
  return 0;
}
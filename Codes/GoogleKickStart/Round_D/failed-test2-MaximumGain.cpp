#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll T, N, *A, M, *B, k;
  ll maximus = 0;

  cin>>T;
  for(int t = 1; t <= T; t++) {
    cin>>N;
    A = new ll[N+1];
    for(int i=0; i<N; i++) {
      cin>>A[i];
    }

    cin>>M;
    B = new ll[M+1];
    for(int i=0; i<M; i++) {
      cin>>B[i];
    }

    cin>>k;

    sort(A, A+N);
    sort(B, B+M);

    int i = N - 1;
    int j = M - 1;
    maximus = 0;

    while( (k > 0) && (i >= 0) && (j >= 0) ) {
      if(A[i] >= B[j]) {
        maximus += A[i];
        i--;
      } else {
        maximus += B[j];
        j--;
      }
      k--;
    }

    if(k > 0) {
      if(j >= 0) {
        while( (k > 0) && (j >= 0) ) {
          maximus += B[j];
          j--;
          k--;
        }        
      } else if(i >= 0) {
        while( (k > 0) && (i >= 0) ) {
          maximus += A[i];
          i--;
          k--;
        }        
      }
    }    

    cout<<"Case #"<<t<<": "<<maximus<<"\n";

    delete[] B;
    delete[] A;
  }

  return 0;
}
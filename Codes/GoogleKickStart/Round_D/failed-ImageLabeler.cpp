#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll T, N, M, delta, mid, *A;
  double successMetric = 0;

  cin>>T;
  for(int t = 1; t <= T; t++) {
    cin>>N>>M;
    A = new ll[N+1];

    for(int i=0; i<N; i++) {
      cin>>A[i];
    }

    sort(A, A + N);
    delta = N - (M - 1);

    successMetric = 0;
    for(int i=delta; i<N; i++) {
      successMetric += A[i];
    }

    // cerr<<successMetric<<"\n";

    mid = delta >> 1;
    if( (delta&1) == 1) {
      successMetric += A[mid];
      // cerr<<"here 1 "<<successMetric<<"\n";
    } else {
      successMetric += 0.5*( A[mid] + A[(mid - 1)] );
      // cerr<<"here 2 "<<successMetric<<"\n";
    }
    
    cout<<"Case #"<<t<<": "<<successMetric<<"\n";

    delete[] A;
  }

  return 0;
}
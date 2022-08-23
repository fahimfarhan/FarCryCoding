#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int N, Q, l1, r1, l0, r0, result;
  vector<int> a;
  cin>>N;

  for(int i=0; i<N; i++) {
    cin>>Q;
    a.push_back(Q);
  }

  cin>>Q;
  for(int q=0; q<Q; q++) {
    cin>>l1>>r1;
    l0 = l1 - 1;
    r0 = r1 - 1;


    result = INT_MAX;
    for(int i=l0; i<=r0; i++) {
      result = min(result, a[i]);
    }

    cout<<result<<"\n";
  }

  // int lgN = ceil(log2f(5));
  // cout<<ceil(log2(5))<<"\n"; // 2.sth = 3
  // cout<<ceil(log2(4))<<"\n"; // 2
  

  return 0;
}
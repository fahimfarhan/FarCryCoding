#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll T, N, M, k, maximus;
  vector<ll> v;

  cin>>T;
  for(int t = 1; t <= T; t++) {
    v.clear();
    cin>>N;
    for(int i=0; i<N; i++) {
      cin>>k;
      v.push_back(k);
    }    

    cin>>M;
    for(int i=0; i<M; i++) {
      cin>>k;
      v.push_back(k);
    }
    cin>>k;

    sort(v.begin(), v.end());

    int idx = v.size() - 1;
    maximus = 0;

    while (k > 0) {
      /* code */
      maximus += v[idx];
      idx--;
      k--;
    }

    cout<<"Case #"<<t<<": "<<maximus<<"\n";


    v.clear();
  }


  return 0;
}
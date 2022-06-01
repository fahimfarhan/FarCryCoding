#include <bits/stdc++.h>
using namespace std;

#define ll int


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll n, m, k, sqr, *a;
  vector<int> *blocks;

  cin>>n>>m>>k;
  a = new int[n+1];
  sqr = ceil(sqrt(n+0.0));
  blocks = new vector<int>[sqr+1];

  for(int i=0; i<n; i++) {
    cin>>a[i];
  }

  ll l, r;
  while(m--) {
    cin>>l>>r;
    l--; r--;
    // todo: logic - tobe continued... ... ...
  }

  delete[] a;
  delete[] blocks;

  return 0;
}
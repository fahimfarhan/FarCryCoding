#include <bits/stdc++.h>
using namespace std;


int N,  Q, l1, r1, l0, r0;
int a[30000+5] = {0};


void start() {
  cin>>N;
  for(int i=0; i<N; i++) {
    cin>>a[i];
  }

  cin>>Q;
  for(int i=0; i<Q; i++) {
    cin>>l1>>r1;
    l0 = l1 - 1;
    r0 = r1 - 1;

    unordered_set<int> us;

    for(int j = l0; j <= r0; j++) {
      us.insert(a[j]);
    }

    cout<<us.size()<<"\n";
  }

}


int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int T;
  cin>>T;
  for(int t = 0; t < T; t++) {
    start();
    cout<<"\n";
  }

  return 0;
}
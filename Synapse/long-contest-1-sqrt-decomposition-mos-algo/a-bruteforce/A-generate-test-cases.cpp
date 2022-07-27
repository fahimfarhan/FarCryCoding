
#include <bits/stdc++.h>
using namespace std;



int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int T = 10;
  int N[10] = {10, 100, 200, 300, 400, 5000, 7000, 10000, 20000, 30000};

  int Q[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 200000};

  int a = 1, b = 1000000, rdno;
  int l = 1, r;
  int l1, r1;

  cout<<T<<"\n";

  for(int t = 0; t < T; t++) {
    
    cout<<N[t]<<"\n";

    for(int i=0; i<N[t]; i++) {
      rdno = rand() % (b-a) + a;
      cout<<rdno<<" ";
    }cout<<"\n";
  
    cout<<Q[t]<<"\n";

    r = N[t];
    for(int i=0; i<Q[t]; i++) {
      l1 = rand() % (r - l) + l;
      r1 = rand() % (r - l) + l;
    
      if(l1 > r1) {
        swap(l1, r1);
      }

      cout<<l1<<" "<<r1<<"\n";
    }
  
  }

  return 0;
}
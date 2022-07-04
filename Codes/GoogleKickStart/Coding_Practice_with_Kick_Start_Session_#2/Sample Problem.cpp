#include <bits/stdc++.h>
using namespace std;

int main() {
  int T, N, M;
  int Ci = 0, sum = 0, remainder;
  cin>>T;
  for(int t = 1; t<=T; t++) {
    cin>>N>>M;
    sum = 0;
    for(int i=0; i<N; i++) {
      cin>>Ci; sum += Ci;
    }

    remainder = sum % M;
    cout<<"Case #"<<t<<": "<<remainder<<"\n";
  }
  return 0;
}
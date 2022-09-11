#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int T, N, M, remainder, C[100000+5] = {0};

  cin>>T;
  for(int t = 1; t <= T; t++) {
    cin>>N>>M;
    for(int i=0; i<N; i++) {
      cin>>C[i];
    }
    remainder = 0;

    int option = 1;

    if(option == 1) {
      for(int i=0; i<N; i++) {
        remainder += C[i]; // faster, but may get overflow error
      }

      remainder%=M;
    } else {
        for(int i=0; i<N; i++) {
          remainder = (remainder + C[i]) % M; // faster, but may get overflow error
        }
    }



    cout<<"Case #"<<t<<": "<<remainder<<"\n";
  }
  return 0;
}
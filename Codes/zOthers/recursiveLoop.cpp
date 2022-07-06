#include <bits/stdc++.h>
using namespace std;



void recursiveLoop(const int& i,const int& endExclusive) {
  if(i == endExclusive) {
    return;
  } 
  cout<<i<<"\n";
  int next = i + 1;
  recursiveLoop(next, endExclusive);
}

void recursiveLoopV2(const int& i, const int& startInc) {
  if(i < startInc) {
    return;
  }
  int next = i - 1;
  recursiveLoopV2(next, startInc);
  cout<<i<<"\n";
}

int main() {
  int startInc = 0;
  int endEx = 10;
  cout<<"Using for loop\n";
  for(int i=startInc; i<endEx; i++) {
    cout<<i<<"\n";
  }
  cout<<"Using recursion loop v1\n";
  recursiveLoop(startInc, endEx);
  cout<<"Using recursion loop v2\n";
  recursiveLoopV2((endEx-1), startInc);
  return 0;
}
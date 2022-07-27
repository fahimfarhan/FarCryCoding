#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll N, *a, Q, l1, r1;  // warning! L, R are in one based indexing
int l0, r0;
int sqrtN;
int blockSize;
int blockCount;

int startBlockInclusive = 0, endBlockInclusive = 0;
unordered_set<ll> *us;

#define DEBUG false

inline void preprocess() {
  sqrtN = sqrt(N);
  blockSize = sqrtN;
  blockCount = ceil( (0.0+N) /blockSize);  // don't miss the 0.0 + N to prevent precision loss.

  us = new unordered_set<ll>[blockCount+1];

  int nextBlockStart = blockSize;
  int b = 0;
  for(int i=0; i<N; i++) {
    if(i == nextBlockStart) {
      b++;
      nextBlockStart+=blockSize;
    }
    us[b].insert(a[i]);
  }

  if(DEBUG) {
    cerr<<"blockSize = "<<blockSize<<", blockCount = "<<blockCount<<"\n";
    for(int i=0; i<blockCount; i++) {
      cerr<<"us["<<i<<"] = "<<us[i].size()<<"\n";
    }


    for(int i=0; i<blockCount; i++) {
      for(auto it = us[i].begin(); it != us[i].end(); it++ ) {
        cerr<<"d: "<<*it<<", ";
      } 
      cerr<<"\n"; 
    }
    cerr<<"\n----------------------------\n";
  }  
}

int dQuery() {
  // int left, mid, right;

  unordered_set<ll> leftSet;
  unordered_set<ll> rightSet;


  // calculate for the left point
  if( (l0 % blockSize) == 0) {
    startBlockInclusive = l0/blockSize;
    leftSet.clear();
  } else {
    startBlockInclusive = ceil( (l0+0.0)/blockSize );
    int lEnd = startBlockInclusive * blockSize;

    for(int i=l0; i<lEnd; i++) {
      leftSet.insert(a[i]);
    } 
  }

  // for right points
  int rightBlock = r0 / blockSize;
  int firstIndexOfRightBlock = rightBlock * blockSize;
  int lastIndexOfRightBlock = firstIndexOfRightBlock + blockSize - 1;

  // cerr<<"r0 = "<<r0<<" "<<"lastIndexOfRightBlock = "<<lastIndexOfRightBlock<<"\n";
  if(r0 == lastIndexOfRightBlock) {
    rightSet.clear();
    endBlockInclusive = rightBlock;
  } else {
    endBlockInclusive = rightBlock - 1;

    for(int i = firstIndexOfRightBlock; i <= r0; i++) {
      rightSet.insert(a[i]);
    }
  }  

  // set theory, n(AUBUC) = nA + nB + nC - nAB - nAC - nBC + nABC. 
  unordered_set<int> result;
  for(auto it = leftSet.begin(); it != leftSet.end(); it++) {
      // cerr<<"inserting1 "<<*it<<", ";
    result.insert(*it);
  }

  // cerr<<"start = "<<startBlockInclusive<<"end = "<<endBlockInclusive<<"\n";

  for(int i=startBlockInclusive; i <= endBlockInclusive; i++) {
    for(auto it = us[i].begin(); it != us[i].end(); it++ ) {
      // cerr<<"inserting2 "<<*it<<", ";
      result.insert(*it);
    }
  }

  for(auto it = rightSet.begin(); it != rightSet.end(); it++) {
    // cout<<"inserting3 "<<*it<<", ";
    result.insert(*it);
  }

  if(DEBUG) {
    for(auto i: result) {
      cerr<<"p "<<i<<", ";
    }cerr<<"\n";
  }

  return result.size();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin>>N;
  a = new ll[N+1];
  for(int i=0; i<N; i++) {
    cin>>a[i];
  }

  preprocess();

  cin>>Q;
  for(int q=0; q<Q; q++) {
    cin>>l1>>r1;
    l0 = l1 - 1;
    r0 = r1 - 1;    

    cout<<dQuery()<<"\n";
  }

  return 0;
}
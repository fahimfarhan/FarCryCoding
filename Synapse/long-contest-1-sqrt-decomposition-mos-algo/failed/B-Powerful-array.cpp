#include <bits/stdc++.h>
using namespace std;

#define ll long long int

#define MAX_N 200000
#define SQRT_MAX_N 500

int N, Q, l0, r0, l1, r1; 
ll *a;

int sqrtN;
int blockSize;
int blockCount;

unordered_map<ll, ll> *mp;

inline void preprocess() {
  sqrtN = SQRT_MAX_N; // sqrt(N);
  blockSize = sqrtN;
  blockCount = ceil( (N+0.0)/blockSize );

  mp = new unordered_map<ll, ll>[blockCount+1];

  int startNextBlock = blockSize;
  int currBlock = 0;
  int s = 0;

  for(int i=0; i<N; i++) {
    if(i == startNextBlock) {
      startNextBlock += blockSize;
      currBlock++;
    }

    s = a[i];
    mp[currBlock][s]++;
  }
}

ll powerfulArray() {
  unordered_map<ll, ll> mapOfKsForS;
  int startBlockInc = 0, endBlockInc = 0;
  int s = 0;
  // left 
  if( (l0 % blockSize) != 0) {
    startBlockInc = ceil((0.0+l0) / blockSize);
    int firstIndexOfStartBlock = startBlockInc * blockSize;
    for(int i=l0; i < firstIndexOfStartBlock; i++) {
      s = a[i];
      if(s!=0) {

        if(mapOfKsForS.find(s) == mapOfKsForS.end()) { // does not exist
          mapOfKsForS[s] = 1;
        } else {
          mapOfKsForS[s]++;        
        }
      }
    }
  } else {
    startBlockInc = l0 / blockSize;
  }

  // right
  endBlockInc = r0/blockSize;
  int firstIdxOfEndBlock = endBlockInc * blockSize;
  int lastIdxOfEndBlock = firstIdxOfEndBlock + blockSize - 1;

  if(r0 != lastIdxOfEndBlock) {
    endBlockInc--;
    for(int i=firstIdxOfEndBlock; i <= r0; i++) {
      s = a[i];
      if(s!=0) {
        if(mapOfKsForS.find(s) == mapOfKsForS.end()) { // does not exist
          mapOfKsForS[s] = 1;
        } else {
          mapOfKsForS[s]++;        
        }
      }
    }
  }

  // middle
  
  int KsInABlock = 0;
  
  
  for(int i=startBlockInc; i <= endBlockInc; i++) {
    for(auto it = mp[i].begin(); it != mp[i].end(); it++) {
      s = it->first;
      KsInABlock = it->second;
      if(s != 0) {
        if(mapOfKsForS.find(s) == mapOfKsForS.end()) { // does not exist
          mapOfKsForS[s] = KsInABlock;
        } else {
          mapOfKsForS[s] += KsInABlock;    
        }    
      }    
    }
  }
  // result
  ll result = 0;

  ll Ks = 0;
  for(auto it = mapOfKsForS.begin(); it != mapOfKsForS.end(); it++) {
    s = it->first;
    Ks = it->second;

    cerr<<"s1: s ="<<s<<" ks = "<<Ks<<"\n";

    result += (Ks * Ks * s);
  }

  return result;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  cin>>N>>Q;
  a = new ll[MAX_N + 1];
  for(int i=0; i<N; i++) {
    cin>>a[i];
  }

  preprocess();

  for(int q = 0; q < Q; q++) {
    cin>>l1>>r1;
    l0 = l1-1;
    r0 = r1-1;
    cout<<powerfulArray()<<"\n";
  }
  
  return 0;
}
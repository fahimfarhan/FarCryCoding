/**
 * https://github.com/krnbatra/SPOJ-Solutions/blob/master/GIVEAWAY.cpp
 * 
*/

#include <bits/stdc++.h>
using namespace std;

#define ll int // long long int
#define io   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define SIZE_N 500000+5
#define SQRT 710 // 707.1068
vector<int> b[SQRT];

ll a[SIZE_N] = {0};

inline void preprocess(const ll& n) {
  for(int i=0; i<n; i++) {
    b[i/SQRT].push_back( a[i] );
  }

  ll newBlocks = ceil((n+0.0)/SQRT);
  for(int i = 0; i < newBlocks; i++) {
    sort(b[i].begin(), b[i].end());
  }
}

void update(const ll& idx, const ll& newVal) {
  if(a[idx] == newVal) return;
  ll oldVal = a[idx];
  a[idx] = newVal;

  ll block = idx/SQRT;

  int lo = 0, hi = b[block].size() - 1, mid = 0;
  while(lo <= hi) {
    mid = (lo + hi) >> 1;
    if(b[block][mid] == oldVal) {
      b[block][mid] = newVal;
      break;
    } else if(b[block][mid] < oldVal) {
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  sort(b[block].begin(), b[block].end());
}

ll query(const ll& l, const ll& r, const ll& c) {
  ll result = 0;

  ll leftBlock = l / SQRT;
  ll rightBlock = r / SQRT;

  if(leftBlock == rightBlock) {
    for(int i=l; i<=r; i++) {
      if(a[i] >= c)
        result++;
    }
  } else {
    if(l % SQRT != 0) {
      leftBlock++;
    }


    for(int i=l; i < leftBlock * SQRT; i++) {
      if(a[i] >= c)
        result++;
    }

    for(int i = leftBlock; i<rightBlock; i++) {
      result += b[i].end() - lower_bound(b[i].begin(), b[i].end(), c);
    }

    for(int i=rightBlock * SQRT; i <= r; i++) {
      if(a[i] >= c)
        result++;
    }

  }

  return result;
}

int main() {
  io

  ll n, q;
  cin>>n;

  for(int i=0; i<n; i++) {
    cin>>a[i];
  }

  preprocess(n);

  cin>>q;
  
  ll l, r, c, idx, newVal;
  for(int i=0; i<q; i++) {
    cin>>c;
    if(c == 1) {
      cin>>idx>>newVal;
      // update
      idx--;
      update(idx, newVal);
    } else {
      cin>>l>>r>>c;
      // query
      l--; r--;
      cout<<query(l, r, c)<<"\n";
    }
  }

  return 0;
}
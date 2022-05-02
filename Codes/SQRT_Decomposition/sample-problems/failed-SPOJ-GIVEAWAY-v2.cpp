#include <bits/stdc++.h>
using namespace std;

#define ll int // long long int

#define SIZE_N 500000+5
#define SQRT 710 // 707.1068

ll X[SIZE_N+1] = {0};
ll block[SQRT][SQRT] = {0};

inline void pre_process(const ll& N) {
  int j = 0, k = 0;
  for(int i=0; i<N; i++) {
    block[j][k] = X[i];
    k++;
    if(k == SQRT) {
      k = 0;
      j++;
    }
  }   
  for(int i=0; i<j; i++) {
    sort(block[j], block[j]+SQRT);
  }
}

void update(const ll& a, const ll& b) {
  if(X[a] == b) {
    return;
  }
  
  ll oldValue = X[a];
  X[a] = b;
  ll idx = a / SQRT;

  auto lb = lower_bound(block[idx], block[idx]+SQRT, oldValue);
  int pos = (lb - block[idx]);

  if(oldValue < b) {
    for(int i=pos; i< SQRT-1; i++) {
      if(block[idx][pos] < block[idx][pos+1]) {
        swap(block[idx][pos], block[idx][pos+1]);
      } else {
        break;
      }
    }
  } else {
    for(int i=pos; i > 0; i--) {
      if(block[idx][pos] < block[idx][pos-1]) {
        swap(block[idx][pos], block[idx][pos-1]);
      } else {
        break;
      }
    }
  }

}

ll query(const ll& a, const ll& b, const ll& c) {
  ll result = 0;
  ll lb = a/SQRT;
  ll rb = b/SQRT;

  if(lb == rb) {
    for(int i=lb; i <= rb; i++) {
      if(X[i] >= c) {
        result++;
      }
    }
  } else {
    ll res1 = 0, res2 = 0, res3 = 0;
    int xEndIndexExclusive = (lb+1)*SQRT;
    for(int i=a; i < xEndIndexExclusive; i++) {
      if(X[i] >= c) {
        res1++;
      }
    }

    for(int i = lb; i < rb; i++) {
      auto lb = lower_bound(block[i], block[i]+SQRT, c);
      int pos = lb - block[i];

      if(block[i][pos] == c) {
        // 1,2,3,4,5,6,7,8,9, c = 6, res2 = N{6,7,8,9} = 4. Size = 9, pos(6) = 5. res2 = Size - pos(6) = 9 - 5 = 4
        int r2 = SQRT - pos;
        res2 += r2;
      } else {
        // 1,2,3,4,5,6,7,8,9, c = 5.5, res2 = N{6,7,8,9} = 4. Size = 9, pos_lb(5) = 4. res2 = Size - pos(5) - 1 = 9 - 4 - 1 = 4
        int r2 = SQRT - pos - 1;
        res2 += r2;
      }
    }
    
    int xStartIndexInclusive = rb * SQRT; // sqrt = 7. rb = 0 => xS = 0*7=0, rb = 1 => xS = 1*7 = 7... ...
    for(int i=xStartIndexInclusive; i <= b; i++) {
      if(X[i] >= c) {
        res3++;
      }
    }
    result = res1 + res2 + res3;
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll N, Q;
  ll d, a, b, c, result;

  cin>>N;
  for(int i = 0; i < N; i++) {
    cin>>X[i];
  }

  pre_process(N);

  cin>>Q;
  for(int i = 0; i < Q; i++) {
    cin>>d;
    if(d == 0) {
      cin>>a>>b>>c;
      // query
      a--;
      b--;
      result = query(a, b, c);
      cout<<result<<"\n";
    } else {
      cin>>a>>b;  
      // update
      a--;
      update(a, b);
    }
  }

  return 0;
}
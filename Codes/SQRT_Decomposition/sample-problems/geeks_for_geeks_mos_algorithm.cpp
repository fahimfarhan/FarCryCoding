#include <bits/stdc++.h>
using namespace std;

class Query{
public:
  int l, r, idx; // [l, r]

  Query(int l = 0, int r = 0, int idx = 0) {
    this->l = l;
    this->r = r;
    this->idx = idx;
  }
};

int blockSize = 4;  // sqrt(n)

inline bool comparator(const Query& a, const Query& b) {
  // cerr<<blockSize<<"\n";
  
  int ai = a.l/blockSize;
  int bi = b.l/blockSize;

  if(ai != bi) {  // ie, different blocks, choose left value
    return (ai < bi);
  }

  return (a.r < b.r); // same block, so sort by right value
}

inline void mosAlgorithmV2(vector<int>& input, vector<Query>& queries, vector<int>& result) {
  int N = input.size();
  blockSize = sqrt(N);

  sort(queries.begin(), queries.end(), comparator);

  int linc = 0, rinc = -1 /*why rinc = -1 is explained below. */ , sum = 0;

  for(auto q: queries) {
    int ql = q.l; int qr = q.r;
    // 0 --- linc --- ql --- xr --- N
    // cerr<<"debug1\n";
    while(linc < ql) {
      sum -= input[linc];
      linc++;
    }
    // 0 --- ql --- linc --- xr --- N
    // cerr<<"debug2\n";
    while(ql < linc) {
      linc--;
      sum += input[linc];
    }

    // 0 --- xl --- qr --- rinc --- N
    // cerr<<"debug3\n";
    while(qr < rinc) {
      sum -= input[rinc];
      rinc--;
    }

    // 0 --- xl ---  --- rinc --- qr --- N
    // cerr<<"debug4\n";
    while(rinc < qr) {
      rinc++; // initially if r = 0, => sum = in[0] howar kotha, not 0. so rinc = -1 dile thik hobe.
      sum += input[rinc];
    }

    result[q.idx] = sum;

  }
}

inline void mosAlgorithm(vector<int>& input, vector<Query>& queries, vector<int>& result) {
  int N = input.size();
  blockSize = sqrt(N);

  sort(queries.begin(), queries.end(), comparator);

  int lInclusive = 0, rExclusive = 0, sum = 0;

  for(auto q: queries) {
    int ql = q.l, qr = q.r;

    // 0 --- lInc --- ql --- xr --- N
    while(lInclusive < ql) {
      sum -= input[lInclusive];
      lInclusive++;
    }

    // 0 --- ql --- lInc --- xr --- N
    while(ql < lInclusive) {
      lInclusive--;
      sum += input[lInclusive]; 
    }

    // 0 --- xl --- qr --- rEx -- N
    while(qr < rExclusive-1) {
      sum -= input[rExclusive-1];
      rExclusive--;
    }

    // 0 --- xl --- rEx --- qr -- N
    while(rExclusive <= qr) {
      sum += input[rExclusive];
      rExclusive++;
    }

    result[q.idx] = sum;

  }
}

int main() {
  vector<int> input = {1, 1, 2, 1, 3, 4, 5, 2, 8};
  vector<Query> queries = {Query(0,4,0), Query(1, 3, 1), Query(2,4,2)};
  vector<int> result(queries.size(), 0);
  
  mosAlgorithmV2(input, queries, result);

  for(auto r: result) {
    cout<<r<<"\n";
  }
  
  return 0;
}
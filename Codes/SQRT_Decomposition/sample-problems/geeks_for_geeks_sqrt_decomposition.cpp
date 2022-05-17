#include <bits/stdc++.h>
using namespace std;

class Query{
public:
  int l, r, idx;

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

inline void mosAlgorithm(vector<int>& input, vector<Query>& queries, vector<int>& result) {
  int N = input.size();
  blockSize = sqrt(N);

  sort(queries.begin(), queries.end(), comparator);

  int pl = 0, pr = 0, sum = 0;
  for(auto q: queries) {
    int cl = q.l;
    int cr = q.r;

    // 0 --- pl --- cl --- xr --- N
    while(pl < cl) {
      sum -= input[pl];
      pl++;
    }
    // 0 --- cl --- pl --- xr --- N
    while(cl < pl) {
      pl--;
      sum += input[pl];
    }
/** original, my code
    // 0 --- xl --- pr --- cr --- N
    while(pr < cr) {
      pr++;
      sum += input[pr];
    }
*/

    // 0 --- xl --- cr --- pr --- N
    // while(cr < pr) {
    //   sum -= input[pr];
    //   pr--;
    // }
  //*/

// 0 --- xl --- pr --- cr --- N
  while(pr <= cr) {
    sum += input[pr];
    pr++;
  }

  while(cr + 1 < pr) {
    sum -= input[pr-1];
    pr--;
  }

    result[q.idx] = sum;

     // Print sum of current range
        cout << "Sum of [" << cl << ", " << cr
             << "] is "  << sum << endl;
  }

}

int main() {
  vector<int> input = {1, 1, 2, 1, 3, 4, 5, 2, 8};
  vector<Query> queries = {Query(0,4,0), Query(1, 3, 1), Query(2,4,2)};
  vector<int> result(queries.size(), 0);
  
  mosAlgorithm(input, queries, result);

  for(auto r: result) {
    cout<<r<<"\n";
  }
  
  return 0;
}
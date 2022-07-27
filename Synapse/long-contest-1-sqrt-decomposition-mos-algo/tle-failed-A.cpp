#include <bits/stdc++.h>
using namespace std;

int n, a[30000+5], q, l1, r1, l0, r0;
int result[200000+5] = {0};
int mp[1000000+5] = {0};


int sqrtn = 500; // approx
int blocksize = (30000 / sqrtn);
int answer = 0;

class query{
public:
  int l0, r0, idx;

  query(int l, int r, int i) {
    l0 = l; r0 = r; idx = i;
  }

  query() {
    l0 = 0; r0 = 0; idx = 0;
  }
};

// vector<query> queries;
query queries[200000+5];

bool comparator(const query& f, const query& s) {
  int blockf = (int) (f.idx / blocksize);
  int blocks = (int) (s.idx / blocksize);

  if(blockf != blocks) {
    return blockf < blocks;
  }
  return f.l0 < s.l0;
}

inline void addnumber(const int& idx) {
  mp[a[idx]]++;
  if(mp[a[idx] ] == 1) {
    answer++;
  }
}

inline void removenumber(const int& idx) {
  mp[a[idx]]--;
  if(mp[a[idx] ] == 0) {
    answer--;
  }
}

inline void start() {
  cin>>n;
  
  
  sqrtn = sqrt(n);
  blocksize = n / sqrtn;
  
  for(int i=0; i<n; i++) {
    cin>>a[i];
  }

  cin>>q;
  for(int i=0; i<q; i++) {
    query q;

    cin>>q.l0>>q.r0;
    // l0 = l1 - 1;
    // r0 = r1 - 1;
    q.l0--;
    q.r0--;

    q.idx = i;
    // query q(l0, r0, i);
    queries[i] = q;
  }

  
  
  sort(queries, queries + q, comparator);


  answer = 0;
  for(int i = queries[0].l0; i <= queries[0].r0; i++) {
    addnumber(i);
  }

  result[queries[0].idx] = answer;


  int pl = queries[0].l0;
  int pr = queries[0].r0;

  for(int j = 1; j<q; j++) {
    auto qc = queries[j];
    // auto qp = queries[j-1];

    // ---- qc.l --- qc.r --- qp.l ################### qp.r ---
    // ---- qp.l ### qp.r --- qc.l ------------------- qc.r ---
    /*
    if(qc.r0 < qp.l0 || qp.r0 < qc.l0) {
      answer = 0;

      for(int i=qc.l0; i <= qc.r0; i++) {
        addnumber(i);
      }
    }
    */

    // -----qc.l0-----qp.l0 ################## qp.r0 ---------
    while(qc.l0 < pl) {
      pl--;
      addnumber(pl);
    }


    // -----qp.l0 #### qc.l0  ############## qp.r0 ---------
    while (pl < qc.l0) {
      removenumber(pl);
      pl++;
    }

    // ----- ####### qp.r0 --------- qc.r0 ---------
    while (pr < qc.r0){
      pr++;
      addnumber(pr);
    }


    // ----- ####### qc.r0 ####### qp.r0 ---------
    while (qc.r0 < pr){
      removenumber(pr);
      pr--;
    }

    result[qc.idx] = answer;      
  }

  for(int i=0; i<q; i++) {
    cout<<result[i]<<"\n";
  }

  // queries.clear();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  // cin>>t;
  for(int t = 0; t < t; t++) {
    start();
    // cout<<"\n";
  }

  return 0;
}
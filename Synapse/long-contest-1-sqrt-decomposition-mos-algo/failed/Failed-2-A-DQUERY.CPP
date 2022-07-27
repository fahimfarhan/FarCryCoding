#include <bits/stdc++.h>
using namespace std;

int N, Q;
int *a;

int *result;

int mp[1000000+5] = {0};

int blockSize = 500;
int blockCount = 1;
int answer = 0;


inline void add(const int& n) {
  mp[n]++;
  if(mp[n] == 1) {
    answer++;
  }
}

inline void remove(const int& n) {
  mp[n]--;
  if(mp[n] == 0) {
    answer--;
  }
}

class Query{
public:
  int l0, r0, idx;
  Query(int l0, int r0, int idx) {
    this->l0 = l0;
    this->r0 = r0;
    this->idx = idx;
  }

  void printer() {
    cout<<"idx = "<<idx<<", ["<<l0+1<<", "<<r0+1<<"]\n";
  }
};

vector<Query> queries;

bool comparator(const Query& f, const Query& s) {
  int fblock = f.l0/blockSize;
  int sblock = s.l0/blockSize;

  if(fblock != sblock) { // if in different block
    return (fblock < sblock);
  }
  
  return (f.r0 < s.r0);  // if in same block
}

// inline void preprocess() {
//   blockSize = sqrt(N);
//   blockCount = ceil((0.0 + N)/blockSize);
// }

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin>>N;
  a = new int[N+1];

  for(int i=0; i<N; i++) {
    cin>>a[i];
  }

  // preprocess();
  cin>>Q;
  result = new int[Q+1];
  int l1, r1, idx;
  for(int q=0; q<Q; q++) {
    cin>>l1>>r1;
    l1--; r1--;  // convert into zero based indexing...
    Query query(l1, r1, q);
    queries.push_back(query);
  }

  sort(queries.begin(), queries.end(), comparator);

  // for(auto q: queries) {
  //   q.printer();
  // }


  answer = 0;
  for(int i=queries[0].l0; i<queries[0].r0; i++) {
    add(a[i]);   
  }

  result[queries[0].idx] = answer;  

  int currL0, prevL0;
  int currR0, prevR0;

  for(int j=1; j<Q; j++) {
    currL0 = queries[j].l0;
    prevL0 = queries[j-1].l0;

    if(currL0 < prevL0) {
      for(int i=currL0; i<prevL0; i++) {
        add(a[i]);
      }
    } 
    
    if(prevL0 < currL0) {
      for(int i=prevL0; i<currL0; i++) {
        remove(a[i]);
      }
    }

    
    currR0 = queries[j].r0;
    prevR0 = queries[j-1].r0;

    if(currR0 < prevR0) {
      for(int i=currR0+1; i<= prevR0;i++) {
        remove(a[i]);
      }
    } 
    
    if(prevR0 < currR0) {
      for(int i=prevR0+1; i<=currR0; i++) {
        add(a[i]);
      }
    }

    result[queries[j].idx] = answer;

  }

  for(int i=0; i<Q; i++) {
    cout<<result[i]<<"\n";
  }

  delete[] result;
  delete[] a;
  return 0;
}
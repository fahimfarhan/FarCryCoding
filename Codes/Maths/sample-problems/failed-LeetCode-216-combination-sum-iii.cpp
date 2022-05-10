#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
      vector<bool> isVisited(10, false);       
      vector<vector<int> > result;
      vector<int> v;

      int sumSoFar = 0;
      int height = 1;
      for(int i = 1; i < 10; i++) {
        backTrack(sumSoFar, i, n, k, height, result, v, isVisited);
      }

      return result;
    }
private:
  void backTrack(int& ssf, int& m, const int& n, const int& k, int& h, vector<vector<int>> &result, vector<int> &v, vector<bool>& isVisited) {
    // cerr<<ssf<<"\n";
    if(h > k) {
      return;
    }

    isVisited[m] = true;    
    ssf += m;
    v.push_back(m);
    
    if(ssf > m) {
      isVisited[m] = false;
      ssf -= m;
      v.pop_back();
      return;
    }
 
    // cerr<<ssf<<" h = "<<h<<" k = "<<k<<"\n";
    
    if(ssf == n) {  
      cerr<<ssf<<" h = "<<h<<" k = "<<k<<"\n";
      for(auto u: v) {
        cout<<u<<" , ";
      }cout<<"\n";
    } else {
      cerr<<ssf<<"\n";
    }
    

    if( (k == v.size()) && (ssf == n) ) {
      vector<int> someClone(v);
      result.push_back(someClone);
            
      isVisited[m] = false;
      ssf -= m;
      v.pop_back();
      return;
    } 

    int h1 = h+1;
    cout<<"h = "<<h<<" h1 = "<<h1<<"\n";
    for(int i = m+1; i<= 9; i++) {
      // v.push_back(i);
      backTrack(ssf, i, m, k, h1, result, v, isVisited);
      // v.pop_back();
    }


      isVisited[m] = false;
      ssf -= m;
      v.pop_back();
      return;

  }
};

int main() {

  Solution s;
  auto out = s.combinationSum3(3, 7);
  for(auto i: out) {
    cout<<"[";
    for(auto j: i) {
      cout<<j<<" , ";
    }
    cout<<"]\n";
  }
  return 0;
}
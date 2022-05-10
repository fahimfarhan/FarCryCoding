#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
      this->k = k;
      this->n = n;
      this->ssf = 0;

      isVisited.resize(10, false);
      path.clear();
      result.clear();

      for(int i=1; i<10; i++) {
        backTrack(i, 1);
      }

      return result;
    }


private:
  int k, n, ssf;
  vector<vector<int> > result;
  vector<int> path;
  vector<bool> isVisited;
  
  void backTrack(const int& u, int h) {
    if(h>k) {
      return;
    }
    
    push(u);
    if( (h == k) && (ssf == n) ) {
      vector<int> someClone(path);
      result.push_back(someClone);
    } else {
      int h1 = h + 1;
      for(int v=u+1; v<10; v++) {
        backTrack(v, h1);
      }
    }
    pop(u);
  }

  void push(const int& u) {
    isVisited[u] = true;
    path.push_back(u);
    ssf += u;
  }

  void pop(const int& u) {
    isVisited[u] = false;
    path.pop_back();
    ssf-=u;
  }

};


int main() {

  return 0;
}
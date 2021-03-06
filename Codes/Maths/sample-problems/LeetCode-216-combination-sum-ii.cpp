#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
      this->k = k;
      this->n = n;
      this->ssf = 0;

  vector<vector<int> > result;
  vector<int> path;
  vector<bool> isVisited(10, false);
  

      for(int i=1; i<10; i++) {
        backTrack(i, 1, path, isVisited, result);
      }

      return result;
    }


private:
  int k, n, ssf;
  void backTrack(const int& u, int h, 
  vector<int>& path,
  vector<bool>& isVisited,
  vector<vector<int> >& result
  ) {
    if(h>k) {
      return;
    }
    
    push(u, path, isVisited, result);
    if( (h == k) && (ssf == n) ) {
      vector<int> someClone(path);
      result.push_back(someClone);
    } else {
      int h1 = h + 1;
      for(int v=u+1; v<10; v++) {
        backTrack(v, h1, path, isVisited, result);
      }
    }
    pop(u, path, isVisited, result);
  }

  void push(const int& u, 
    vector<int>& path,
    vector<bool>& isVisited,
    vector<vector<int> >& result
  ) {
    isVisited[u] = true;
    path.push_back(u);
    ssf += u;
  }

  void pop(const int& u, 
    vector<int>& path,
    vector<bool>& isVisited,
    vector<vector<int> >& result
  ) {
    isVisited[u] = false;
    path.pop_back();
    ssf-=u;
  }

};


int main() {

  return 0;
}
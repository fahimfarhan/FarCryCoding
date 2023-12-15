#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
      unordered_set<string> dest;


      int N = paths.size();

      for(int i=0; i<N; i++) {
        // src.insert(paths[i][0]);
        dest.insert(paths[i][0]);
      }

      for(int i=0; i<N; i++) {
        if(dest.find(paths[i][1]) == dest.end()) {
          return paths[i][1];
        }
      }

      return "";

    }
};


int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
      // unordered_set<string> src;
      unordered_set<string> dest;

      string u, v;

      int N = paths.size();

      for(int i=0; i<N; i++) {
        // src.insert(paths[i][0]);
        dest.insert(paths[i][1]);
      }

      for(int i=0; i<N; i++) {
        // src.insert(paths[i][0]);
        dest.erase(paths[i][0]);
      }

      // dest should have only one string

      auto it = dest.begin();
      string destination = *it;
      return destination;
    }
};


int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}

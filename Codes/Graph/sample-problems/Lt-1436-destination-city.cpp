#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
      unordered_map<string, int> mp;
      int N = paths.size();
      string u, v;

      for(int i=0; i<N; i++) {
        u = paths[i][0];
        v = paths[i][1];

        if(!mp[u]) {
          mp[u] = 0;
        }
        if(!mp[v]) {
          mp[v] = 0;
        }
        mp[u]++;
      }

      string dest = "";

      for(auto element: mp) {
        if(element.second == 0) {
          dest = element.first;
          break;
        }
      }

      return dest;

    }
};

int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}

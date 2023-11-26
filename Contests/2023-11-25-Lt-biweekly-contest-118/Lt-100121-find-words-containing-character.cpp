#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
      vector<int> output;

      int N = words.size(), M = 0;
      for(int i=0; i<N; i++) {
        M = words[i].size();
        for(int j = 0; j < M; j++) {
          // cout<<words[i][j];
          if(words[i][j] == x) {
            output.push_back(i);
            break;
          }
        }
      }
      return output;      
    }
};

int main(int argc, char const *argv[])
{
  /* code */
  Solution s;
  vector<string> v = {"leet", "code", "fgdg"};
  auto output = s.findWordsContaining(v, 'e');
  for(auto a: output) {
    cout<<a<<" ";
  }cout<<"\n";
  return 0;
}

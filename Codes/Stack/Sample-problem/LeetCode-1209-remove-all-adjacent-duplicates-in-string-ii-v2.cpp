#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
      // stack<pair<char, int> > st;
public:
    string removeDuplicates(string s, int k) {       
      string t = "";

      vector<pair<char, int> > v;
      char ch = '\0';
      int cnt = 0;
      int N = s.size();
      for(int i=0; i<N; i++) {
        ch = s[i];
        if(v.empty()) {
          v.push_back({ch, 1});
        } else {
          // v.push_back({ch, 2});
          if(v.back().first == ch) {
            v.back().second++;

            if(v.back().second == k) {
              v.pop_back();
            }
          } else {
            v.push_back({ch, 1});
          }
          // auto p = v.back();
          // cerr<<p.first<<" "<<p.second<<"\n";
        }
      }

      for(auto p: v) {
        ch = p.first;
        cnt = p.second;

        for(int i=0; i<cnt; i++) {
          t += ch;  // t = t + ch; <-- this line is the real culprit!!!
        }
      }
      return t;
    }
};


int main() {
// "abcd"
// 2
// "deeedbbcccbdaa"
// 3
// "pbbcggttciiippooaais"
// 2

  Solution s;
  string in = "deeedbbcccbdaa";
  int k = 3;
  //cin>>in;
  //cin>>k;
  auto t = s.removeDuplicates(in, k);
  cout<<t<<"\n";
  return 0;
}
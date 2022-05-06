#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
      // stack<pair<char, int> > st;
public:
    string removeDuplicates(string s, int k) {       
      stack<pair<char, int> > st;
      int N = s.size();
      char ch = '\0';
      int cnt = 0;
      for(int i=0; i<N; i++) {
        ch = s[i];
        if(!st.empty() && st.top().first == ch) {
          // cerr<<"inside case 1\n";
          cnt = 1 + st.top().second;
          
          st.push({ch, cnt });

          if(cnt == k - 1) {
            for(int i=0; i<k; i++) {
              st.pop();
           }
          }
        } else { 
          st.push({ch,0});
        }
      }

      string t = "";
      while(!st.empty()) {
        ch = st.top().first;
        t = ch + t;
        st.pop();
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
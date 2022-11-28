#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  string uniqueEmail(string input) {
    string output = "";

    int N = input.size();
    int i = 0;
    bool include = true;
    for (i = 0; i < N; i++) {
      if (input[i] == '@') {
        break;
      } else if (input[i] == '+') {
        include = false;
      } else if (input[i] == '.') { /* ignore this char*/
      } else if (include) {
        output += input[i];
      }
    }

    string domain = input.substr(i);
    output += domain;
    return output;
  }

public:
  int numUniqueEmails(vector<string> &emails) {

    unordered_set<string> us;

    for (auto email : emails) {
      string uniqueMail = uniqueEmail(email);
      us.insert(uniqueMail);
    }
    return us.size();
  }
};

int main(int argc, char *argv[]) { return 0; }

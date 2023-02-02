#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isAlienSorted(vector<string> &words, string order) {

    int orderMap[26] = {0};
    for (int i = 0; i < 26; i++) {
      orderMap[(int)(order[i] - 'a')] = i;
    }

    int ithWordsJthCharacter;  // = words[i][j] - 'a';
    int nextWordsJthCharacter; // = words[i + 1][j] - 'a';

    for (int i = 0; i < words.size() - 1; i++) {
      for (int j = 0; j < words[i].size(); j++) {

        // case "apple" vs "app"
        if (j >= words[i + 1].size()) {
          return false;
        }

        if (words[i][j] != words[i + 1][j]) {
          ithWordsJthCharacter = words[i][j] - 'a';
          nextWordsJthCharacter = words[i + 1][j] - 'a';

          if (orderMap[ithWordsJthCharacter] >
              orderMap[nextWordsJthCharacter]) {
            return false;
          }

          // no need to continue with jth word
          break;
        }
      }
    }

    return true;
  }
};

int main(int argc, char *argv[]) {
  vector<string> v("hello", "leetcode");
  string order = "hlabcdefgijkmnopqrstuvwxyz";

  Solution s;
  cout << s.isAlienSorted(v, order) << "\n";
  return 0;
}

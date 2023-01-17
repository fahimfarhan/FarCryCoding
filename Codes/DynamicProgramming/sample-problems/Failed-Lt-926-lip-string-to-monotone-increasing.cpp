#include <bits/stdc++.h>
#include <cstring>
using namespace std;

class Solution {
private:
  // string s = "";

  const static int MAX_N = 100000 + 5;
  int memo[2][MAX_N];

public:
  int minFlipsMonoIncr(string s) {

    if (s.empty()) {
      return 0;
    }
    // now s has at least size = 1

    int minimus = 0;
    // this->s = s;

    int length = s.size();
    // todo logic
    memo[0][0] = (s[0] != '0');
    memo[1][0] = (s[0] != '1');
    // preprocess

    int j = 0;
    for (int i = 1; i < length; i++) {
      j = i - 1;
      memo[0][i] = memo[0][j] + (s[i] != '0');
      memo[1][i] = memo[1][j] + (s[i] != '1');
    }

    // count
    int flip0 = 0,
        flip1 = 0; // flip_i = count to make not_i to i (ie 1 to 0, or 0 to 1)

    int flips = 0;
    minimus = memo[1][length - 1]; // 1111 .... 1111

    int last = length - 1;
    for (int i = 0; i < length; i++) {

      flip0 = memo[0][0];
      flip1 = memo[1][last] - memo[1][0];

      flips = flip0 + flip1;

      minimus = min(minimus, flips);
    }

    // this->s = "";
    return minimus;
  }
};

int main(int argc, char *argv[]) { return 0; }

#include <bits/stdc++.h>
using namespace std;

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

int pick = 0;

int guess(int num) {
  if (num > pick) {
    return -1;
  } else if (num < pick) {
    return 1;
  }

  return 0;
}

class Solution {
private:
  uint lo;
  uint hi;
  uint myGuess;

public:
  void foo() {
    uint one = 1;

    lo = one;
    hi = (one << 31) - 1;
    myGuess =
        one
        << 30; // = avg = (lo + hi)/2, but using bit operation for efficiency
  }

  int guessNumber(int n) {
    lo = 1;
    hi = n;

    while (true) {
      myGuess = lo + ((hi - lo) >> 1);

      int g = guess(myGuess);

      if (g == 0) {
        break;
      } else if (g == 1) {
        lo = myGuess + 1;
      } else if (g == -1) {
        hi = myGuess - 1;
      }
    }
    // avg = (lo + hi) / 2 = (2lo + hi - lo)/2 = lo + (hi - lo)/2

    return myGuess;
  }
};

int main() {
  int n = 10;
  pick = 6;

  Solution s;
  int g = s.guessNumber(n);
  cout << g << "\n";

  n = 1, pick = 1;
  g = s.guessNumber(n);
  cout << g << "\n";

  n = 2;
  pick = 1;
  g = s.guessNumber(n);
  cout << g << "\n";

  n = 2;
  pick = 2;
  g = s.guessNumber(n);
  cout << g << "\n";
  return 0;
}

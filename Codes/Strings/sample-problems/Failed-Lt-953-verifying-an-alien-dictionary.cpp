#include <bits/stdc++.h>
using namespace std;

bool isSorted;
int mp[200]; // = {0};

bool comperator(string x, string y) {
  int xLength = x.length();
  int yLength = y.length();

  if (xLength == 0 && yLength != 0) {
    return true;
  }
  if (yLength == 0 && xLength != 0) {
    isSorted = false;
    return false;
  }

  int x0 = mp[x[0]];
  int y0 = mp[y[0]];

  if (x0 == y0) {
    return comperator(x.substr(1), y.substr(1));
  } else {
    bool b = x0 < y0;
    if (!b) {
      isSorted = false;
    }
    return b;
  }
}

class Comperator {

public:
  bool isSorted;
  int mp[200]; // = {0};
               //
  Comperator(string order) {
    memset(mp, -1, sizeof(int) * 200);
    isSorted = true;

    int orderLength = order.length();
    for (int i = 0; i < orderLength; i++) {
      mp[(int)order[i]] = i;
    }
  }

  bool comperator(string x, string y) {
    int xLength = x.length();
    int yLength = y.length();

    if (xLength == 0 && yLength != 0) {
      return true;
    }
    if (yLength == 0 && xLength != 0) {
      isSorted = false;
      return false;
    }

    int x0 = mp[x[0]];
    int y0 = mp[y[0]];

    if (x0 == y0) {
      return comperator(x.substr(1), y.substr(1));
    } else {
      bool b = x0 < y0;
      if (!b) {
        isSorted = false;
      }
      return b;
    }
  }
};

class Solution {

public:
  static bool compDescendingOrderWrtSize(string x, string y) {
    int n = x.size();
    int m = y.size();

    if (n > m) {
      return true;
    } else {
      return false;
    }
  }

  bool isAlienSorted(vector<string> &words, string order) {

    memset(mp, -1, sizeof(int) * 200);
    isSorted = true;

    int orderLength = order.length();
    for (int i = 0; i < orderLength; i++) {
      mp[(int)order[i]] = i;
    }

    // Comperator comperator(order);

    sort(words.begin(), words.end(), comperator);
    bool result = isSorted;
    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<string> v("hello", "leetcode");
  string order = "hlabcdefgijkmnopqrstuvwxyz";

  Solution s;
  cout << s.isAlienSorted(v, order) << "\n";
  return 0;
}

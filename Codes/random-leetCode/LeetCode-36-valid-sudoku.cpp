#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
  int kount[10] = {0};
  int temp = 0;

  inline bool rowValid(vector<vector<char>> &board, int r) {
    memset(kount, 0, sizeof(kount));
    temp = 0;
    for (int i = 0; i < 9; i++) {
      if (board[i][r] >= '0') {
        temp = board[i][r] - '0';
        kount[temp]++;

        if (kount[temp] > 1) {
          return false;
        }
      }
    }

    return true;
  }

  inline bool columnValid(vector<vector<char>> &board, int c) {
    memset(kount, 0, sizeof(kount));
    temp = 0;
    for (int i = 0; i < 9; i++) {
      if (board[c][i] >= '0') {
        temp = board[c][i] - '0';
        kount[temp]++;

        if (kount[temp] > 1) {
          return false;
        }
      }
    }

    return true;
  }

  inline bool gridValid(vector<vector<char>> &board, int left, int top) {
    memset(kount, 0, sizeof(kount));
    temp = 0;
    for (int i = left; i < left + 3; i++) {
      for (int j = top; j < top + 3; j++) {
        if (board[i][j] >= '0') {
          temp = board[i][j] - '0';
          kount[temp]++;

          if (kount[temp] > 1) {
            return false;
          }
        }
      }
    }

    return true;
  }

public:
  bool isValidSudoku(vector<vector<char>> &board) {
    // check row
    for (int i = 0; i < 9; i++) {
      if (!rowValid(board, i)) {
        return false;
      }
    }
    // check column
    for (int i = 0; i < 9; i++) {
      if (!columnValid(board, i)) {
        return false;
      }
    }
    // check the 9 smaller (3x3) grids
    for (int i = 0; i < 9; i += 3) {
      for (int j = 0; j < 9; j += 3) {
        if (!gridValid(board, i, j)) {
          return false;
        }
      }
    }

    return true;
  }
};

int main() { return 0; }

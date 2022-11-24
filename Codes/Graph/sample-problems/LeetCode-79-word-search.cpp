#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  int N, M;
  bool **visited;

  bool validGrid(int r, int c) {
    if ((0 <= r) && (r < N) && (0 <= c) && (c < M)) {
      return true;
    }
    return false;
  }

  bool backTrack(vector<vector<char>> &board, const string &word, int r, int c,
                 int wordIdx) {
    int row, col;
    int nextIndex = wordIdx + 1;

    if ((wordIdx == word.size() - 1) && (board[r][c] == word[wordIdx])) {
      return true;
    }

    if (nextIndex >= word.size()) {
      return false;
    }

    row = r + 1;
    col = c;
    visited[r][c] = true;
    bool temp = false;
    if (validGrid(row, col)) {
      if (!visited[row][col] && board[row][col] == word[nextIndex]) {
        temp = backTrack(board, word, row, col, nextIndex);
      }
    }

    if (temp) {
      return true;
    }

    row = r - 1;
    col = c;
    if (validGrid(row, col)) {
      if (!visited[row][col] && board[row][col] == word[nextIndex]) {
        temp = backTrack(board, word, row, col, nextIndex);
      }
    }

    if (temp) {
      return true;
    }

    row = r;
    col = c + 1;
    if (validGrid(row, col)) {
      if (!visited[row][col] && board[row][col] == word[nextIndex]) {
        temp = backTrack(board, word, row, col, nextIndex);
      }
    }

    if (temp) {
      return true;
    }

    row = r;
    col = c - 1;
    if (validGrid(row, col)) {
      if (!visited[row][col] && board[row][col] == word[nextIndex]) {
        temp = backTrack(board, word, row, col, nextIndex);
      }
    }
    if (temp) {
      return true;
    }

    visited[r][c] = false;
    return false;
  }

  void preprocess() {
    visited = new bool *[N + 1];
    for (int i = 0; i <= N; i++) {
      visited[i] = new bool[M + 1];
    }

    for (int i = 0; i <= N; i++) {
      for (int j = 0; j < M; j++) {
        visited[i][j] = false;
      }
    }
  }

  void destructor() {
    for (int i = 0; i <= N; i++) {
      delete[] visited[i]; // = new bool[M+1];
    }
    delete[] visited;
  }

public:
  bool exist(vector<vector<char>> &board, string word) {
    N = board.size();
    M = board[0].size();
    preprocess();

    bool wordExists = false;
    for (int i = 0; i < N; i++) {
      if (wordExists) {
        break;
      }
      for (int j = 0; j < M; j++) {
        if (!visited[i][j] && (word[0] == board[i][j])) {
          wordExists = backTrack(board, word, i, j, 0);
          if (wordExists) {
            break;
          }
        }
      }
    }
    destructor();
    return wordExists;
  }
};

int main(int argc, char *argv[]) { return 0; }

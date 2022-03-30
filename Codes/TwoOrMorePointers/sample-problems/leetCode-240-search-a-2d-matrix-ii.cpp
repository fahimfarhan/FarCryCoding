#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 
 * Thanks to https://cheonhyangzhang.gitbooks.io/leetcode-solutions/content/240-search-a-2d-matrix-ii-medium.html
 * 
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int r, c;
      r = 0; //matrix.size() - 1;
      c = matrix[0].size() - 1;

      while( (r < matrix.size()) && (c >=0) ) {
        if( target < matrix[r][c]) {
          c--;
        } else if(target > matrix[r][c]) {
          r++;
        } else {
          return true;
        }
      }

      return false;
    }


    bool searchMatrix1(vector<vector<int>>& matrix, int target) {
      int r, c;
      r = matrix.size() - 1;
      c = 0; // matrix[0].size();

      while(r >=0 && c < matrix[0].size()) {
        if(matrix[r][c] > target) {
          r--;
        } else if(matrix[r][c] < target) {
          c++;
        } else {
          return true;
        }
      }
      return false;
    }
};

int mina() {

  return 0;
}
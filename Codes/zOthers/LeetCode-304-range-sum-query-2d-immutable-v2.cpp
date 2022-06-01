#include <bits/stdc++.h>
using namespace std;

class NumMatrix {
private:
  int** dp;
  int r, c, r1, c1;
public:
    NumMatrix(vector<vector<int>>& m) {
      r = m.size();
      c = m[0].size();

      r1 = r + 2;
      c1 = c + 2;

      dp = new int*[r1];
      for(int i=0; i<r1; i++) {
        dp[i] = new int[c1];
      }

      for(int i=0; i<r1; i++) {
        dp[i][0] = 0;
        dp[i][c1-1] = 0;
      }

      for(int j=0; j<c1; j++) {
          dp[0][j] = 0;
          dp[r1-1][j] = 0;
        }

      for(int i=1; i<=r; i++) {
        for(int j=1; j<=c; j++) {
          int a = m[i-1][j-1];
          dp[i][j] = a + dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1];
        }
      }      
    }

    ~NumMatrix() {
      for(int i=0; i<r1; i++) {
        //dp[i] = new int[c1];
        delete[] dp[i];
      }
      delete[] dp;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
      row1++;
      row2++;
      col1++;
      col2++;

      int sum = dp[row2][col2] - dp[row2][col1-1] - dp[row1-1][col2] + dp[row1-1][col1-1];
      
      return sum;   
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main() {
  vector<vector<int>> m = { {3, 0, 1, 4, 2},  
                            {5, 6, 3, 2, 1}, 
                            {1, 2, 0, 1, 5}, 
                            {4, 1, 0, 1, 7}, 
                            {1, 0, 3, 0, 5} }; // {{1,2,3,4}, {5,6,7,8}};
  NumMatrix nm(m);

  cout<<nm.sumRegion(2, 1, 4, 3)<<"\n";
  cout<<nm.sumRegion(1, 1, 2, 2)<<"\n";
  cout<<nm.sumRegion(1,2,2,4)<<"\n";
  cout<<nm.sumRegion(0,0,0,3)<<"\n";


  return 0;
}
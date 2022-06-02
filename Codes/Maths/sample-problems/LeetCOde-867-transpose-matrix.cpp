#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
      int n = matrix.size();
      int m = matrix[0].size();

      vector<int> col(n, 0);
      vector<vector<int>> trans(m, col);

      for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
          trans[j][i] = matrix[i][j];
        }
      }
      return trans;
    }

    vector<vector<int>> transposeFailed(vector<vector<int>>& matrix) {
      int n = matrix.size();
      int m = matrix[0].size();

      for(int i=0; i<n; i++) {
        for(int j=i+1; j<m; j++) {
          swap(matrix[i][j], matrix[j][i]);
        }
      }
      return matrix;
    }
};

/*

  00  01  02   03  04
  10  11  12   13  14
  20  21  22   23  24
  30  31  32   33  34
  40  41  42   43  44

  01  ->  10

  input:  
  1  2  3
  4  5  6
  7  8  9

  my output:
  1 4 7
  2 5 6
  3 8 9

  expected:
  1  4  7
  2  5  8
  3  6  9

*/

void printer(vector<vector<int>> &m) {
  for(auto i: m) {
    for(auto j: i) {
      cout<<j<<" ";
    }cout<<"\n";
  }
}

int main(int argc, char const *argv[])
{
  /* code */
  vector<vector<int>> matrix = {
      {1,  2,  3},
  {4,  5,  6},
  {7,  8,  9}
  };

  Solution s;
  auto m = s.transpose(matrix);

  printer(m);

  return 0;
}

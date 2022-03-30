#include <bits/stdc++.h>
using namespace std;

//#define FALSE false
//#define TRUE true
// #define MAYBE 2

class Node{
  public:
    int x=0, y=0;

    Node() {
      x=0, y=0;
    }

    Node(int x1, int y1) {
      x = x1; y = y1;
    }

    void print() {
      cerr<<"("<<x<<", "<<y<<")";
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        Node start(0,0), end( (n-1), (m-1) );
        return divideAndConquer(matrix, target, start, end);
    }


    /*

    a     b     

        c       d
    e     f     
        
        g       h
    
    */
    vector<Node> divide(const Node& a, const Node& h) {
      int xm, ym;

      xm = a.x + ((h.x - a.x)>>1);
      ym = a.y + ((h.y - a.y)>>1);
      
      Node c(xm, ym);
      
      Node b(c.x+1, a.y),  d(h.x, c.y), e(a.x, c.y+1), f(c.x+1, c.y+1), g(c.x, h.y);

      vector<Node> v = {a, b, c, d, e, f, g};
      return v;
    }

    bool conquer(vector<vector<int>>& matrix, const int& target, const Node& tl,const Node& br) {  
      if(tl.x > br.x) { return false; }
      if(tl.y > br.y) { return false; }

      if( (tl.x == br.x) && (tl.y == br.y) ) {
        if(matrix[tl.x][tl.y] == target) {
          return true;
        } else {
          return false;
        }

      }
      
      int start = matrix[tl.x][tl.y];
      int end = matrix[br.x][br.y];

      if( (start <= target) && (target <= end) ) {
        return divideAndConquer(matrix, target, tl, br);
      }

      return false;
    }

    bool divideAndConquer(vector<vector<int>>& matrix, const int& target, const Node& tl, const Node& br) {
      
      vector<Node> v = divide(tl, br);      
      Node a = v[0], b = v[1], c = v[2], d = v[3], e = v[4], f = v[5], g = v[6], h = v[7];


      bool b1, b2, b3, b4;
      b1 = conquer(matrix, target, a, c);
      b2 = conquer(matrix, target, b, d);
      b3 = conquer(matrix, target, e, g);
      b4 = conquer(matrix, target, f, h);

      bool ret = b1 | b2 | b3 | b4;
      return ret;
    }
};


int main() {

// Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]],
// target = 5

  Solution s;
  vector<vector<int> > v = { {1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30} };

  //cout<<s.searchMatrix(v, 5)<<"\n";
 
  //cout<<s.searchMatrix(v, 20)<<"\n";
 
  vector<vector<int> > v1 = { {1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30} };
  cout<<s.searchMatrix(v1, 5)<<"\n";
  cout<<s.searchMatrix(v1, 20)<<"\n";
 
  return 0;
}
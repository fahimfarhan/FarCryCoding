#include <bits/stdc++.h>
using namespace std;

tuple<int, int, int> extendedGcd(int a, int b) {
  // base case
  if(b == 0) {
    return {1, 0, a};
  }
  int x1, y1, g;
  auto t = extendedGcd(b, a % b);
  x1 = get<0>(t);
  y1 = get<1>(t);
  g = get<2>(t);


  int x = y1;
  int y = x1 - (a/b)*y1;

  return {x, y, g};
}

// isSolvable, x, y
tuple<bool, int, int, int> diophantineAnySolution(int a, int b, int c) {
  // degenerate case
  if(a == 0 && b == 0) {
    return {false, -1, -1, -1};
  }

  auto t = extendedGcd(a, b);
  int xg, yg, g;
  
  xg = get<0>(t);
  yg = get<1>(t);
  g  = get<2>(t);

  // a x_g + b y_g == g

  if( (c % g) != 0) {
    return {false, -1, -1, -1}; 
  } 

  int x = c*xg / g;
  int y = c*yg / g;

  return {true, x, y, g};
}

list<pair<int, int> > findAllSolutions(int a, int b, int c) {
  list<pair<int, int>> p;

  auto t = diophantineAnySolution(a, b, c);

  bool solutionExists = get<0>(t);
  if(!solutionExists) {
    return p;
  }

  int Xg = get<1>(t); int Yg = get<2>(t);
  int g = get<3>(t);

  if( (a == 0 || b == 0) && (a != b) ) {
    p.push_back({Xg, Yg}); // only one soln exists...
  }  

  // infinite many soln exists! lets find 11. 5 small, and 5 big
  for(int k=1; k <= 5; k++) {
    int x = Xg - k * b / g;
    int y = Yg + k * a / g;

    p.push_back({x, y});

    x = Xg + k * b / g;
    y = Yg - k * a / g;

    p.push_front({x, y});
  }

  return p;
}

int main() {

  return 0;
}
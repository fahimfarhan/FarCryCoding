// extended-euclidean.cpp
#include <bits/stdtr1c++.h>
using namespace std;

// @params a, b
// @result g, x, y
tuple<int, int, int> extendedGcd(int a, int b) {
  if (b == 0) {
    return tuple<int, int, int>(a, 1, 0);
  }

  tuple<int, int, int> t = extendedGcd(b, a % b);
  int g = get<0>(t);
  int x1 = get<1>(t);
  int y1 = get<2>(t);

  int x = y1;
  int y = x1 - (a / b) * y1;

  return tuple<int, int, int>(g, x, y);
}

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int a, b, g, x, y;

  while (cin >> a >> b) {
    tuple<int, int, int> t = extendedGcd(a, b);
    g = get<0>(t);
    x = get<1>(t);
    y = get<2>(t);

    cout << x << " " << y << " " << g << "\n";
  }

  return 0;
}

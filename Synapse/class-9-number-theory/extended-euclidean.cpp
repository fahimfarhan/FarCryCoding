// extended-euclidean.cpp
#include <bits/stdtr1c++.h>
using namespace std;

// @params a, b
// @result g, x, y
tuple<int, int, int> extendedGcd(int a, int b) {
  if (b == 0) {
    return tuple<int, int, int>(a, 1, 0);
  }

  auto [g, x1, y1] = extendedGcd(b, a % b);
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

  /*
  cout << gcd(1, 0) << "\n";
  cout << gcd(1, 2) << "\n";
  cout << gcd(2, 3) << "\n";
  cout << gcd(7, 79) << "\n";
  cout << gcd(10, 2) << "\n";
  cout << gcd(4, 16) << "\n";
  cout << gcd(29, 69) << "\n";
  */
  {

    auto [g, x, y] = extendedGcd(1432, 123211);
    cout << g << " " << x << " " << y << "\n";
  }

  {
    auto [g, x, y] = extendedGcd(3, 5);
    cout << g << " " << x << " " << y << "\n";
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

tuple<int, int, int> extendedGcd(int a, int b) {
  if (b == 0) {
    return tuple<int, int, int>(a, 1, 0);
  }

  auto [g, x1, y1] = extendedGcd(b, a % b);
  int x = y1;
  int y = x1 - (a / b) * y1;

  return tuple<int, int, int>(g, x, y);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int a, b, c;
  cin >> a >> b >> c;

  tuple<int, int, int> t = extendedGcd(a, b);

  int g = get<0>(t);
  int x = get<1>(t);
  int y = get<2>(t);

  // cerr << "g = " << g << " x = " << x << " y = " << y << "\n";
  int remainderCg = c % g;
  // cerr << "remainderCg = " << remainderCg << "\n";

  if ((c % g) == 0 && (x >= 0) && (y >= 0)) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }

  return 0;
}

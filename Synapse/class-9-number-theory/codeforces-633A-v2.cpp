#include <bits/stdc++.h>
using namespace std;

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

  int a, b, c, g;
  cin >> a >> b >> c;

  g = gcd(a, b);
  // ax + by = c => by = c - ax
  // => y = (c - ax) / b
  // if y is int ie (c - ax) % b == 0, then the soln exists.

  int y = -1;
  bool possible = false;
  for (int x = 0; x * a <= c; x++) {
    y = (c - a * x) % b;
    if (y == 0) {
      possible = true;
      break;
      ;
    }
  }

  if (possible) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

/**
 *@Brief:
    input: a, b
    output: x, y, g
 * */
tuple<int, int, int> extendedGcd(int a, int b) {
  // base case:
  if (b == 0) {
    return {1, 0, a};
  }
  tuple<int, int, int> t = extendedGcd(b, a % b);
  int _x = get<0>(t);
  int _y = get<1>(t);
  int g = get<2>(t);
  // x = y1, \\
  // y = x1 - \lfloor {a \over b} \rfloor .y1

  int x = _y;
  int y = _x - (a / b) * _y;

  return {x, y, g};
}

int i = 0;

int gcd(int a, int b) {
  //  cerr << "debug: gcd case" << a << " " << b << "\n";
  if (b == 0) {
    // cerr << "debug: gcd base case\n";
    return a;
  }

  int r = a % b;
  return gcd(b, r);
}

bool checkIfdiophantineSolnExists(int a, int b, int c) {
  int g = gcd(a, b);
  // a x_g + b y_g = G
  // a c x_g/G + b c y_g / G = c
  // soln exists if c is divisible by g.
  bool exists = (c % g) == 0;

  return exists;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int T, a, b, c;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> a >> b >> c;
    string result = "Yes";
    bool exists = checkIfdiophantineSolnExists(a, b, c);
    if (exists) {
      result = "Yes";
    } else {
      result = "No";
    }

    cout << "Case " << t << ": " << result << "\n";
  }

  return 0;
}

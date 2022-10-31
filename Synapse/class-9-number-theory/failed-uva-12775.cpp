#include <bits/stdc++.h>
using namespace std;

tuple<int, int, int> extendedGcd(int a, int b) {
  if (b == 0) {
    return {1, 0, a};
  }
  tuple<int, int, int> t = extendedGcd(b, a % b);
  int x1, y1, g;

  x1 = get<0>(t);
  y1 = get<1>(t);
  g = get<2>(t);

  int x = y1;
  int y = x1 - y1 * (a / b);

  return {x, y, g};
}

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  cin.tie(0);
  cout.tie(0);

  int T, A, B, C, P;
  int g, x, y, z;
  int result = 0;

  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> A >> B >> C >> P;

    result = 0;
    g = gcd(A, B);

    int stop = P / C + 1;
    for (int i = 0; i <= stop; i++) {
      int dc = P - i * C;

      if ((dc >= 0) && ((dc % g) == 0)) {
        // todo: run extended gcd, and find a range of them
        tuple<int, int, int> t = extendedGcd(A, B);

        // loop over k
        // x' = x_0 - kb/g \\
        // y' = y_0 + ka/g

        int k = 0;
        int x = get<0>(t);
        int y = get<1>(t);

        if ((x >= 0) && (y >= 0)) {
          result++;
        }

        int bOverG = B / g;
        int aOverG = A / g;

        while (true) {
          x -= bOverG;
          y += aOverG;

          if ((x >= 0) && (y >= 0)) {
            result++;
          } else {
            break;
          }
        }

        x = get<0>(t);
        y = get<1>(t);

        while (true) {
          x += bOverG;
          y -= aOverG;

          if ((x >= 0) && (y >= 0)) {
            result++;
          } else {
            break;
          }
        }
      }
    }
    cout << "Case " << t << ": " << result << "\n";
  }
  return 0;
}

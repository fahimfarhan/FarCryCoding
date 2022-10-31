// COPR16G
/**
 * I haven't the faintest idea where this number (ab - a - b) comes from!
 * Linear Diophantine equation, and McChicken nuget theorem are needed.
 * */
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll gcd(ll a, ll b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll t, a, b, result;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    if (gcd(a, b) == 1) {
      // exitst
      result = (a * b - a - b) + 1;
      cout << result << "\n";
    } else {
      cout << -1 << "\n";
    }
  }

  return 0;
}

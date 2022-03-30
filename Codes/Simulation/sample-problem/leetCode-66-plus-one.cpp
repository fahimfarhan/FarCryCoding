#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      int carry = 1;
      int n = digits.size();
      int sum = 0;

      for(int i=n-1; i>=0; i--) {
        sum = digits[i]+carry;
        if(sum == 10) {
          carry = 1;
          digits[i] = 0;
        } else {
          carry = 0;
          digits[i] = sum;
        }
      }

      if(carry == 1) {
        digits.insert(digits.begin(), 1);
      }
      return digits;
    }
};

int main() {


  return 0;
}
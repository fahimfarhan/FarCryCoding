#include <bits/stdc++.h>
using namespace std;

#define RESULT first
#define NEXT_INDEX second
#define ll long long

class Solution {
private:
  set<string> operators = {"+", "-", "*", "/"};

  pair<ll, int> reversePolishNotation(vector<string> &tokens, int idx) {
    // handle corner cases
    if (idx < 0) {
      return {0, 0};
    }
    // handle base case
    if (operators.find(tokens[idx]) == operators.end()) {
      // ie, a number,
      return {stoi(tokens[idx]), (idx - 1)};
    }
    // else an operator!
    // handle recursive cases
    auto p1 = reversePolishNotation(tokens, (idx - 1));
    auto p2 = reversePolishNotation(tokens, p1.NEXT_INDEX);

    ll b = p1.RESULT;
    ll a = p2.RESULT;

    string op = tokens[idx];
    ll result = 0;
    if (op == "+") {
      result = a + b;
    } else if (op == "-") {
      result = a - b;
    } else if (op == "*") {
      result = a * b;
    } else {
      result = a / b;
    }
    return {result, p2.NEXT_INDEX};
  }

public:
  int evalRPN(vector<string> &tokens) {
    // if (tokens.size() == 1) {
    //   return stoi(tokens[0]);
    // }
    return (int)(reversePolishNotation(tokens, (tokens.size() - 1)).RESULT);
  }
};

int main(int argc, char *argv[]) {
  Solution s;

  vector<string> case1 = {"2", "1", "+", "3", "*"};
  vector<string> case2 = {"4", "13", "5", "/", "+"};
  vector<string> case3 = {"10", "6", "9",  "3", "+", "-11", "*",
                          "/",  "*", "17", "+", "5", "+"};

  vector<string> case4 = {"-128", "-128", "*", "-128", "*", "-128",
                          "*",    "8",    "*", "-1",   "*"};
  cout << s.evalRPN(case1) << "\n";
  cout << s.evalRPN(case2) << "\n";
  cout << s.evalRPN(case3) << "\n";
  cout << s.evalRPN(case4) << "\n";
  return 0;
}

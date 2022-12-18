#include <bits/stdc++.h>
using namespace std;

class MonotonicDecreasingStack {
private:
  stack<int> st;

public:
  int push(int n) {
    if (st.empty()) {
      st.push(n);
      return 0;
    }

    if (n < st.top()) {
      st.push(n);
      return 1;
    }
    int ret = 0;
    while ((!st.empty()) && (n >= st.top())) {
      ret++;
      st.pop();
    }
    clear();
    st.push(n);

    return ret;
  }

  void pop() {
    if (st.empty()) {
      return;
    }
    st.pop();
  }

  int top() { return st.top(); }

  bool empty() { return st.empty(); }

  int size() { return st.size(); }

  void clear() {
    while (!st.empty()) {
      st.pop();
    }
  }
};

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    int N = temperatures.size();

    vector<int> output(N, 0);

    if (N == 0) {
      return output;
    }

    MonotonicDecreasingStack st;
    for (int i = N - 1; i >= 0; i--) {
      output[i] = st.push(temperatures[i]);
    }
    return output;
  }
};

int main(int argc, char *argv[]) { return 0; }

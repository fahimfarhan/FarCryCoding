#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    int N = temperatures.size();
    vector<int> output(N, 0);

    stack<int> st; // monotonicDecreasingStack;

    for (int currDay = 0; currDay < N; currDay++) {
      int currTemp = temperatures[currDay];
      while (!st.empty() && temperatures[st.top()] < currTemp) {
        int prevDay = st.top();
        st.pop();

        output[prevDay] = currDay - prevDay;
      }
      st.push(currDay);
    }

    return output;
  }
};

int main(int argc, char *argv[]) { return 0; }

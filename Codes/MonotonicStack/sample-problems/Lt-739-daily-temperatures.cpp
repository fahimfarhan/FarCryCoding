#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    int N = temperatures.size();
    vector<int> output(N, 0);

    stack<int> st; // monotonicallyDecreasingStack

    for (int currentDay = 0; currentDay < N; currentDay++) {
      int currentTemp = temperatures[currentDay];
      while (!st.empty() && temperatures[st.top()] < currentTemp) {
        int prevDay = st.top();
        st.pop();
        output[prevDay] = currentDay - prevDay;
      }
      st.push(currentDay);
    }

    return output;
  }
};

int main(int argc, char *argv[]) { return 0; }

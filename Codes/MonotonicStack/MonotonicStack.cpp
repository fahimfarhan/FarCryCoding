#include <bits/stdc++.h>
using namespace std;

#define MIN_MONOTONIC -1
#define MAX_MONOTONIC 1


template <typename T>
class MonotonicStack{
private:
  stack<T> st;
  int type;

public:
  // static int minMonotonic = -1;
  // static int maxMonotonic = 1;

  MonotonicStack(int type = MIN_MONOTONIC) {
    this->type = type;
  }

  ~MonotonicStack() {
    while (!st.empty()){
      st.pop();
    }
    
  }

  bool push(T n) {
    if(st.empty()) {
      st.push(n);
      return true;
    } else if( (type == MAX_MONOTONIC) && (st.top() <= n) ) {  // question: < or <= o.O
      st.push(n);
      return true;
    } else if( (type == MIN_MONOTONIC) && (st.top() >= n) ) {
      st.push(n);
      return true;
    }
    return false;
  }

  T top() {
    //if(!st.empty())
      return st.top();
    //return nullptr;
  }

  void pop() {
    if(!empty())
      st.pop();
  }

  bool empty() {
    return st.empty();
  }

  int size() {
    return st.size();
  }


};


int main() {
  return 0;
}


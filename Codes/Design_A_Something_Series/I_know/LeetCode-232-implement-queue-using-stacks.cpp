#include <bits/stdc++.h>
using namespace std;

class MyQueue {
private:
  stack<int> st;
  stack<int> temp;

public:
    MyQueue() {}
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        if(st.empty()) {
          return -1;
        }
        while (!st.empty()) {
          /* code */
          temp.push(st.top());
          st.pop();
        }
        
        int peekaboo = temp.top();
        temp.pop();

        while(!temp.empty()) {
          st.push(temp.top());
          temp.pop();
        }
        return peekaboo;
    }
    
    int peek() {
        if(st.empty()) {
          return -1;
        }
        
        while (!st.empty()) {
          /* code */
          temp.push(st.top());
          st.pop();
        }
        int peekaboo = temp.top();
        while(!temp.empty()) {
          st.push(temp.top());
          temp.pop();
        }
        return peekaboo;
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main() {

  return 0;
}
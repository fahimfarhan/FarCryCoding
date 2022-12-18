#include <bits/stdc++.h>
using namespace std;

class MyQueue {
private:
  stack <int> main;
  stack <int> temp;

  int top = -1;

  inline void swapStacks(stack<int>& from, stack<int>& to) {
    while(!from.empty())  {
      to.push(from.top());
      from.pop();    
    }
  }
public:
    MyQueue() {
        
    }
    
    void push(int x) {
      if(main.empty()) {
        top = x;
      }
      main.push(x);
    }
    
    int pop() {
      int ret = top;
      swapStacks(main,temp);
      temp.pop();
      if(!temp.empty()) {
        top = temp.top();
      }
      swapStacks(temp,main);
      return ret;
    }
    
    int peek() {
      if(main.empty()) {
        return -1;
      }
      return top;
    }
    
    bool empty() {
      return main.empty();
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

int main (int argc, char *argv[])
{
  cout<<"hello there!\n";
  return 0;
}

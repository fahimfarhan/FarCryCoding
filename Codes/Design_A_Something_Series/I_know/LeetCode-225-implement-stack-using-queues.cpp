#include <bits/stdc++.h>
using namespace std;

class MyStack {
private:
  queue<int> primary, temp;
public:
  MyStack() {}

  void push(int x) {
      primary.push(x);
  }
  
  int pop() {
    if(primary.empty()) {
      return -1;
    }

    int top1 = top();

    int size = primary.size();
    for(int i=0; i<size-1; i++) {
      temp.push(primary.front());
      primary.pop();
    }

    primary.pop(); // so now this is poped

    while (!temp.empty()) {
      /* code */
      primary.push(temp.front());
      temp.pop();
    }
    return top1;
  }
  
  int top() {
    if(primary.empty()) {
      return -1;
    }
    return primary.back();
    
  }
  
  bool empty() {
      
  }
};


int main() {


  return 0;
}
#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
private:
  // int size;
  priority_queue<int> leftQ;  // maxQ, for lower part / left
  // priority_queue <int, vector<int>, greater<int> > pq;
  priority_queue<int, vector<int>, greater<int> > rightQ; // minQ for upper part / right

public:
    MedianFinder() { }
    
    void addNum(int num) {
      if( (!rightQ.empty()) && (rightQ.top() < num) ) {
        rightQ.push(num);
      } else {
        leftQ.push(num);
      }
      int top = 0;
      int delta = leftQ.size() - rightQ.size(); 
      if(delta == 2) {
        top = leftQ.top();
        leftQ.pop();
        rightQ.push(top);
      } else if(delta == -2) {
        top = rightQ.top();
        rightQ.pop();
        leftQ.push(top);
      }
    }
    
    double findMedian() {
      if(leftQ.size() > rightQ.size()) {
        return leftQ.top();
      } else if(rightQ.size() > leftQ.size()) {
        return rightQ.top();
      } else {
        return (leftQ.top() + rightQ.top())*0.5;
      }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
int main() {
  MedianFinder s;
  s.addNum(1);
  cout<<"fm = "<<s.findMedian()<<"\n";
  s.addNum(2);
  cout<<"fm = "<<s.findMedian()<<"\n";
  s.addNum(3);
  cout<<"fm = "<<s.findMedian()<<"\n";
  return 0;
}

void foo() {
  stack<int> st;
}
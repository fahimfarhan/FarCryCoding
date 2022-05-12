#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
private:
  int size;
  priority_queue<int> leftQ;  // maxQ, for lower part / left
  // priority_queue <int, vector<int>, greater<int> > pq;
  priority_queue<int, vector<int>, greater<int> > rightQ; // minQ for upper part / right

public:
    MedianFinder() { 
      size = 0;
      int m = 100000+5;
      leftQ.push(-m);
      rightQ.push(m); // sentinel node for simplifying some conditions
    }
    
    void addNum(int num) {
       //if(num < )
      if(num < leftQ.top()) {
        leftQ.push(num);
      } else { // if(num > rightQ.top()) {
        rightQ.push(num);
      }
      cerr<<"leftQ.size = "<<leftQ.size()<<" rightQ.size = "<<rightQ.size()<<"\n";
      if(rightQ.size() - leftQ.size() > 1) {
        while (rightQ.size() - leftQ.size() > 1){
          /* code */
          leftQ.push(rightQ.top()); rightQ.pop();
        }
        
        cerr<<"case 1"<<"\n";
      } else if(leftQ.size() - rightQ.size() > 1) {
        while(leftQ.size() - rightQ.size() > 1) {
          rightQ.push(leftQ.top()); leftQ.pop();
        }
        cerr<<"case 2"<<"\n";
      }
      cerr<<leftQ.size()<<" "<<rightQ.size()<<"\n";
      size++;    
    }
    
    double findMedian() {
      /*
      if( (size & 1) == 1) {
        // return 0.0+v[ (size>>1) ];
      } else {
        // return 0.5*(0.0 + v[(size>>1)] + v[ (size>>1) - 1]);
      }
      */
      if(leftQ.size() == rightQ.size()) {
        //int leftTop = 0;
        if(leftQ.size() == 1) {
          return 0; // (0 + 0)/2
        }
        return (leftQ.top() + rightQ.top()) * 0.5;
      } else if(leftQ.size() > rightQ.size()) {
        return leftQ.top();
      } else if(rightQ.size() > leftQ.size()) {
        return rightQ.top();
      }
      return 0.0;
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
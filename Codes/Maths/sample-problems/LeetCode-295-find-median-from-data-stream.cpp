#include <bits/stdc++.h>
#include <queue>
using namespace std;

const int SELTINEL_INF = 100000 + 6;

class MedianFinder {
private:
  // int size;
  priority_queue<int> increasing;  // maxQ, for lower part / left
  // priority_queue <int, vector<int>, greater<int> > pq;
  priority_queue<int, vector<int>, greater<int> > decreasing; // minQ for upper part / right

public:
    MedianFinder() { }
    
    void addNum(int num) {
      if( (!decreasing.empty()) && (decreasing.top() < num) ) {
        decreasing.push(num);
      } else {
        increasing.push(num);
      }
      int top = 0;
      int delta = increasing.size() - decreasing.size(); 
      if(delta == 2) {
        top = increasing.top();
        increasing.pop();
        decreasing.push(top);
      } else if(delta == -2) {
        top = decreasing.top();
        decreasing.pop();
        increasing.push(top);
      }
    }
    
    double findMedian() {
      if(increasing.size() > decreasing.size()) {
        return increasing.top();
      } else if(decreasing.size() > increasing.size()) {
        return decreasing.top();
      } else {
        return (increasing.top() + decreasing.top())*0.5;
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

  // [[],[6],[],[10],[],[2],[],[6],[],[5],[],[0],[],[6],[],[3],[],[1],[],[0],[],[0],[]]

  MedianFinder mf;

  int N = 3;           // 11
  int a[] = {1, 2, 3}; // {6, 10, 2, 6, 5, 0, 6, 3, 1, 0, 0};
  for (int i = 0; i < N; i++) {
    mf.addNum(a[i]);
    cout << mf.findMedian() << "\n";
  }

  list<int> mylist;

  return 0;
}

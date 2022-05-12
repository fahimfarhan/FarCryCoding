#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
private:
  int size;
  vector<int> v;

public:
    MedianFinder() { size = 0; }
    
    void addNum(int num) {
      // v.push_back(num);
      // sort(v.begin(), v.end());
      auto lb = lower_bound(v.begin(), v.end(), num);
      int lbIdx = lb - v.begin();
      v.insert(lb, num);
      for(auto x: v) {
        cerr<<x<<",  "<<" ";
      }cerr<<"\n";
      size++;    
    }
    
    double findMedian() {
      if( (size & 1) == 1) {
        return 0.0+v[ (size>>1) ];
      } else {
        return 0.5*(0.0 + v[(size>>1)] + v[ (size>>1) - 1]);
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

  return 0;
}

#include <bits/stdc++.h>
using namespace std;


 // This is the interface that allows for creating nested lists.
 // You should not implement it, or speculate about its implementation
 class NestedInteger {
   public:
     // Return true if this NestedInteger holds a single integer, rather than a nested list.
     bool isInteger() const;

     // Return the single integer that this NestedInteger holds, if it holds a single integer
     // The result is undefined if this NestedInteger holds a nested list
     int getInteger() const;

     // Return the nested list that this NestedInteger holds, if it holds a nested list
     // The result is undefined if this NestedInteger holds a single integer
     const vector<NestedInteger> &getList() const;
 };



class NestedIterator {
private:
  int idx;
  vector<int> v;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
      idx = 0;
      flatten(nestedList);
    }

    void flatten(vector<NestedInteger> &nestedList) {
      for(auto nestedInt: nestedList) {
        if(nestedInt.isInteger()) {
          v.push_back(nestedInt.getInteger());
        } else {
          vector<NestedInteger> temp = nestedInt.getList();
          flatten(temp);
        }
      }
    }
    
    int next() {
      int ret = v[idx];
      idx++;
      return ret;
    }
    
    bool hasNext() {
      return (idx < v.size());
    }
};


int main() {

  return 0;
}
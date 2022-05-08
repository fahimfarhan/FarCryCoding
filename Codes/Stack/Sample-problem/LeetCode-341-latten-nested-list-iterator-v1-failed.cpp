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
  vector<int> st;
  vector< vector<NestedInteger>* > stForNestedLists; 

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
      idx = -1;
      st.push_back(idx);
      stForNestedLists.push_back(&nestedList);      
    }
    
    int next() {
      idx++;
      auto vni = stForNestedLists.back();
      if(idx == vni->size()) {
        // todo: pop, handle logic...
        idx = st.back();
        st.pop_back();
        stForNestedLists.pop_back();

        return next();
      }
      NestedInteger ni = (*vni)[idx]; 
      if(ni.isInteger()) {
        return ni.getInteger();
      } else {
        st.push_back(idx);
        vector<NestedInteger> someNestedList = ni.getList();
        stForNestedLists.push_back(&someNestedList);
        idx = -1;
        return next();
      }
    }
    
    bool hasNext() {
      auto someListAtTop = stForNestedLists.back();
      if( idx < (someListAtTop->size()-1 ) ) {
        return true;
      } else {
        int j = stForNestedLists.size() - 1;

        while(j > 0 && (!stForNestedLists[j]->back().isInteger()) ) {
          int idxk = st[j];
          auto someListK = stForNestedLists[j];

          if(idxk == (someListK->size() - 1) ) {
            j--;
          } else {
            break;
          }
        }

        if(j == 0) {
          return false;
        } 
        return true;
      }   
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main() {

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
  int key, value;

  Node(const int& k, const int& v) {
    this->key = k;
    this->value = v;
  }
};

class LRUCache {
private:
  int capacity = 0;
  unordered_map<int, Node*> mp;
  list<Node*> dlist;  
public:
    LRUCache(int capacity) {
        if(capacity <= 0) {
          this->capacity = 100;
        } else {
          this->capacity = capacity;
        }
    }
    
    int get(int key) {
      auto it = mp.find(key);
      if(it == mp.end()) {
        // doesnot exist
        return -1;
      }
      Node* p = mp[key];

      if(p != dlist.front()) {
        updateFreshness(p);
      }
      return p->value;
    }
    
    void put(int key, int value) {
       remove(key);

       if(dlist.size() >= capacity) {
         int lastKey = dlist.back()->key;
         remove(lastKey);
       } 
       Node *p = new Node(key, value);
       mp[key] = p;
       if(p != dlist.front()) {
         updateFreshness(p);
       } 
    }

    void updateFreshness(Node* p) {
      dlist.remove(p);
      dlist.push_front(p);
    }

    void remove(const int& key) {
      auto it = mp.find(key);
      if(it == mp.end()) {
        // doesnot exist
        return;
      }
      Node *p = it->second;
      dlist.remove(p);
      mp.erase(key);

      delete[] p;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
  return 0;
}

/*
=================================================================
==32==ERROR: AddressSanitizer: alloc-dealloc-mismatch (operator new vs operator delete []) on 0x602000000090
    #6 0x7f2269d800b2  (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
0x602000000090 is located 0 bytes inside of 8-byte region [0x602000000090,0x602000000098)
allocated by thread T0 here:
    #5 0x7f2269d800b2  (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
==32==HINT: if you don't care about these errors you may set ASAN_OPTIONS=alloc_dealloc_mismatch=0
==32==ABORTING
*/
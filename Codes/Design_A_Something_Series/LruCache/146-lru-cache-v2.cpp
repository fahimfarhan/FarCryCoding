#include <bits/stdc++.h>
using namespace std;

class Node{
public:
  int key, value;
    Node* prev;
    Node* next;
  Node(const int& k, const int& v) {
    this->key = k;
    this->value = v;

    prev = nullptr;
    next = nullptr;
  }

  ~Node() {
    prev = nullptr;
    next = nullptr;
  }
};

class DoublyLinkedList{
private:
  // sentinel nodes for convenience
  Node *head;
  Node *tail;
public:
  DoublyLinkedList() {
    head = new Node(0, 0);
    tail = new Node(0, 0);

    head->next = tail;
    tail->prev = head;
  }

  Node* front() {
    Node* p = head->next;
    if(p == tail) 
      return nullptr;
    return p;
  }

  Node* back() {
    Node* p = tail->prev;
    if(p == head)
      return nullptr;
    return p;
  }

  void push_front(Node* p) {
    if(p == nullptr) 
      return;
    Node* next = head->next;
    head->next = p; p->next = next;
    next->prev = p; p->prev = head;

    next = nullptr;
    p = nullptr;
  }

  void push_back(Node* p) {
    if(p == nullptr) 
      return;
    Node* prev = tail->prev;
    tail->prev = p; p->prev = prev;
    prev->next = p; p->next = tail;
  
    prev = nullptr;
    p = nullptr;
  }

  void remove(Node* p) {
    if(p == nullptr) 
      return;
    Node* prev = p->prev;
    Node* next = p->next;

    prev->next = next;
    next->prev = prev;
  
    prev = nullptr;
    next = nullptr;
    p = nullptr;
  }

};

class LRUCache {
private:
  // variables
  int capacity = 0;
  unordered_map<int, Node*> mp;
  DoublyLinkedList dlist;
  
  // Auxiliary methods
  void remove(const int& key) {
    auto it = mp.find(key);
    if(it == mp.end()) {
      // not found, so it does not exist
      return;
    }
    Node *p = it->second;
    if(p == nullptr) {
      return;
    }
    dlist.remove(p);
    mp.erase(p->key);

    try{
        delete p;
    } catch(exception &x) {
      cerr<<"inside remove exception: "<<x.what()<<"\n";
    }
    
    p = nullptr;
  }

  void updateLruCache(Node* p) {
    if(p == nullptr) 
      return;
    dlist.remove(p);
    dlist.push_front(p);
    p = nullptr;
  }


public:
    LRUCache(int capacity) {
        if( capacity <= 0 ) {
          this->capacity = 100;
        } else {
          this->capacity = capacity;
        }
    }
    
    int get(int key) {
        auto it = mp.find(key);
        if(it == mp.end()) {
          // not found, so it does not exist
          return -1;
        }
        Node *p = it->second;
        if(p != dlist.front()) {
          updateLruCache(p);
        }
        int value = p->value;
        p = nullptr;
        
        return value;
    }
    
    void put(int key, int value) {
      remove(key);       
      if(mp.size() >= capacity) {
        remove(dlist.back()->key);
      }
      Node *node = new Node(key, value);
      mp[key] = node;
      dlist.push_front(node);
      node = nullptr;
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
AddressSanitizer:DEADLYSIGNAL
=================================================================
==31==ERROR: AddressSanitizer: SEGV on unknown address (pc 0x00000034e1e5 bp 0x7ffd753c2e50 sp 0x7ffd753c2d80 T0)
==31==The signal is caused by a READ memory access.
==31==Hint: this fault was caused by a dereference of a high value address (see register values below).  Dissassemble the provided pc to learn which register was used.
    #5 0x7f670d9bd0b2  (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
AddressSanitizer can not provide additional info.
==31==ABORTING
*/
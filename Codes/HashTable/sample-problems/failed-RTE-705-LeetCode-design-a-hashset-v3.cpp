// 705-LeetCode-design-a-hashset.cpp

#include <bits/stdc++.h>
using namespace std;

#define N 1009 // also, 1009 is a prime!

class Node{
public:
    int n;
    Node* next;

    Node() { n = 0; next = nullptr; }

    ~Node() {
        if(next!=nullptr) {
            delete next;
            next = nullptr;
        }
    }
};

class LinkedList{
private:
    Node* header = nullptr;


    void destructor(Node* p) {
        if(p == nullptr) return;

        if(p->next != nullptr) {
            destructor(p->next);
        }
        p->next = nullptr;
        delete p;
    }


public:
    LinkedList() {
        header = new Node();  // Warning: header is just a dummy node. Don't save a value inside header. it will destroy integrity.
    }

    ~LinkedList() {
        destructor(header);
    }

    // -----------------------------------


    void add(const int& key) {
        // if(header == nullptr) {
        //     header = new Node();
        // }

        pair<bool, Node*> u = contains(key);
        if(u.first) return;

        Node* tail = u.second;
        
        Node* p = new Node();
        p->n = key;

        tail->next = p;

        tail = nullptr;
        p = nullptr;
    }


    /**
     * @Brief: return pair<bool, node* > 
     * bool => is found 
     * 
     * node* => Node(key)->next
     * 
     * So after first recursive return, we'll get true, someNode
     * therefore, p->next = someNode will alter the linkedList properly!
     *  
     * */
    void remove(const int& key) {
        remove(key, header);
    }

    pair<bool, Node*> remove(const int& key, Node* p) {
        if(p == nullptr) return {false, nullptr};

        if(p->n == key) {
            // case 1: found
            pair<bool, Node*> ret = {true, p->next};

            p->next = nullptr;
            delete p;

            return ret;
        }

        pair<bool, Node*> u = remove(key, p->next);

        // here is the trick!
        if(u.first == false) {
            return u;
        }

        if(u.second == nullptr){
            return u;
        }

        p->next = u.second;
        return {true, nullptr};

    }
    

    /** @brief: if found, return (true, pointerToFoundElement), else {false, tail}
     * You can use the tail in add() method!
     * */
    pair<bool, Node*> contains(const int& key) {
        // if(header == nullptr) {
        //     header = new Node();
        // }

        Node* p = header;
        // if(p == nullptr) return nullptr;

        bool found = false;
        while(p->next!=nullptr) {
            p = p->next;
            if(p->n == key) {
                found = true;
                break;
            }
        }

        return {found, p};

        // if(found) return p;
        // return nullptr;
    }

};


class MyHashSet {
private:
    LinkedList mp[N];

public:

	MyHashSet() {}
    
    void add(const int& key) { 
        // key = qN + r
        int q = key / N;
        int r = key - q*N;

        mp[r].add(q);
    }
    
    void remove(const int& key) { 
        // key = qN + r
        int q = key / N;
        int r = key - q*N;

        mp[r].remove(q);
    }

    bool contains(const int& key) {
        // key = qN + r
        int q = key / N;
        int r = key - q*N;

        return mp[r].contains(q).first;
        
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	MyHashSet st;

	return 0;
}


=================================================================
==31==ERROR: AddressSanitizer: heap-use-after-free on address 0x6020000000b8 at pc 0x00000034bb21 bp 0x7ffd0dc21f30 sp 0x7ffd0dc21f28
READ of size 8 at 0x6020000000b8 thread T0
    #5 0x7f7ffccbe0b2  (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
0x6020000000b8 is located 8 bytes inside of 16-byte region [0x6020000000b0,0x6020000000c0)
freed by thread T0 here:
    #6 0x7f7ffccbe0b2  (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
previously allocated by thread T0 here:
    #4 0x7f7ffccbe0b2  (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
Shadow bytes around the buggy address:
  0x0c047fff7fc0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7fd0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7fe0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7ff0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff8000: fa fa fd fa fa fa fd fa fa fa fd fa fa fa 00 00
=>0x0c047fff8010: fa fa 00 00 fa fa fd[fd]fa fa 00 00 fa fa 00 00
  0x0c047fff8020: fa fa 00 00 fa fa 00 00 fa fa 00 00 fa fa 00 00
  0x0c047fff8030: fa fa 00 00 fa fa 00 00 fa fa 00 00 fa fa 00 00
  0x0c047fff8040: fa fa 00 00 fa fa 00 00 fa fa 00 00 fa fa 00 00
  0x0c047fff8050: fa fa 00 00 fa fa 00 00 fa fa 00 00 fa fa 00 00
  0x0c047fff8060: fa fa 00 00 fa fa 00 00 fa fa 00 00 fa fa 00 00
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07 
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
  Shadow gap:              cc
==31==ABORTING
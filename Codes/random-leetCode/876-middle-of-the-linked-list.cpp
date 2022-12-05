#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {

  pair<int, ListNode *> f(ListNode *node, int size) {
    int idx = size - 1;

    pair<int, ListNode *> p;
    if (node->next == nullptr) {
      p = {(size >> 1), nullptr};
    } else {
      p = f(node->next, (size + 1));
    }

    if (p.first == idx) {
      p.second = node;
    }
    return p;
  }

public:
  ListNode *middleNode(ListNode *head) { return f(head, 1).second; }
};

int main(int argc, char *argv[]) { return 0; }

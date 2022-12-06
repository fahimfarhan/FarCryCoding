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
public:
  ListNode *oddEvenList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode *odhead = head;
    ListNode *evhead = head->next;

    ListNode *od = odhead;
    ListNode *ev = evhead;

    while (od->next && ev->next) {
      od->next = od->next->next;
      od = od->next;

      ev->next = ev->next->next;
      ev = ev->next;
    }

    od->next = evhead;

    return odhead;
  }
};

void printer(ListNode *head) {
  while (head != nullptr) {
    cerr << head->val << "->";
    head = head->next;
  }
  cerr << "\n";
}

int main(int argc, char *argv[]) {

  ListNode n5(5);
  ListNode n4(4, &n5);
  ListNode n3(3, &n4);
  ListNode n2(2, &n3);
  ListNode n1(1, &n2);

  printer(&n1);

  Solution s;
  auto p = s.oddEvenList(&n1);

  printer(p);
  return 0;
}

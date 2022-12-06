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
    if (head == nullptr) {
      return nullptr;
    }

    ListNode *od = nullptr, *ev = nullptr, *ot = nullptr, *et = nullptr;

    ListNode *temp = nullptr;

    bool isOdd = true;
    while (head != nullptr) {
      temp = head;
      head = head->next;
      temp->next = nullptr;

      if (isOdd) {
        if (ot == nullptr) {
          od = temp;
          ot = od;
        } else {
          ot->next = temp;
          ot = ot->next;
        }
      } else {
        if (et == nullptr) {
          ev = temp;
          et = ev;
        } else {
          et->next = temp;
          et = et->next;
        }
      }

      isOdd = !isOdd;
    }

    ot->next = ev;
    return od;
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

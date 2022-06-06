#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      map<ListNode*, int> count;

      ListNode* p = headA;

      while (p!=nullptr) {
        count[p]++;
        p = p->next;
      }

      p = headB;
      while(p!=nullptr) {
        count[p]++;
        if(count[p] == 2) {
          break;
        }
        p = p->next;
      }

      return p;
    }
};

int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}

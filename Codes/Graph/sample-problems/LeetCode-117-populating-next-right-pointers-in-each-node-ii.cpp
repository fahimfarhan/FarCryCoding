#include <bits/stdc++.h>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
  Node* connect(Node* root) {
    if(root == nullptr) {
      return root;
    }
    bts(root);
    return root;  
  }
private:
  void bts(Node* node) {
    queue< pair<Node*, int> > q;
    q.push({node, 0});
    
    while(!q.empty()) {
      auto p = q.front();
      q.pop();

      if( (!q.empty()) && (p.second == q.front().second) ) {
        p.first->next = q.front().first;
      } else {
        p.first->next = nullptr;
      }

      int h = p.second + 1;
      if(p.first->left!=nullptr) {
        q.push({p.first->left, h});
      }

      if(p.first->right!=nullptr) {
        q.push({p.first->right, h});
      }
    }
  }
};

int main() {

  return 0;
}
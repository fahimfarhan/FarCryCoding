#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    bool areCurrentNodesSame = true, areLeftNodesSame = true,
         areRightNodesSame = true;

    if (p == nullptr && q == nullptr) {
      return true;
    }

    if (p != nullptr && q != nullptr) {
      areCurrentNodesSame = (p->val == q->val);

      if (!areCurrentNodesSame) {
        return false;
      }

      areLeftNodesSame = isSameTree(p->left, q->left);
      if (!areLeftNodesSame) {
        return false;
      }

      areRightNodesSame = isSameTree(p->right, q->right);
      if (!areRightNodesSame) {
        return false;
      }

      return true; // (areCurrentNodesSame && areLeftNodesSame &&
                   // areRightNodesSame);
    }

    // p = null, q != null
    // p != null, q = null
    return false;
  }
};

int main(int argc, char *argv[]) { return 0; }

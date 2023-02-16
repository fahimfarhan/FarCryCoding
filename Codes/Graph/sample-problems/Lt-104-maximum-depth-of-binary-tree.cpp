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
  int maxDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    int n = 1; // the height of the root
    n = max(maxDepth(root->left, 1), maxDepth(root->right, 1));
    return n;
  }

  int maxDepth(TreeNode *root, int h) {
    if (root == nullptr) {
      return h;
    }
    int n = max(maxDepth(root->left, (h + 1)), maxDepth(root->right, (h + 1)));
    return n;
  }
};
int main(int argc, char *argv[]) { return 0; }

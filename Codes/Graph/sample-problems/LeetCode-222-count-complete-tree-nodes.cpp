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
  int countNodes(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int totalNodesInLeftSubTree = countNodes(root->left);
    int totalNodesINRightSubTree = countNodes(root->right);
    int currNodeCount = 1;

    return totalNodesInLeftSubTree + totalNodesINRightSubTree + currNodeCount;
  }
};

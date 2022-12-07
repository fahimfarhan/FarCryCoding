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
  int rangeSumBST(TreeNode *root, int low, int high) {

    return dfs(root, low, high);
  }

  int dfs(TreeNode *node, int lo, int hi) {
    int result = 0;
    if (lo <= node->val && node->val <= hi) {
      result += node->val;
    }

    if (node->left != nullptr) {
      result += dfs(node->left, lo, hi);
    }

    if (node->right != nullptr) {
      result += dfs(node->right, lo, hi);
    }

    return result;
  }
};

int main(int argc, char *argv[]) { return 0; }

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
  vector<int> preorderTraversal(TreeNode *node, vector<int> &v) {
    // base case
    if (node == nullptr) {
      return v;
    }

    // recursive case
    v.push_back(node->val);
    preorderTraversal(node->left, v);
    preorderTraversal(node->right, v);
    return v;
  }

public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> output;
    return preorderTraversal(root, output);
  }
};

int main(int argc, char *argv[]) { return 0; }

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
  vector<int> postorderTraversal(TreeNode *node, vector<int> &v) {
    // base case
    if (node == nullptr) {
      return v;
    }

    // recursive case
    postorderTraversal(node->left, v);
    postorderTraversal(node->right, v);
    v.push_back(node->val);
    return v;
  }

public:
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> output;
    return postorderTraversal(root, output);
  }
};

int main(int argc, char *argv[]) { return 0; }

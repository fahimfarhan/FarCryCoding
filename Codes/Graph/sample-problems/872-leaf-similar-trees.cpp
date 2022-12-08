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
private:
  vector<int> leaves1;
  vector<int> leaves2;

public:
  bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    dfs(root1, leaves1);
    dfs(root2, leaves2);

    if (leaves1.size() != leaves2.size()) {
      return false;
    }

    int N = leaves1.size();

    bool similar = true;
    for (int i = 0; i < N; i++) {
      if (leaves1[i] != leaves2[i]) {
        similar = false;
        break;
      }
    }

    return similar;
  }

  void dfs(TreeNode *node, vector<int> &v) {
    if (node == nullptr) {
      return;
    }

    if (node->left == nullptr && node->right == nullptr) {
      // leaf confirmed!
      v.push_back(node->val);
    }

    if (node->left != nullptr) {
      dfs(node->left, v);
    }

    if (node->right != nullptr) {
      dfs(node->right, v);
    }
  }
};

int main(int argc, char *argv[]) { return 0; }

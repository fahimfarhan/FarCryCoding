#include <bits/stdc++.h>
#include <climits>
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
  inline int max4(const int &a, const int &b, const int &c, const int &d) {
    int m1 = max(a, b);
    int m2 = max(c, d);
    return max(m1, m2);
  }

  int postOrderDfs(TreeNode *node, int &globalMaximus) {
    if (node == nullptr) {
      return 0;
    }

    int left1 = postOrderDfs(node->left, globalMaximus);
    int right1 = postOrderDfs(node->right, globalMaximus);
    int center = node->val;

    int leftIfExists, rightIfExists;

    if (node->left == nullptr) {
      leftIfExists = INT_MIN;
    } else {
      leftIfExists = center + left1;
    }

    if (node->right == nullptr) {
      rightIfExists = INT_MIN;
    } else {
      rightIfExists = center + right1;
    }

    // at each recursive level, there are 4 paths, center, center+left,
    // center+right, center + left + right
    int localMaximus =
        max4(center, leftIfExists, rightIfExists, left1 + center + right1);

    globalMaximus = max(globalMaximus, localMaximus);
    // so in this local scope, localMaximus is the largest path.
    // if we go to the parent node, it will have a maximal path
    // 1. parent->node
    // 2. parent->node->left,
    // 3. parent->node->right,
    // (parent->node-> left and right is impossible, as node is repeated)
    int considerForGlobalMaximus =
        max(center, max(leftIfExists, rightIfExists));
    return considerForGlobalMaximus;
  }

public:
  int maxPathSum(TreeNode *root) {
    int maximus = INT_MIN;

    postOrderDfs(root, maximus);

    return maximus;
  }
};

int main(int argc, char *argv[]) { return 0; }

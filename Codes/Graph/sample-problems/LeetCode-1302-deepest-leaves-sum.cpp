#include <bits/stdc++.h>
using namespace std;


//  Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
      int sum = 0;
      int depth = 0;
      dfs(root, sum, depth, 1);
      return sum;    
    }

private:
  void dfs(TreeNode* u, int& sum, int& depth, int currDepth) {
    if (u == nullptr) {
      return;
    }
    if ( (u->left == nullptr) && (u->right == nullptr) ) {
      if(currDepth > depth) {
        sum = 0;
        depth = currDepth;
      }

      if(depth == currDepth) {
        sum += u->val;
        return;
      }
    }

    if(u->left!=nullptr) {
      dfs(u->left, sum, depth, (currDepth+1));
    }

    if(u->right!=nullptr) {
      dfs(u->right, sum, depth,(currDepth+1));
    }
  }
};

int main() {

  return 0;
}
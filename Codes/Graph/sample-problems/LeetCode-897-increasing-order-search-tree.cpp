#include <bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
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
    TreeNode* increasingBST(TreeNode* root) {
      return bst(root).first;
    }

    pair<TreeNode*, TreeNode* > bst(TreeNode* node) {
      pair<TreeNode*, TreeNode* > ret = {nullptr, nullptr};

      if(node == nullptr) {
        return ret;
      }

      if( (node->left == nullptr) && (node->right == nullptr) ) {
        return {node, node};
      }

      TreeNode* left = node->left;
      TreeNode* right = node->right;

      node->left = nullptr;
      node->right = nullptr;

      if( (left != nullptr) && (right == nullptr) ) {
        // left + node
        auto l = bst(left);
        l.second->right = node;
        return {l.first, node};
      } else if( (left == nullptr) && (right != nullptr) ) {
        // node + right
        auto r = bst(right);
        node->right = r.first;
        return {node, r.second};
      } else {
        // left + node + right
        auto l = bst(left);
        l.second->right = node;
        
        auto r = bst(right);
        node->right = r.first;
        
        return {l.first, r.second};
      }
      return ret;
    }
};


int main() {


  return 0;
}
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

class BSTIterator {
private:
  vector<TreeNode*> v;
  int idx = -1;
  int vSize = 0;

  void bst(TreeNode* node) {
    if(node == nullptr) {
      return;
    }
    if(node->left != nullptr) {
      bst(node->left);
    }
    v.push_back(node);
    if(node->right != nullptr) {
      bst(node->right);
    }
  }
public:
    BSTIterator(TreeNode* root) {
        v.clear();
        bst(root);
        vSize = v.size();
        idx = -1;
    }

    ~BSTIterator() {
      while (!v.empty())
      {
        /* code */
        v.pop_back();
      }
      
    }
    
    int next() {
        idx++;
        if(idx < vSize) {
          return v[idx]->val;
        }
        return -1;
    }
    
    bool hasNext() {
      return ( (idx+1) < vSize );      
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main() {

  return 0;
}
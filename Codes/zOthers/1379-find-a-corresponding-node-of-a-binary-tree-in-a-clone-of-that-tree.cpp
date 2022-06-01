#include <bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
      queue<TreeNode*> qOriginal;
      queue<TreeNode*> qClone;

      qOriginal.push(original);
      qClone.push(cloned);

      TreeNode* o = nullptr;
      TreeNode* c = nullptr;

      while(!qOriginal.empty()) {
        o = qOriginal.front();
        c = qClone.front();

        qOriginal.pop();
        qClone.pop();

        if(target == o) {
          break;  
        }

        if(o->left!=nullptr) {
          qOriginal.push(o->left);
        }
        if(o->right!=nullptr) {
          qOriginal.push(o->right);
        }

        if(c->left!=nullptr) {
          qClone.push(c->left);
        }
        if(c->right!=nullptr) {
          qClone.push(c->right);
        }
      }   
      return c;
    }
};

int main() {

  return 0;
}
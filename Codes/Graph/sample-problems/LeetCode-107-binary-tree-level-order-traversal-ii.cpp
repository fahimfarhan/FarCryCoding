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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
      vector<vector<int> > v;
      if(root == nullptr) {
        return v;
      }

      queue<pair<TreeNode*, int> > q;
      int depth = 0;
      q.push({root, depth});
      
      unordered_map<int, vector<int> > mp;

      while (!q.empty()){
        auto p = q.front();
        q.pop();

        int d = p.second;
        depth = d;
        auto node = p.first;
        mp[d].push_back(node->val);

        d++;

        if(node->left != nullptr) {
          q.push({node->left, d});
        }

        if(node->right != nullptr) {
          q.push({node->right, d});
        }
      }

      for(int i=depth; i>=0; i--) {
        v.push_back(mp[i]);
      }
      return v;
    }
};

int main() {

  return 0;
}
/**
 * @file 1-Trie.cpp
 * @author Qazi Fahim Farhan (fahim.farhan@outlook.com)
 * @brief 
 * 
 * This is my implementation of trie. I watched 
 * this [youtube tutorial by hackerrank](https://www.youtube.com/watch?v=zIjfhVPRZCg), 
 * and now I'm gonna implement what I literally saw in the video.
 * 
 * [LeetCode problem link](https://leetcode.com/problems/implement-trie-prefix-tree/)
 * 
 * Failed. I forgot about pointers, and addresses :'(
 * 
 * @version 0.1
 * @date 2022-01-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class Node{
public:
  unordered_map<char, ll> mp;
  bool isCompleteWord = false;
  
  Node() {
    isCompleteWord = false;
  }

  ~Node() {
    mp.clear();
  }
};

class Trie{
private:
  Node *root;
public:
 Trie() {
   this->root = new Node();
 }
    
    void insert(string word) {
      Node *curr = root;
      int N = word.size();

      char ch = '\0';
      
      for(int i=0; i<N; i++) {
        ch = word[i];
        // int address = (int)(&root);
        if(!curr->mp[ch]) {
          Node *node = new Node();
          curr->mp[ch] = (ll)(&node);
        }
        curr = (Node*)(curr->mp[ch]);
      }
      curr->isCompleteWord = true;
      curr = nullptr;
    }
    
    bool search(string word) {
        Node *curr = root;
        int N = word.size();
        char ch = '\0';

        for(int i=0; i<N; i++) {
          if(!curr->mp[ch]) {
            return false;
          }
          curr = (Node*)(curr->mp[ch]);
        }
        bool ret = curr->isCompleteWord;
        curr = nullptr;
        return ret; // curr->isCompleteWord;
    }
    
    bool startsWith(string prefix) {
        Node *curr = root;
        int N = prefix.size();
        char ch = '\0';

        for(int i=0; i<N; i++) {
          if(!curr->mp[ch]) {
            return false;
          }
          curr = (Node*)(curr->mp[ch]);
        }
        curr = nullptr;
        return true;
    }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  Trie *trie = new Trie();
  trie->insert("apple");
  cout<<(trie->search("apple"))<<"\n";
  cout<<(trie->startsWith("app"))<<"\n";
  cout<<(trie->search("app"))<<"\n";
  

  return 0;
}
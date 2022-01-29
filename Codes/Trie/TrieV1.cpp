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
  unordered_map<char, Node*> mp;
  bool isCompleteWord = false;
  
  Node() {
    isCompleteWord = false;
  }

  ~Node() {
    mp.clear();
  }
};



class Trie {
public:
    Node *root;
    Trie() {
      root = new Node();
    }
    
    void insert(string word) {
        int N = word.size();
        Node *curr = root;
        char ch = '\0';

        for(int i=0; i<N; i++) {
          ch = word[i];
          bool notFound = curr->mp.find(ch) == curr->mp.end();
          if(notFound) {
            Node *temp = new Node();
            curr->mp[ch] = temp;
            temp = nullptr;
          }
          curr = curr->mp[ch];
        }
        curr->isCompleteWord = true;
        curr = nullptr;
    }
    
    bool search(string word) {
        Node *p = getNode(word);
        bool isFound = false;
        if(p!=nullptr) {
          isFound = p->isCompleteWord;
        }
        p = nullptr;
        return isFound;
    }
    
    bool startsWith(string prefix) {
        Node *p = getNode(prefix);
        bool startsWithInput = (p!=nullptr);
        p = nullptr;

        return startsWithInput;
    }

    Node* getNode(const string& prefix) {
      Node *curr = root;
      int N = prefix.size();
      char ch = '\0';

      for(int i=0; i<N; i++) {
        ch = prefix[i];
        bool notFound = curr->mp.find(ch) == curr->mp.end();
        if(notFound) {
          curr = nullptr;
          break;
        }
        curr = curr->mp[ch];
      }
      return curr;
    }

    // destructor
    ~Trie() {
      // cout<<"destroying Trie\n";
      startDfs();
    }

    void startDfs() {
      for(auto p: root->mp) {
        if(p.second!=nullptr) {
          dfs(p.second);
        }
      }
      delete root;
    }
    void dfs(Node *u) {
      Node *v;
      for(auto p: u->mp) {
        if(p.second!=nullptr) {
          v = p.second;
          dfs(v);
        }
      }
      delete u;
      // cout<<"destroyed some u\n";
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  unordered_map<char, Node> mp;
  Node n1, n2;
  mp['a'] = n1;
  mp['b'] = n2;

  Node node = mp['a'];

  bool b1 = mp.find('a') == mp.end();
  bool notFound = mp.find('c') == mp.end();

  cout<<b1<<" "<<notFound<<'\n';

  Trie *trie = new Trie();
  trie->insert("apple");
  cout<<(trie->search("apple"))<<"\n";
  cout<<(trie->startsWith("app"))<<"\n";
  cout<<(trie->search("app"))<<"\n";

  delete trie;
  
  return 0;
}
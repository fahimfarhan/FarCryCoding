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
 * This version uses arrays instead of hashMap(unordered_map in cpp)
 * @version 0.2
 * @date 2022-01-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>
using namespace std;


#define ll long long int
#define SIZE 52

class Node{
public:
  // unordered_map<char, Node*> mp;
  Node* mp[SIZE] = {nullptr};
  bool isCompleteWord = false;
  
  Node() {
    isCompleteWord = false;
  }

  ~Node() {
    // mp.clear();
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
        char c = '\0';

        for(int i=0; i<N; i++) {
          c = word[i];

          int pos = getIndex(c);

          bool notFound = (curr->mp[pos] == nullptr); // curr->mp.find(ch) == curr->mp.end();
          if(notFound) {
            Node *temp = new Node();
            curr->mp[pos] = temp;
            temp = nullptr;
          }
          curr = curr->mp[pos];
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
    // Auxiliary methods
    char getChar(const int& somePos) {
      // cout<<"debugX "<<somePos<<" ";
      if((0<=somePos) && (somePos < 26)) {
        char ret = (char)(somePos + (int)'A');
        // cout<<"debugX1 "<<ret<<"\n";
        return ret;
      } else if((26<=somePos) && (somePos < 52)) {
        char ret = (char)(somePos + (int)'a' - 26);
        // cout<<"debugX2 "<<ret<<"\n";
        return ret;
      }
      return '\0';
    }

    int getIndex(const char& c) {
      if(('A' <=c) && (c<='Z')) {
        return (c - 'A');
      } else if(('a' <= c) && (c <= 'z')) {
        return (c - 'a' + 26);
      }
      return -1;
    }

    Node* getNode(const string& prefix) {
      Node *curr = root;
      int N = prefix.size();
      char c = '\0';

      for(int i=0; i<N; i++) {
        c = prefix[i];
        int pos = getIndex(c);
        bool notFound = curr->mp[c]; // curr->mp.find(ch) == curr->mp.end();
        if(notFound) {
          curr = nullptr;
          break;
        }
        curr = curr->mp[pos];
      }
      return curr;
    }

    // destructor
    ~Trie() {
      cout<<"destroying Trie\n";
      startDfs();
      cout<<"destroyed Trie\n";
    }

    void startDfs() {
      for(int i=0; i<SIZE; i++) {
        if(root->mp[i] != nullptr) {
          dfs(root->mp[i], i);
        }
      }

      delete root;
    }
    void dfs(Node *u, const int& somePos) {
      Node *v;
      
      for(int i=0; i<SIZE; i++) {
        v = u->mp[i];
        if(v != nullptr) {
          dfs(v, i);  
        }
      }
      
      delete u;
      cout<<"destroyed "<<getChar(somePos)<<"\n";
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

 //int pos = '{' - 
  //cout<<"{ = "<<
  
  return 0;
}
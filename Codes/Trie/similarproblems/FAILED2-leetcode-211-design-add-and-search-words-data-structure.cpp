/**
 * @file leetcode-211-design-add-and-search-words-data-structure.cpp
 * @author Qazi Fahim Farhan (fahim.farhan@outlook.com)
 * @brief 
 * 
 * This is my implementation of trie. I watched 
 * this [youtube tutorial by hackerrank](https://www.youtube.com/watch?v=zIjfhVPRZCg), 
 * and now I'm gonna implement what I literally saw in the video.
 * 
 * [LeetCode problem link](https://leetcode.com/problems/design-add-and-search-words-data-structure/)
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



class WordDictionary { // Trie {
public:
    Node *root;
    WordDictionary() { // Trie() {
      root = new Node();
    }
    
    void addWord(string word) { // void insert(string word) {
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
    
    bool searchOriginal(string word) {
        Node *p = getNode(word);
        bool isFound = false;
        if(p!=nullptr) {
          isFound = p->isCompleteWord;
        }
        p = nullptr;
        return isFound;
    }
    
    bool search(string word) {
      int N = word.size() - 1;
      int lastInclusive = -1;
      for(int i=N; i>=0; i--) {
        if(word[i] != '.') {
          lastInclusive = i; 
          break;
        }
      }
      int len = lastInclusive - 0 + 1;
      // cerr<<len<<" = len debugX\n";
      string prefix = word.substr(0, len);
      return startsWith(prefix);
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

    Node* getNode(const string& prefix, Node* startNode = nullptr, const int& start = 0) {
      if(prefix.size() == 0) {
        return root;
      }

      Node *curr;
      if(startNode == nullptr) {
        curr = root;
      } else {
        curr = startNode;
      }

      Node *temp = nullptr;
      
      int N = prefix.size();

      if(start >= N) {
        return nullptr;
      }

      char c = '\0';

      for(int i= start; i<N; i++) {
        c = prefix[i];
        if(c == '.') {
          int k = i + 1;
          for(int j=0; j<SIZE; j++) {
            if(curr->mp[j]!=nullptr) {
              temp = getNode(prefix, curr->mp[j], k);
              if(temp != nullptr) {
                return temp;
              }
            }
          }
          
          return nullptr;
          
        } else {
          int pos = getIndex(c);
          bool notFound = (curr->mp[pos] == nullptr); // curr->mp.find(ch) == curr->mp.end();
          if(notFound) {
            curr = nullptr;
            break;
          }
          curr = curr->mp[pos];
        }
        
      }
      return curr;
    }

    // destructor
    ~WordDictionary() { // ~Trie() {
      // cout<<"destroying Trie\n";
      startDfs();
      // cout<<"destroyed Trie\n";
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
      // cout<<"destroyed "<<getChar(somePos)<<"\n";
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

  // bool b1 = mp.find('a') == mp.end();
  bool notFound = mp.find('c') == mp.end();

  // cout<<b1<<" "<<notFound<<'\n';

  WordDictionary *wordDictionary = new WordDictionary();
  // wordDictionary->addWord("bad");
  // wordDictionary->addWord("dad");
  // wordDictionary->addWord("mad");  
  wordDictionary->addWord("a");
  // bool b1 = wordDictionary->search("."); // return False  
  // bool b2 = wordDictionary->search("bad"); // return True
  // bool b3 = wordDictionary->search(".ad"); // return True
  // bool b4 = wordDictionary->search("b.."); // return True

  // cout<<b1<<" "<<b2<<" "<<b3<<" "<<b4<<"\n";

//["WordDictionary","addWord","addWord","search","search","search","search","search","search"]
//[[],               ["a"],     ["a"],    ["."],    ["a"],   ["aa"],  ["a"],  [".a"],  ["a."]]

  wordDictionary->addWord("a");
  wordDictionary->addWord("a");
  bool b1 = wordDictionary->search("a.");
  cout<<"b1 = "<<b1<<"\n";

  delete wordDictionary;
  
  return 0;
}
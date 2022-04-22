#include <bits/stdc++.h>
using namespace std;


class Node{
public:
	int n;
	Node* next;
	Node* down;

	Node() {
		n = -1;
		next = nullptr;
		down = nullptr;
	}

	~Node() {
		if(next!=nullptr) delete next;
		if(down!=nullptr) delete down;
	
		next = nullptr;
		down = nullptr;
	}

};

class Skiplist {
private:
	Node* normalLane; // sentinel node
	Node* expressLane; // sentinel node

	int normalLaneSize = 0;
	int expressLaneSize = 0;

	int coin = 0;
	bool flipCoin() {  // if true, insert inside the express lane
		coin++;
		if(coin == expressLaneSize) coin = 0;
		return (coin == 0);
	}

public:
  Skiplist() {
    normalLane = new Node();
    expressLane = new Node();
    expressLane->down = normalLane;
  }

  ~Skiplist() {
    if(expressLane!=nullptr) {
      expressLane->down = nullptr;
      delete expressLane;
    } 
  
  	if(normalLane!=nullptr) delete normalLane;
  	
  	normalLane = nullptr;
  	expressLane = nullptr;
  }
  
  bool search(int target) {
      Node* curr = expressLane;
			while( (curr->next!=nullptr) && (target <= curr->next->n) ) {
      	curr = curr->next;
      }

      bool found = false;
      if(curr->n == target) {
      	found = true;
      	curr = nullptr;
      	return found;
      }

      curr = curr->down;
			while( (curr->next!=nullptr) && (target <= curr->next->n) ) {
      	curr = curr->next;
      }
      found = (curr->n == target);
      return found;
  }
  
  void add(int target) {
      normalLaneSize++;
      expressLaneSize = sqrt(normalLaneSize);

      bool isHead = flipCoin();

      Node* curr = expressLane;
      Node* temp = nullptr;
      
      while( (curr->next!=nullptr) && (target < curr->next->n) ) {
      	curr = curr->next;
      }

      if(isHead) {
      	temp = new Node();
      	temp->n = target;
      	temp->next = curr->next;
      }

      curr = curr->down; // so now we are in the normal lane
			while( (curr->next!=nullptr) && (target < curr->next->n) ) {
        // if(target < curr->next->n)
        	curr = curr->next;
        // else break;
      }

      Node* temp2 = new Node();
      temp2->n = target;

      temp2->next = curr->next;
      curr->next = temp2;

      if(temp!=nullptr) {
	      temp->down = temp2;
  	    temp = temp2;
      }
      
      // all temp variables to null
      curr = nullptr;
      temp = nullptr;
      temp2 = nullptr;
  }
  
  bool erase(int num) {
      bool isErased = false;
      normalLaneSize--;
      expressLaneSize = sqrt(normalLaneSize);
  
      Node* curr = expressLane;
      Node* temp = nullptr;
      Node* temp2 = nullptr;
      
      while( (curr->next!=nullptr) && (num < curr->next->n) ) {
      	curr = curr->next;
      }

      if( (curr->next != nullptr) && curr->next->n == num ) {
      	temp = curr->next;
      	curr->next = temp->next;
      	temp->next = nullptr;
        isErased = true;
      }

      curr = curr->down; // now we are in normalLane
			
			while( (curr->next!=nullptr) && (num < curr->next->n) ) {
      	curr = curr->next;
      }

      if( (curr->next != nullptr) && (curr->next->n == num) ) {
      	temp2 = curr->next;
      	curr->next = temp2->next;
      	temp2->next = nullptr;
              isErased = true;
      }

      delete temp;
      delete temp2;

      curr = nullptr;
      temp = nullptr;
      temp2 = nullptr;
    return isErased;
  }


};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */

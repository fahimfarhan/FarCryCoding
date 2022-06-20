import java.util.*;

class Node {
  Node prev = null;
  Node next = null;
  int key = 0;
  int value = 0;

  public Node(int key,int value){
    this.key=key;
    this.value=value;
  }
}

class LRUCache {
  HashMap<Integer, Node> mp = new HashMap<>();
  Node head = new Node(0, 0);
  Node tail = new Node(0,0);
  int capacity = 5;

  public LRUCache(int capacity) {
      this.capacity = capacity;
      head.next = tail;
      tail.prev = head;
  }
  
  public int get(int key) {
    if(mp.containsKey(key)) {
      Node node = mp.get(key);
      delete(node);
      insert(node);
      return node.value;
    }
    return -1;      
  }
  
  public void put(int key, int value) {
      
    Node temp = null;
      
    if(mp.containsKey(key)) {
        temp = mp.get(key);
        delete(temp);
      }

      if(mp.size() >= capacity) {
        delete(tail.prev);  
      }

      if(temp == null) {
        temp = new Node(key, value);
      } else if(temp.value != value) {
        temp.value = value;
      }

      temp.prev = null;
      temp.next = null;

      insert(temp);
  }

  // ---------
  private void delete(Node node) {
    mp.remove(node.key);
    node.prev.next = node.next;
    node.next.prev = node.prev;
  }

  private void insert(Node node) {
    mp.put(node.key, node);
    Node formerHeadNext = head.next;

    head.next = node;
    node.prev = head;

    node.next = formerHeadNext;
    formerHeadNext.prev = node;

  }
}

/**
* Your LRUCache object will be instantiated and called as such:
* LRUCache obj = new LRUCache(capacity);
* int param_1 = obj.get(key);
* obj.put(key,value);
*/
// 706-design-hashmap.cpp
#include <bits/stdc++.h>

using namespace std;

#define N 10005

class MyHashMap {
public:
   	int mp[N] = {-1};
    MyHashMap() {
    	memset(mp, -1, sizeof(mp));
    }
    
    void put(int key, int value) {
        mp[key] = value;
    }
    
    int get(int key) {
        return mp[key];
    }
    
    void remove(int key) {
        mp[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);



	return 0;
}
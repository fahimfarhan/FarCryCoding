// 705-LeetCode-design-a-hashset.cpp

#include <bits/stdc++.h>
using namespace std;


#define N 1000001 // also, 1009 is a prime!

class MyHashSet {
public:
		bool dp[N] = {false};

		MyHashSet() {}
    
    void add(int key) {
				dp[key] = true;
    }
    
    void remove(int key) { 
        dp[key] = false;
    }
    
    bool contains(int key) {
        return dp[key]; 
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	MyHashSet st;

	return 0;
}

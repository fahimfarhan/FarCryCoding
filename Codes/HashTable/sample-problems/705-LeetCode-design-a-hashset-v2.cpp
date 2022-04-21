// 705-LeetCode-design-a-hashset.cpp

#include <bits/stdc++.h>
using namespace std;

#define N 1009 // also, 1009 is a prime!


class MyHashSet {
public:
    vector<int> mp[N];

	MyHashSet() {}
    
    void add(const int& key) { 
        // key = qN + r
        int q = key / N;
        int r = key - q*N;
    
        if(contains_internal(q, r) != -1) {
            return;
        }
        
        mp[r].push_back(q);

    }
    
    void remove(const int& key) { 
        // key = qN + r
        int q = key / N;
        int r = key - q*N;
    
        int somePos = contains_internal(q, r);
        if(somePos == -1) {
            return;
        }

        // https://stackoverflow.com/a/63598736/9053942
        mp[r].erase(mp[r].begin() + somePos);
    }

    bool contains(const int& key) {
        // key = qN + r
        int q = key / N;
        int r = key - q*N;

        int pos = contains_internal(q, r);
        if(pos == -1) return false;
        return true;
    }
    
    int contains_internal(const int& q, const int& r) {
        // key = qN + r
        
        int tempSize = mp[r].size();
        int foundPosition = -1;
        for(int i=0; i<tempSize; i++) {
            if(mp[r][i] == q) {
                foundPosition = i;
                break;
            }
        }

        return foundPosition; 
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

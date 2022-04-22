#include <bits/stdc++.h>
using namespace std;

#define N 1009 // also, 1009 is a prime!


class MyHashMap {
public:
    vector<pair<int,int> > mp[N];

	MyHashMap() {}
    
    void put(const int& key, const int& value) { 
        // key = qN + r
        int q = key / N;
        int r = key - q*N;
    
        vector<pair<int, int> >::iterator it;

        for(it = mp[r].begin(); it != mp[r].end(); it++) {
            if(it->first == key) {
                break;
            }
        }
                
        if(it != mp[r].end()) {
            it->second = value;
        } else {
            mp[r].push_back({q, value});
        }
    }
    
    void remove(const int& key) { 
        // key = qN + r
        int q = key / N;
        int r = key - q*N;
    
        int somePos = -1;

        int tempSize = mp[r].size();
        for(int i=0; i < tempSize; i++) {
            if(mp[r][i].first == q) {
                somePos = i;
                break;
            }
        }


        if(somePos == -1) {
            return;
        }

        // https://stackoverflow.com/a/63598736/9053942
        mp[r].erase(mp[r].begin() + somePos);
    }

    int get(const int& key) {
        // key = qN + r
        int q = key / N;
        int r = key - q*N;

        vector<pair<int, int> >::iterator it;

        for(it = mp[r].begin(); it != mp[r].end(); it++) {
            if(it->first == key) {
                break;
            }
        }

        if(it == mp[r].end()) return -1;
        return it->second;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

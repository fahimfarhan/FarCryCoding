#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
private:
  map<int, int> mp;
  vector<int> v;

public:
  RandomizedSet() {}

  bool insert(int val) {
    auto it = mp.find(val);

    if (it != mp.end()) {
      return false;
    }

    v.push_back(val);
    int pos = v.size() - 1;
    mp[val] = pos;
    return true;
  }

  bool remove(int val) {
    auto it = mp.find(val);
    if (it == mp.end()) {
      return false;
    }
    int pos = it->second;
    int lastPos = v.size() - 1;

    swap(v[pos], v[lastPos]);
    mp[v[pos]] = pos;

    // the actual delete operation
    mp.erase(val);
    v.pop_back();

    return true;
  }

  int getRandom() {
    int pos = rand() % v.size();
    return v[pos];
  }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main(int argc, char *argv[]) { return 0; }

// Lt-2870-minimum-number-of-operations-to-make-array-empty.cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
  		unordered_map<int, int> mp;

  		for(int num: nums) {
  			mp[num]++;
  		}

			unordered_map<int, int>::iterator it;

			int q = 0, r = 0;
			int minimus = 0;
			for(it = mp.begin(); it != mp.end(); it++) {
				// cerr<<"it->first "<<it->first<<"\n";
				// base cases 1
				if(1 == it->second) {
					minimus = -1;
					// cerr<<"Case 1: "<<minimus<<"\n";
					break;
				}
				// base case 2
				if(2 == it->second) {
					minimus +=1;
					// cerr<<"Case 2: "<<minimus<<"\n";
					continue;
				}

				// other cases N
				q = ((it->second) / 3);
				r = ((it->second) % 3);
				// cout<<"Case N: q: "<<q<<" r: "<<r<<" ";
				if(r == 0) {
					minimus += q;
					// cout<<"case N1: "<<minimus<<"\n";
				} else if(r == 1) {
					minimus += (q+1); // minimus += (q-1)(for 3) + 2(for 2)
					// cout<<"case N2: "<<minimus<<"\n";
				} else {
					minimus += (q+1);  // q (for 3) + 1(for 2)
					// cout<<"case N3: "<<minimus<<"\n";
				}
			}

			return minimus;
  		
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	Solution s;
	vector<int> v = {2,3,3,2,2,4,2,3,4};
	
	int output = s.minOperations(v);

	cout<<output<<"\n";
	
	return 0;
}
// Lt-1879-redistribute-characters-to-make-all-strings-equal.cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int mp[26] = {0};

        int N = words.size();
        int M = 0;

        for(int i=0; i<N; i++) {
        	M = words[i].size();
        	for(int j = 0; j < M; j++) {
        		mp[ (int)(words[i][j] - 'a') ]++;
        	}
        }



        bool possible = true;

        for(int i=0; i<26; i++) {
        	// cout<<mp[i]<<"\n";
        	if( mp[i] != 0 ) {
        		if(mp[i] % N != 0) {
        			possible = false;
        			break;
        		}
        	}
        }

        return possible;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	Solution s;
	vector<string> v = {"aabc", "bc", "abc"};
	s.makeEqual(v);

	return 0;
}
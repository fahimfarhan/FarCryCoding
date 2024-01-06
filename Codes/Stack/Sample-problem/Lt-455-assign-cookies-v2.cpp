// Lt-455-assign-cookies-v2.cpp
// Lt-455-assign-cookies.cpp
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());

		// vector<int> satisfied;
		int i = g.size() - 1;
		int j = s.size() - 1;
		int satisfiedKidsCount = 0;
		int tmp = 0;
		while( (i >=0) && (j >= 0) ) {
			tmp = (int) (!(g[i] > s[j]));
			i--;
			j-=tmp;
			satisfiedKidsCount+=tmp;
		}


		return satisfiedKidsCount;
    }
};


int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
// Lt-455-assign-cookies.cpp
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());

		// vector<int> satisfied;
		int satisfiedKid = 0;
		int satisfiedKidsCount = 0;

		while( (!g.empty()) && (!s.empty()) ) {
			if(g.back() > s.back() ) {
				g.pop_back();
			} else {
				// satisfiedKid = g.top();
				g.pop_back();
				s.pop_back(); // satisfiedKid ate the top cookie
				// satisfied.push_back()
				satisfiedKidsCount++;
			}
		}
    	return satisfiedKidsCount;
    }
};


int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
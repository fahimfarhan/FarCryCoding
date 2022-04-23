#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	unordered_map<string, string> mp;            // key, value = mainUrl, tinyUrl
	unordered_map<string, string> reverse_mp;    // key, value = tinyUrl, mainUrl
	int count;

	string tinyUrlPrefix = "http://tinyurl.com/";

public:
	Solution() {
		count = 0;
	}

	~Solution() {
		mp.clear();
	}


    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
    	if( mp.find(longUrl) == mp.end() ) {
    		
    		string tinyUrlSuffix = to_string(count);
    		string tinyUrl = tinyUrlPrefix + tinyUrlSuffix;
    		
    		mp[longUrl] = tinyUrl;
    		reverse_mp[tinyUrl] = longUrl;

			count++;

    		return tinyUrl;
    	}

        return mp[longUrl];
    

    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return reverse_mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int int main(int argc, char const *argv[])
{
	/* code */

	return 0;
}
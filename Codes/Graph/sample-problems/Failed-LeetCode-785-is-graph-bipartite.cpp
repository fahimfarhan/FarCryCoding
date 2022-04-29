// LeetCode-785-is-graph-bipartite.cpp

#include <bits/stdc++.h>
using namespace std;

#define BLUE 1
#define RED 2
#define GREEN 0


class Solution {
private:
	int *color;

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int N = graph.size();
        color = new int[N+1];
        memset(color, GREEN, sizeof(color));

        bool isBip = true;
        for(int i=0; i<N; i++) {
        	if(color[i] == GREEN) {
        		// color[i] = BLUE;
        		dfs(graph, i, BLUE);
        	}
        }

        bool* isBfsVisited = new bool[N+1];
        memset(isBfsVisited, false, sizeof(isBfsVisited));

        for(int i=0; i<N; i++) {
        	if(!isBfsVisited[i]) {
        		bool b = bfs(graph,color, isBfsVisited, i);
        		if(b == false) {
        			isBip = false;
        			break;
        		}
        	}
        }        

        delete[] color;
        return isBip;
    }

    bool bfs(vector<vector<int>>& graph, int* color, bool* isBfsVisited, const int& u) {
		bool result = true;
    	queue<pair<int, int> > q;

    	q.push({u, color[u]});
    	isBfsVisited[u] = true;

    	while(!q.empty()) {
    		auto front = q.front();
    		q.pop();

    		int v = front.first;
    		int c = front.second;

    		for(int i=0; i<graph[v].size(); i++) {
    			int w = graph[v][i];
    			if(c == color[w]) {
    				result = false;
    				return result;
    			}
    			if(!isBfsVisited[w]) {
    				q.push({w, color[w]});
    			}

    		}
    	}
    	return result;
    }

    void dfs(vector<vector<int>>& graph, const int& u, const int& c) {
    	color[u] = c;
    	bool ret = true;
    	int oppositeColor = BLUE;

    	if(c == BLUE) {	oppositeColor = RED;	}

    	for(int i=0; i<graph[u].size(); i++) {
    		int v = graph[u][i];
    		if(color[v] == GREEN)
	    		dfs(graph, v, oppositeColor);
    	}
    }
};

int main() {

	return 0;
}
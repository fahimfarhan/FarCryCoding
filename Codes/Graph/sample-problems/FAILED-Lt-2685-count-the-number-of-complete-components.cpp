#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // create a graph from the edges
        vector<vector<int>> graph(n);
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // create a visited array
        vector<bool> visited(n, false);

        // create dfs function
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {

                int nodeCount = 0;
                int egdeCountTimesTwo = 0;

                dfs(graph, visited, i, nodeCount, egdeCountTimesTwo);
                cout << "nodeCount: " << nodeCount << " egdeCount: " << egdeCountTimesTwo << endl;
                if(egdeCountTimesTwo == nodeCount * (nodeCount - 1)) {
                    count++;
                }
            }
        }
        return count;
    }

private:
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int node, int& nodeCount, int& egdeCount) {
        visited[node] = true;
        nodeCount++;
        egdeCount += graph[node].size();
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                // egdeCount++;
                dfs(graph, visited, neighbor, nodeCount, egdeCount);
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    // create edges vector. input: [[0,1],[0,2],[1,2],[3,4],[3,5]]
    vector<vector<int>> edges = {{0,1},{0,2},{1,2},{3,4},{3,5}};
    // create object of Solution class
    Solution obj;
    // call the function and print the result
    cout << obj.countCompleteComponents(6, edges) << endl;

    // create egdes vector. input: [[0,1],[0,2],[1,2],[3,4]]
    vector<vector<int>> edges1 = {{0,1},{0,2},{1,2},{3,4}};
    // call the function and print the result
    cout << obj.countCompleteComponents(5, edges1) << endl;
    return 0;
}

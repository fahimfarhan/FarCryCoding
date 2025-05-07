#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
      int minTimeToReach(
        vector<vector<int>>& moveTime
    ) {
        // 1 dfs?
        // 2 total cost in current path?
        // 3 minimus = min(minimus, current path cost)

        int N = moveTime.size();
        int M = moveTime[0].size();

        cout <<"Size = " << N << " "<<M <<"\n";


        vector<vector<bool>> isVisited(N, std::vector<bool>(M, false));

        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                cout << moveTime[i][j] << " ";
            } cout << "\n";
        }

        int minimus = dfs(0, 0, 0, moveTime, isVisited, N, M);

        return minimus;
      }

  private:
      int x[4] = {+1, -1, 0, 0};
      int y[4] = {0, 0, +1, -1};

      bool isSafe(
        int N, 
        int M, 
        int u, 
        int v
    ) {
        if(u < 0) return false;
        if(v < 0) return false;

        if(N <= u) return false;
        if(M <= v) return false;
        
        return true;
    }


      int dfs(
        int u, 
        int v, 
        int currentTime,
        vector<vector<int>>& g,
        vector<vector<bool>>& isVisited,
        int N,
        int M
    ) {
        if(!isSafe(N, M, u, v)) return INT_MAX;
        if(isVisited[u][v]) return INT_MAX;

        isVisited[u][v] = true;

        if(
            ( u == (N-1) ) &&
            ( v == (M-1) )
        ) {
            cout << "reached destination, returning "<< currentTime <<"\n";
            if(g[u][v] < currentTime) {
                return currentTime;
            } else {
                return g[u][v];
            }

        }

        // we're at u, v
        int nextTime = 0;
        if(g[u][v] < currentTime) {
            nextTime = currentTime + 1;
        } else {
            nextTime = g[u][v] + 1;  // todo: watch out!
        }
        cout<<"(u "<<u<<" , v "<<v<<") Next time = "<<nextTime<<"\n";

        int minimus = INT_MAX;
        for(int i=0; i<4; i++) {
                int tmp = dfs(u+x[i], v+y[i], nextTime, g, isVisited, N, M);
                minimus = min(minimus, tmp);
            
        }
        isVisited[u][v] = false; // I think we need this
        return minimus;
    }
};

int main() {
    Solution s = Solution();
    vector<vector<int>> v = {{0,4},
                             {4, 4}};
    int minimus = s.minTimeToReach(v);
    cout<< "Test Case #1 " << minimus <<"\n";
    return 0;
}

/**
 * 
 * https://leetcode.com/problems/ones-and-zeroes/discuss/2066479/C%2B%2B-oror-Recursive-(memoization)-oror-explained
 * 
 * 
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
      return 0;
    }
};

class SolutionV2Failed {
private:
  vector<pair<int, int> > counts;
  set<int> setOfIdx;

  void preprocess(vector<string>& strs) {
    setOfIdx.clear();
    counts.clear();
    int N = strs.size();

    for(int i=0; i<N; i++) {
      string str = strs[i];
      int ones = 0, zeroes = 0;

      int M = str.size();
      for(int j=0; j<M; j++) {
        if(str[j] == '1') {   ones++;  }
        else {  zeroes++;   }
      }
      counts.push_back({zeroes, ones});
    }
  }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        preprocess(strs);
        int idx = strs.size() - 1;
        int res = knapSackRecursion(idx, m, n);
        for(auto i : setOfIdx) {
          cout<<"inside setOfIdx = "<<i<<"\n";
        }
        return setOfIdx.size(); // res;
    }

    int knapSackRecursion(int& idx, int& zeroes, int& ones) {
      int result = 0;

      // if(idx == -1 || ( (zeroes <=0) && (ones <=0)) ) {
      //   return 0;
      // }

      if(idx < 0) {
        // cerr<<"return from case 1\n";
        return 0;
      }

      if(zeroes < 0) {
        // cerr<<"return from case 2\n";
        return 0;
      }
      if(ones < 0) {
        // cerr<<"return from case 3\n";
        return 0;
      }



      int taken = INT_MIN;
      int o = counts[idx].first;
      int z = counts[idx].second;
       
      int idx_1 = idx - 1;
      if( (ones >= o) && (zeroes >= z) ) {
 
        int zeroes_z = zeroes - z;
        int ones_o = ones - o;
        taken = 1 + knapSackRecursion( idx_1, zeroes_z, ones_o );
      }
      int notTaken = knapSackRecursion( idx_1, zeroes, ones);

      if(taken > notTaken) {
        result = taken;
        // cout<<"taken index = "<<idx<<" , result = "<<result<<"\n";
        setOfIdx.insert(idx);
      } else {
        result = notTaken;
      }
      
      return result;
    }
};

class SolutionV1Failed {
private:
  vector<pair<int, int> > numPairs;

  void preprocess(const vector<string>& strs, const int& m /* remaining zeroes*/, const int& n/* remaining ones*/) {
    numPairs.clear();

    for(auto str : strs) {
      int N = str.size();
      int one = 0, zero = 0;
      for(int i=0; i<N; i++) {
        if(str[i] == '1') {
          one++;
        } else {
          zero++;
        }
        numPairs.push_back({zero, one});
      }
    }
  }

  int knapSackRecursionV2(int idx, int remainingZeroes, int remainingOnes) {
    if(idx == -1 || ( (remainingZeroes <= 0) || (remainingOnes <= 0))) {   // eita bujhi ni
      return 0;
    }

    int taken = INT_MIN;

    int z = numPairs[idx].first;
    int o = numPairs[idx].second;

    if( (remainingZeroes >= z) && (remainingOnes >= o) ) {
      taken = 1 + knapSackRecursionV2( (idx-1), (remainingZeroes - z), (remainingOnes - o));
    }
    int notTaken = knapSackRecursionV2(idx-1, remainingZeroes, remainingOnes);

    int maximus = max(taken, notTaken);
    return maximus;
  }

  int knapSackRecursion(int idx, int remainingZeroes, int remainingOnes) {
    // either strs[idx] is added, or not
    //                                        strs[idx]
    //              added                                                 not added
    // 1 + f(idx+1, rZ - np[idx].f, rO - np[idx].s)                   f(idx+1, rZ, rO)

    // base cases:
    if(idx < 0 || remainingZeroes < 0 || remainingOnes < 0) {
      return 0;
    }
    if( (remainingOnes == 0) && (remainingZeroes == 0) ) {
      return 0;
    }

    if( (remainingZeroes - numPairs[idx].first < 0) || (remainingOnes - numPairs[idx].second < 0) ) {
      return knapSackRecursion(idx-1, remainingZeroes, remainingOnes);
    }

    int v1 = 1 + knapSackRecursion(idx-1, remainingZeroes-numPairs[idx].first, remainingOnes - numPairs[idx].second);
    int v2 = knapSackRecursion(idx-1, remainingZeroes, remainingOnes);

    return max(v1, v2);
  }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
      preprocess(strs, m, n);
      return knapSackRecursionV2(strs.size() - 1, m, n);
    }
};

int main() {
  /*
test cases

["10","0001","111001","1","0"]
5
3
["10","0","1"]
1
1
["10","0001","111001","1","0"]
4
3

Expected:
4
2
3

Output:
4
2
4


  */
  SolutionV2Failed s;
  vector<string> v1 = {"10","0001","111001","1","0"};
  cout<<s.findMaxForm(v1, 5, 3)<<"\n";

  vector<string> v2 = {"10","0","1"};
  cout<<s.findMaxForm(v2, 1, 1)<<"\n";

  vector<string> v3 = {"10","0001","111001","1","0"};
  cout<<s.findMaxForm(v3, 4, 3)<<"\n";

  return 0;
}
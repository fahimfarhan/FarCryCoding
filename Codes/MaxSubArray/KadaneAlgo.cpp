#include <bits/stdc++.h>

using namespace std;

int kadaneAlgorithm(vector<int>& input) {
	int N = input.size();
	int localMaxima = 0;
	int globalMaxima = INT_MIN;

	for(int i=0; i<N; i++) {
		localMaxima = max(input[i], input[i]+localMaxima);
		if(localMaxima > globalMaxima) {
			globalMaxima = localMaxima;
		}
	}

	return globalMaxima;
}

int kadaneAlgorithmFailed(vector<int>& input) {
	int N = input.size();
	int maximumSubArraySum = 0;
	int *dp = new int[N+1];
	
	for(int i=0; i<N; i++) {
		dp[i] = 0;
	}

	dp[0] = input[0];

	for(int i=1; i<N; i++) {
		dp[i] = max(input[i], (input[i] + dp[i-1])); 
	}
	maximumSubArraySum = dp[N-1];
	delete[] dp;

	return maximumSubArraySum;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	vector<int> input = {-2,1,-3,4,-1,2,1,-5,4};

	int outputMaximumSubArraySum = kadaneAlgorithm(input);
	cout<<outputMaximumSubArraySum<<"\n";


	return 0;
}

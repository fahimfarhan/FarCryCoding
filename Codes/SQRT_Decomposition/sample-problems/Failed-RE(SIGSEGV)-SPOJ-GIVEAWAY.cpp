#include <bits/stdc++.h>
using namespace std;

#define ll long long int
ll SQRT = 4096;  // perhaps in some cases, it is better to estimate the upper bounds using the given constraints, and using those values.

ll *x = nullptr;
vector<ll> *block = nullptr;

inline void pre_process(const int& N) {
	SQRT = sqrt(N)+10;
	int blockSize = N/SQRT + 1;

	block = new vector<ll>[blockSize+10];

	int j = 0; int k = 0;
	for(int i=0; i<N; i++) {
		block[j].push_back(x[i]);

		k++;
		if(k == SQRT) {
			k = 0; 
			j++;
		}
	}

	for(int i=0; i<blockSize+1; i++) {
		sort(block[i].begin(), block[i].end());
	}
}

ll query(const ll& l, const ll& r, const ll& c) {
	ll queryResult = 0;

	int lb = l/SQRT;
	int rb = r/SQRT;

	if(lb == rb) {
		for(int i=l; i<=r; i++) {
			if(x[i] >= c) {
				queryResult++;
			}
		}
	} else {
		int q1=0, q2=0, q3=0;
		int leftEndExclusive = (lb+1)*SQRT;
		int middleStartInclusive = leftEndExclusive;

		int middleEndExclusive = rb*SQRT;
		int rightStartInclusive = middleEndExclusive;

		for(int i=l; i<leftEndExclusive; i++) {
			if(x[i] >= c) {
				q1++;
			}
		}
	
		for(int i=middleStartInclusive; i<middleEndExclusive; i++) {
			auto it = lower_bound(block[i].begin(), block[i].end(), c);
			int pos = it - block[i].begin();

			int delta = block[i].size() - pos;
			q2 += delta;
		}

		for(int i=rightStartInclusive; i<=r; i++) {
			if(x[i] >= c) {
				q3++;
			}
		}
		queryResult = q1+q2+q3;
	}
	return queryResult;
}

void update(const ll& pos, const ll& b) {
	ll oldVal = x[pos];
	x[pos] = b;
	int idx = pos / SQRT;

	auto it = find(block[idx].begin(), block[idx].end(), oldVal);
	int position = it - block[idx].begin();

	block[idx][position] = b;

	if(b > oldVal) {
		int someBlockSize = block[idx].size();
		for(int i=position; i <someBlockSize - 1; i++) {
			if(block[idx][i] > block[idx][i+1]) {
				swap(block[idx][i], block[idx][i+1]);
			} else {
				break;
			}
		}
	} else {
		for(int i=position; i > 0; i--) {
			if(block[idx][i-1] > block[idx][i]) {
				swap(block[idx][i-1], block[idx][i]);
			} else {
				break;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, Q;
	cin>>N;
	x = new ll[N+10];

	for(int i=0; i<N; i++) {
		cin>>x[i];
	}

	pre_process(N);

	cin>>Q;

	int m;
	ll a, b, c;

	while(Q--) {
		cin>>m;
		if(m == 0) {
			cin>>a>>b>>c;
			// todo: query
			ll q = query(a, b, c);
			cout<<q<<"\n";
		} else {
			cin>>a>>b;
			// todo: update
			update(a, b);
		}
	}
	delete[] x;
	delete[] block;
	return 0;
}
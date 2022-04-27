// UVA-12003-Array-Transformation.cpp
/**
 * @Bref: Thanks to https://vjudge.net/solution/9037322 . I corrected my errors by reading this code.
 * */
#include <bits/stdc++.h>
using namespace std;

#define SQRT 4096 // 2^12
#define RSHFT 12

#define ll long

int N;
ll *A;
vector<ll> *block;

inline void pre_process() {
	int quotient = N / SQRT + 1;
	block = new vector<ll>[quotient+1];

	int j = 0;
	int k = 0;
	for(int i=0; i<N; i++) {
		block[j].push_back(A[i]);
		k++;
		if(k == N) {
			k = 0;
			j++;
		}
	}

	for(int i=0; i<quotient; i++) {
		sort(block[i].begin(), block[i].end());
	}
}

inline ll query(const ll& l0, const ll& r0, const ll& v) {
	ll k = 0;

	int lb = l0/SQRT;  // <------------------
	int rb = r0/SQRT;  // <------------------

	if(lb == rb) {

		for(int i=l0; i<=r0; i++) {
			if(A[i] < v) {
				k++;
			}
		}

	//	cerr<<"case1: "<<k<<"\n";
	} else {
		// step 1: count in left
		ll leftEndExclusive = (lb+1) * SQRT;  // <---------------------------

		ll k1 = 0;
		for(int i=l0; i<leftEndExclusive; i++) {
			if(A[i] < v) {
				k1++;
			}
		}
		
		// step 2: count in middle
		ll k2 = 0;
		for(int i=lb+1; i<rb; i++) {
			auto it = lower_bound(block[i].begin(), block[i].end(), v);
			k2 += (it - block[i].begin());		
		}

		// step 3: count in right
		ll k3 = 0;
		ll rightStartInclusive = rb * SQRT;

		for(int i=rightStartInclusive; i<=r0; i++) {
			if( A[i] < v ) {
				k3++;
			}
		}

		k = k1 + k2 + k3;
	//			cerr<<"case2: "<<k<<"\n";
	}
	return k;
}

void update(const ll& p0, const ll& value) {
	//cerr<<"debug: updateValue = "<<value<<"\n";
	if(value == A[p0]) return;

	// update A[p0]
	ll oldAp0 = A[p0];


	A[p0] = value;
	// update block[i]
	int blockIdx = (p0>>RSHFT) + 1; // p0/SQRT + 1;

	auto it = find(block[blockIdx].begin(), block[blockIdx].end(), oldAp0);
	int pos = it - block[blockIdx].begin();

	if(oldAp0 < value) {
		int size1 = block[blockIdx].size();

		for(int i=pos; i<size1 - 1; i++) {
			if(A[i+1] > A[i]) {	break; }
			swap(A[i], A[i+1]);
		}
	} else {
		for(int i=pos; i>0; i--) {
			if(A[i-1] < A[i]) { break;	}
			swap(A[i-1], A[i]);
		}
	}
}

void queryAndUpdate(const ll& l0, const ll& r0, const ll& v, const ll& p0, const ll& u) {
	ll k = query(l0, r0, v);
	//cerr<<"debug "<<u<<" "<<k<<" "<<r0<<" "<<l0<<"\n"; 
	ll value = u * k / (r0 - l0 + 1);
	//cerr<<"debug value0 "<<value<<"\n";
	update(p0, value);
}

inline void destructor() {
	delete[] A;
	delete[] block;
}


int main(int argc, char const *argv[]) {
	/* code */
	ll M, U;

	cin>>N>>M>>U;
	A = new ll[N+1];
	
	for(int i=0; i<N; i++) {
		cin>>A[i];
	}

	// todo: preprocess
	pre_process();

	ll L, R, V, P;
	for(int i=0; i<M; i++) {
		cin>>L>>R>>V>>P;
		// s1 
		// convert into 0 based indexing
		
		L--;
		R--;
		P--;

		// s2 
		// todo: query, and update
		queryAndUpdate(L, R, V, P, U);
	}

	for(int i=0; i<N; i++) {
		cout<<A[i]<<"\n";
	}

	destructor();

	return 0;
}
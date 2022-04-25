// UVA-12003-Array-Transformation.cpp
#include <bits/stdc++.h>
using namespace std;

#define SQRT 4000


int N, M, U, quotient;	
int *a;
vector<int> *b;


void sortBlock(int k) {
	sort(b[k].begin(), b[k].end());
}


inline void pre_process() {
	quotient = N / SQRT + 1;
	b = new vector<int>[quotient];
	

	int j=0, k=0;
	for(int i=0; i<N; i++) {
		if(j == SQRT) {
			j = 0;
			sortBlock(k);
			k++;
		}
		// b[k][j] = a[i];
		b[k].push_back(a[i]);		
	}
	sortBlock(k);
}

int query(const int& l,const int& r,const int& v) {
	int k = 0;

	int lb = l/SQRT + 1;
	int rb = r/SQRT;

	if(lb == rb) {
		for(int i=l; i<=r; i++) {
			if(a[i] < v) k++;
		}
	} else {

		for(int i=l; i<lb*SQRT; i++) {
			if(a[i] < v) k++;
		}

		for(int i=lb; i<rb; i++) {
			auto it = lower_bound(b[i].begin(), b[i].end(), v);
			k += (it - b[i].begin());			
		}

		for(int i=rb*SQRT; i<=r; i++) {
			if(a[i] < v) k++;	
		}
	}
	return k;
}

void update(const int& p, const int& x) {  // (const int& l,const int& r,const int& p, const int& k) {
	if(a[p] == x) {	return;	}
	int oldAp = a[p];
	a[p] = x; // u*k / (r - l + 1);

	int k = p/SQRT;

	auto it = find(b[k].begin(), b[k].end(), oldAp);
	int pos = it - b[k].begin();

	b[k][pos] = x;
	if(x > oldAp) {
		for(int i=pos; i < b[k].size() - 1; i++) {
			swap(b[k][i], b[k][i+1]);
		}
	} else {
		for(int i=pos; i > 0; i--) {
			swap(b[k][i], b[k][i-1]);
		}
	}
}


inline void printer() {
	for(int i=0; i<N; i++) {
		cout<<a[i]<<"\n";
	}
}

inline void destructor() {
	delete[] a;
	delete[] b;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);


	cin>>N>>M>>U;

	a = new int[N+1];
	for(int i=0; i<N; i++) {
		cin>>a[i];
	}

	pre_process();

	int L, R, v, p;

	while(M--) {
		cin>>L>>R>>v>>p;
		cerr<<L<<" "<<R<<" "<<v<<" "<<p<<"\n";
		int k = query(L, R, v);
		cerr<<"k = "<<k<<"\n";
		int x = U*k / (R - L + 1);
		cerr<<"x = "<<x<<"\n";
		update(p, x);
		printer();
	}

	destructor();	
	return 0;
}
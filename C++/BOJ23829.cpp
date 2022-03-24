#include <bits/stdc++.h>
#define MINF 0x7f7f7f7f
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll N, Q, psum[100010];
vector<ll> v;

void init() {
	memset(psum, 0, sizeof(psum));
	cin >> N >> Q;
	for(int i=1; i<=N; i++) {
		ll x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	for(int i=1; i<=N+1; i++) {
		psum[i] = v[i-1];
		psum[i] += psum[i-1];
	}
	for(int i=0; i<Q; i++) {
		ll x, result = 0;
		cin >> x;
		ll idx = lower_bound(v.begin(), v.end(), x) - v.begin();
		result += ((idx * x) - psum[idx]);
		result += ((psum[N+1] - psum[idx]) - (N-idx)*x);
		cout << result << '\n';
	}
}


int main() {    
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}

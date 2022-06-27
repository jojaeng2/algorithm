#include <bits/stdc++.h>
#define X first
#define Y second
#define NUM 100010
#define INF 1e9
#define MOD 1000000007
#define LOG 22
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<int, ll> pil;
typedef pair<pii, int> piii;
typedef pair<piii, int> piiii;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> plll;
int n, m;
vector<int> tree[4*NUM+10];

void update(int s, int e, int node, int idx, int num) {
	if(s > idx || e < idx) return;
	tree[node].push_back(num);
	if(s == e) return;
	int mid = (s+e)/2;
	update(s, mid, node*2, idx, num);
	update(mid+1, e, node*2+1, idx, num);
}

int sum(int s, int e, int node, int l, int r, int num) {
	if(s > r || e < l) return 0;
	int psum = 0;
	if(l <= s && e <= r) {
		int idx = upper_bound(tree[node].begin(), tree[node].end(), num) - tree[node].begin();
		psum += idx;
		return psum;

	}
	int mid = (s+e)/2;
	psum += sum(s, mid, node*2, l, r, num) + sum(mid+1, e, node*2+1, l, r, num);
	return psum;
}

void init() {
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		int x;
		cin >> x;
		update(1, n, 1, i, x);
	}
	for(int i=0; i<=4*NUM; i++) sort(tree[i].begin(), tree[i].end());
	while(m--) {
		int s, e, k, l = -INF, r = INF, answer;
		cin >> s >> e >> k;
		while(l <= r) {
			int mid = (l+r)/2;
			int cnt = sum(1, n, 1, s, e, mid);
			if(cnt >= k) {
				answer = mid;
				r = mid-1;
			}
			else l = mid+1;
		}
		cout << answer << '\n';
	}

}		

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
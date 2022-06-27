#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <cmath>
#include <deque>
#include <list>
#define X first
#define Y second
#define NUM 500010
#define INF 2000000000
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
ll num[NUM], tree[4*NUM], lazy[4*NUM];

ll init_tree(int s, int e, int node) {
	if(s == e) return tree[node] = num[s];
	int mid = (s+e)/2;
	return tree[node] = (init_tree(s, mid, node*2) ^ init_tree(mid+1, e, node*2+1));
}

void propagation(int s, int e, int node) {
	if(lazy[node] != 0) {
		tree[node] ^= lazy[node];
		if(s != e) {
			lazy[node*2] ^= lazy[node];
			lazy[node*2+1] ^= lazy[node];
		}
		lazy[node] = 0;
	}
}

ll sum(int s, int e, int node, int idx) {
	propagation(s, e, node);
	if(idx < s || e < idx) return 0;
	if(s == e) return tree[node];
	int mid = (s+e)/2;
	return sum(s, mid, node*2, idx) ^ sum(mid+1, e, node*2+1, idx);
}

void update(int s, int e, int node, int l, int r, int diff) {
	propagation(s, e, node);
	if(s > r || e < l) return;
	if(l <= s && e <= r) {
		tree[node] ^= diff;
		if(s != e) {
			lazy[node*2] ^= diff;
			lazy[node*2+1] ^= diff;
		}
		return;
	}
	int mid = (s+e)/2;
	update(s, mid, node*2, l, r, diff);
	update(mid+1, e, node*2+1, l, r, diff);
}

void init() {
	memset(num, 0, sizeof(num));
	memset(tree, 0, sizeof(tree));
	memset(lazy, 0, sizeof(lazy));
	cin >> n;
	for(int i=1; i<=n; i++) cin >> num[i];
	init_tree(1, n, 1);
	cin >> m;
	while(m--) {
		int x, y, z, d;
		cin >> x;
		if(x == 1) {
			cin >> y >> z >> d;
			y++, z++;
			update(1, n, 1, y, z, d);
		}
		else {
			cin >> y;
			y++;
			cout << sum(1, n, 1, y) << '\n';
		}
	}

}		

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
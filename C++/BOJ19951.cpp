#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <bitset>
#include <set>
#include <map>
#define X first
#define Y second
#define NUM 100010
#define MOD 1000000007
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int n, m;
ll num[NUM], tree[4*NUM], lazy[4*NUM];


ll init_tree(int s, int e, int node) {
	if(s == e) return tree[node] = num[s];
	int mid = (s+e)/2;
	return tree[node] = (init_tree(s, mid, node*2) + init_tree(mid+1, e, node*2+1));
}

void update(int s, int e, int node, int l, int r, int diff) {
	if(lazy[node] != 0) {
		tree[node] += lazy[node]*(e-s+1);
		if(s != e) {
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(s > r || e < l) return;
	if(l<=s && e<=r) {
		tree[node] += (e-s+1)*diff;
		if(s != e) {
			lazy[node*2] += diff;
			lazy[node*2+1] += diff;
		}	
		return;
	}

	int mid = (s+e)/2;
	update(s, mid, node*2, l, r, diff);
	update(mid+1, e, node*2+1, l, r, diff);
}

ll sum(int s, int e, int node, int idx) {
	if(lazy[node] != 0) {
		tree[node] += lazy[node]*(e-s+1);
		if(s!=e) {
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(s>idx || e<idx) return 0;
	if(s == e) return tree[node];
	int mid = (s+e)/2;
	return sum(s, mid, node*2, idx) + sum(mid+1, e, node*2+1, idx);
}

void init() {
	memset(num, 0,  sizeof(num));
	memset(tree, 0, sizeof(tree));
	memset(lazy, 0, sizeof(lazy));
	cin >> n >> m;
	for(int i=1; i<=n; i++) cin >> num[i];
	init_tree(1, n, 1);
	for(int i=0; i<m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		update(1, n, 1, x, y, z);
	}
	for(int i=1; i<=n; i++) {
		cout << sum(1, n, 1, i) << ' ';
	}
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}

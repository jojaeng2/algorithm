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
#define X first
#define Y second
#define NUM 100010
#define INF 1e15
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, int> pli;
int n, tree[4*NUM], lazy[4*NUM];

int sum(int s, int e, int node, int idx) {
	if(lazy[node] != 0) {
		tree[node] += lazy[node];
		if(s != e) {
			lazy[node * 2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(s > idx || e < idx) return 0;
	if(s == e) {
		int num = tree[node];
		tree[node] = 0;
		return num;
	}
	int mid = (s+e)/2;
	return sum(s, mid, node*2, idx) + sum(mid+1, e, node*2+1, idx);
}

void update(int s, int e, int node, int l, int r) {
	if(lazy[node] != 0) {
		tree[node] += lazy[node];
		if(s != e) {
			lazy[node * 2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(s > r || l > e) return;
	if(l<=s && e<=r) {
		tree[node] += 1;
		if(s != e) {
			lazy[node*2] += 1;
			lazy[node*2+1] += 1;
		}
		return;
	}
	int mid = (s+e)/2;
	update(s, mid, node*2, l, r);
	update(mid+1, e, node*2+1, l, r);
}

void init() {
	memset(tree, 0, sizeof(tree));
	memset(lazy, 0, sizeof(lazy));
	cin >> n;
	for(int i=0; i<n; i++) {
		int x, y;
		cin >> x >> y;
		cout << sum(1, NUM-10, 1, x) + sum(1, NUM-10, 1, y) << '\n';
		if(x+1 == y) continue;
		update(1, NUM-10, 1, x+1, y-1);
	}
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
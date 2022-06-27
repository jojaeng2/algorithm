#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stack>
#define X first
#define Y second
#define NUM 1000010
#define INF 1e9
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii,int> piii;
typedef long long ll;
int n, m;
ll tree[4*NUM];

void update(int s, int e, int node, int idx, int diff) {
	if(s > idx || e < idx) return;
	tree[node] += (ll)diff;
	if(s == e) return;
	int mid = (s+e)/2;
	update(s, mid, node*2, idx, diff);
	update(mid+1, e, node*2+1, idx, diff);
}

ll sum(int s, int e, int node, int l, int r) {
	if(s>r || e<l) return 0;
	if(l<=s && e<=r) return tree[node];
	int mid = (s+e)/2;
	return sum(s, mid, node*2, l, r) + sum(mid+1, e, node*2+1, l, r);
}

void init() {
	memset(tree, 0, sizeof(tree));
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		if(x == 1) update(1, n, 1, y, z);
		else cout << sum(1, n, 1, y, z) << '\n';
	}
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
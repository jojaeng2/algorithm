#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define X first
#define Y second
#define NUM 200010
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
ll maxtree[NUM*4], psum[NUM], mintree[4*NUM], in[NUM];
int n, m;
vector<int> v;

ll min_idx(int s, int e, int node) {
	if(s == e) return mintree[node] = in[s];
	int mid = (s+e)/2;
	return mintree[node] = min(min_idx(s, mid, node*2), min_idx(mid+1, e, node*2+1));
}

ll max_idx(int s, int e, int node) {
	if(s == e) return maxtree[node] = in[s];
	int mid = (s+e)/2;
	return maxtree[node] = max(max_idx(s, mid, node*2), max_idx(mid+1, e, node*2+1));
}

ll min_update(int s, int e, int node, int idx, int now) { 
	if(s>idx || e<idx) return mintree[node];
	mintree[node] = 987654321;
	if(s == e) return mintree[node] = now;	
	int mid = (s+e)/2;
	return mintree[node] = min(min_update(s, mid, node*2, idx, now), min_update(mid+1, e, node*2+1, idx, now));
}

ll max_update(int s, int e, int node, int idx, int now) { 
	if(s>idx || e<idx) return maxtree[node];
	maxtree[node] = 0;
	if(s == e) return maxtree[node] = now;	
	int mid = (s+e)/2;
	return maxtree[node] = max(max_update(s, mid, node*2, idx, now), max_update(mid+1, e, node*2+1, idx, now));
}

ll find_min(int s, int e, int node, int l, int r) {
	if(s>r || e<l) return 987654321;
	if(l<=s && e<=r) return mintree[node];
	int mid = (s+e)/2;
	return min(find_min(s, mid, node*2, l, r), find_min(mid+1, e, node*2+1, l, r));
}

ll find_max(int s, int e, int node, int l, int r) {
	if(s>r || e<l) return 0;
	if(l<=s && e<=r) return maxtree[node];
	int mid = (s+e)/2;
	return max(find_max(s, mid, node*2, l, r), find_max(mid+1, e, node*2+1, l, r));
}


void init() {
	memset(maxtree, 0, sizeof(maxtree));
	memset(psum, 0, sizeof(psum));
	memset(mintree, 1e4, sizeof(mintree));
	memset(in, 0, sizeof(in));
	cin >> n >> m;
	v.push_back(-1);
	for(int i=1; i<=n; i++) {
		int x;
		cin >> x;
		in[x] = i;
		v.push_back(x);
	}
	min_idx(1, n, 1);
	max_idx(1, n, 1);
	for(int i=1; i<=m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		if(x == 1) {
			int a = v[y], b = v[z];
			min_update(1, n, 1, a, in[b]);
			min_update(1, n, 1, b, in[a]);
			max_update(1, n, 1, a, in[b]);
			max_update(1, n, 1, b, in[a]);
			ll temp = in[a];
			in[a] = in[b], in[b] = temp;
			swap(v[y], v[z]);
		}
		else {
			int idx = find_min(1, n, 1, y, z);
			int idx2 = find_max(1, n, 1, y, z);
			if((idx2-idx) == (z-y)) cout << "YES" << '\n';
			else cout << "NO" << '\n';
		}
	}
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}

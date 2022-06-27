#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define NUM 2000010
#define X first
#define Y second
using namespace std;
int n, m;
typedef long long ll;
typedef pair<pair<int, int>, int> piii;
ll num[NUM], tree[4*NUM];
vector<int> v, in;
vector<piii> query;

int sum(int s, int e, int node, int l, int r) {
	if(s>r || e<l) return 0;
	if(l<=s && e<=r) return tree[node];
	int mid = (s+e)/2;
	return sum(s, mid, node*2, l, r) + sum(mid+1, e, node*2+1, l, r);
}

void update(int s, int e, int node, int idx) {
	if(s>idx || idx>e) return;
	tree[node]++;
	if(s == e) return;
	int mid = (s+e)/2;
	update(s, mid, node*2, idx);
	update(mid+1, e, node*2+1, idx);
}

ll init_tree(int s, int e, int node) {
	if(s == e) return tree[node] = num[s];
	int mid = (s+e)/2;
	return tree[node] = init_tree(s, mid, node*2) + init_tree(mid+1, e, node*2+1);
}

void init() {
	memset(num, 0, sizeof(num));
	memset(tree, 0, sizeof(tree));
	cin >> n;
	for(int i=0; i<n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
		in.push_back(x);
	}
	cin >> m;
	for(int i=0; i<m; i++) {
		int x, y, z;
		cin >> x;
		if(x == 1) {
			cin >> y;
			query.push_back({{1, y}, 0});
			v.push_back(y);
		}
		else {
			cin >> y >> z;
			query.push_back({{2, y}, z});
		}
	}
	v.push_back(-1000000010);
	sort(v.begin(), v.end());
	for(int i=0; i<in.size(); i++) {
		int idx = lower_bound(v.begin(), v.end(), in[i]) - v.begin();
		num[idx] = 1;
	}
	init_tree(1, v.size(), 1);
	for(int i=0; i<query.size(); i++) {
		int x = query[i].X.X, y = query[i].X.Y, z = query[i].Y;
		if(x == 1) {
			int idx = lower_bound(v.begin(), v.end(), y) - v.begin();
			update(1, v.size(), 1, idx);
		}
		else {
			int l = lower_bound(v.begin(), v.end(), y) - v.begin();
			int r = upper_bound(v.begin(), v.end(), z) - v.begin();
			cout << z-y+1 - sum(1, v.size(), 1, l, r-1) << '\n';
		}
	}
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
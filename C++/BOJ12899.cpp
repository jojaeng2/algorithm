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
#define NUM 2000010
#define INF 1000000000
#define MOD 998244353
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, int> pli;
int N;
ll num[NUM], tree[4*NUM];

void update(int s, int e, int node, int idx, int diff) {
	if(s > idx || e < idx) return;
	tree[node] += (ll)diff;
	if(s == e) return;
	int mid = (s+e)/2;
	update(s, mid, node*2, idx, diff);
	update(mid+1, e, node*2+1, idx, diff);
}

int query(int s, int e, int node, int X) {
	if(s == e) return s;
	int mid = (s+e)/2;
	if(X <= tree[node*2]) return query(s, mid, node*2, X);
	else return query(mid+1, e, node*2+1, X-tree[node*2]);
}


void init() {
	memset(num, 0, sizeof(num));
	memset(tree, 0, sizeof(tree));
	cin >> N;
	while(N--) {
		int x, y;
		cin >> x >> y;
		if(x == 1) update(1, NUM-10, 1, y, 1);
		else {
			int idx = query(1, NUM-10, 1, y);
			update(1, NUM-10, 1, idx, -1);
			cout << idx << '\n';
		}
	}
}	

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
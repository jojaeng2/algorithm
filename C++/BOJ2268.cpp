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
#define NUM 1000010
#define INF 1000000000
#define MOD 1000000007
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, int> pli;
using namespace std;
ll tree[4*NUM], num[NUM];
int N, M;

ll sum(int s, int e, int node, int l, int r) {
	if(s > r || e < l) return 0;
	if(l<=s && e<=r) return tree[node];
	int mid = (s+e)/2;
	return sum(s, mid, node*2, l, r) + sum(mid+1, e, node*2+1, l, r);
}

void update(int s, int e, int node, int idx, ll diff) {
	if(s > idx || e < idx) return;
	tree[node] -= num[idx];
	tree[node] += diff;
	if(s == e) return;
	int mid = (s+e)/2;
	update(s, mid, node*2, idx, diff);
	update(mid+1, e, node*2+1, idx, diff);
}

ll init(int start,int end,int node){
    if(start==end) return tree[node] = num[start];
    int mid = (start+end)/2;
    return tree[node] = init(start,mid,node*2) + init(mid+1,end,node*2+1);
}

void init() {
	memset(tree, 0, sizeof(tree));
	memset(num, 0, sizeof(num));
	cin >> N >> M;

    init(1,N,1);
	for(int i=0; i<M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		if(x == 0) {
			if(y > z) swap(y, z);
			cout << sum(1, N, 1, y, z) << '\n';
		}
		else {
			update(1, N, 1, y, (ll)z);
			num[y] = (ll)z;
		}
	}
}

int main(){
	init();
    
}
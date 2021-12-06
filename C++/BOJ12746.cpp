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
#define NUM 230000
#define INF 2000000000
#define MOD 1000000007
#define LOG 22
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
int n, q, par[LOG+10][NUM], depth[NUM], psum[NUM], dp[NUM], ss = INF, ee = INF, maxi = 0;
vector<int> adj[NUM];

void dfs(int s, int e) {
	for(int next : adj[s]) {
		if(next == e) continue;
		depth[next] = depth[s] + 1;
		par[0][next] = s;
		dfs(next, s);
	}
}

void sparse() {
	for(int i=1; i<=LOG; i++) {
		for(int j=1; j<=n; j++) {
			par[i][j] = par[i-1][par[i-1][j]];
		}
	}
}

int lca(int x, int y) {
	if(depth[x] < depth[y]) swap(x, y);
	for(int i=LOG; i>=0; i--) {
		if((depth[x] - depth[y]) >= (1 << i)) x = par[i][x];
	}
	if(x == y) return x;
	for(int i=LOG; i>=0; i--) {
		if(par[i][x] == par[i][y]) continue;
		x = par[i][x];
		y = par[i][y];
	}
	x = par[0][x], y = par[0][y];
	return x;
}

int dynamic(int s, int e) {
	dp[s] = psum[s];
	for(int next : adj[s]) {
		if(next == e) continue;
		dp[s] += dynamic(next, s);
	}
	if(dp[s] > maxi) {
		maxi = dp[s];
		ss = min(s, e), ee = max(s, e);
	}
	else if(dp[s] == maxi) {
		if(min(s, e) < ss) {
			ss = min(s, e), ee = max(s, e);
		}
		else if(min(s, e) == ss && max(s, e) < ee) {
			ss = min(s, e), ee = max(s, e);
		}
	}
	return dp[s];
}

void init() {
	memset(par, 0, sizeof(par));
	memset(psum, 0, sizeof(psum));
	memset(depth, 0, sizeof(depth));
	memset(dp, 0, sizeof(dp));
	cin >> n >> q;
	for(int i=1; i<n; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	par[0][1] = 0, depth[1] = 1;
	dfs(1, 0);
	sparse();
	for(int i=0; i<q; i++) {
		int x, y;
		cin >> x >> y;
		int root = lca(x, y);
		if(root == x) {
			psum[x]--;
			psum[y]++;
		}
		else if(root == y) {
			psum[y]--;
			psum[x]++;
		}
		else {
			psum[root] -= 2;
			psum[x]++;
			psum[y]++;
		}
	}
	dynamic(1, 0);
	cout << ss << " " << ee << " " << maxi << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
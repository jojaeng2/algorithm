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
#define NUM 100010
#define INF 2000000000
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
int n, m, k, s, e, dp[NUM];
bool visit[NUM] = {false};
ll answer = 0;
vector<int> adj[NUM];

int dfs(int curr) {
	dp[curr] = 1;
	for(int next : adj[curr]) {
		if(visit[next]) continue;
		if((curr == s && next == e) || (curr == e && next == s)) continue;
		visit[next] = true;
		dp[curr] += dfs(next);
	}
	return dp[curr];
}

void init() {
	memset(dp, 0, sizeof(dp));
	cin >> n >> m >> k;
	for(int i=1; i<=m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		if(i == k) s = x, e = y;
	}
	visit[s] = true;
	dfs(s);
	if(visit[e]) cout << answer << '\n';
	else {
		visit[e] = true;
		dfs(e);
		answer = (ll)dp[s] * (ll)dp[e];
		cout << answer << '\n';
	}
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
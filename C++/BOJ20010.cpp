#include <bits/stdc++.h>
#define X first
#define Y second
#define NUM 1000010
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
int n, m, par[1010], ans = 0, maxi = 0, vis[1010];
vector<pii> adj[1010];
vector<piii> v;

bool compare(piii a, piii b) {
	return a.Y < b.Y;
}

int find(int start) {
	if(start == par[start] ) return start;
	return par[start] = find(par[start]);
}

bool uni(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) return false;
	if(x < y) par[y] = x;
	else par[x] = y;
	return true;
}

void dfs(int start) {
	for(auto next : adj[start]) {
		if(vis[next.X] != -1) continue;
		vis[next.X] = vis[start] + next.Y;
		maxi = max(vis[next.X], maxi);
		dfs(next.X); 
	}
}

void init() {
	for(int i=0; i<1010; i++) par[i] = i;
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		v.push_back({{x, y}, d});
	}
	sort(v.begin(), v.end(), compare);
	for(int i=0; i<v.size(); i++) {
		int x = v[i].X.X, y = v[i].X.Y, dist = v[i].Y;
		if(uni(x, y)) {
			adj[x].push_back({y, dist});
			adj[y].push_back({x, dist});
			ans += dist;
		}
	}
	for(int i=0; i<n; i++) {
		memset(vis, -1, sizeof(vis));
		vis[i] = 0;
		dfs(i);
	}
	cout << ans << '\n' << maxi << '\n';
}		

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
#include <bits/stdc++.h>
#define X first
#define Y second
#define NUM 1000
#define INF 1e9
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
int n, graph[10][10], dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1}, ans = 0;
bool vis[10][10];

void dfs(int x, int y, int cnt) {
	if(x == 5 && y == 5 && cnt == 25-n) {
		ans++;
		return;
	}
	for(int i=0; i<4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if(nx < 1 || ny < 1 || nx > 5 || ny > 5 || vis[nx][ny] || graph[nx][ny] == -1) continue;
		vis[nx][ny] = true;
		dfs(nx, ny, cnt+1);
		vis[nx][ny] = false;
	}
}

void init() {
	memset(graph, 0, sizeof(graph));
	memset(vis, false, sizeof(vis));
	cin >> n;
	for(int i=0; i<n; i++) {
		int x, y;
		cin >> x >> y;
		graph[x][y] = -1;
	}
	vis[1][1] = true;
	dfs(1, 1, 1);
	cout << ans << '\n';
}		

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
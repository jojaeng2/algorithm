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
#define NUM 130
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
int n, m, graph[1010][1010], dp[4][1010][1010], dx[3] = {1, 0, 0}, dy[3] = {0, -1, 1};

int dfs(int x, int y, int dir) {
	if(dp[dir][x][y] != -1) return dp[dir][x][y];
	dp[dir][x][y] = graph[x][y];
	if(x == n && y == m) return dp[dir][x][y];
	int res = -INF;
	for(int i=0; i<3; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
		if((dir == 1 && i == 2) || (dir == 2 && i == 1)) continue;
		res = max(res, dfs(nx, ny, i));
	}
	dp[dir][x][y] += res;
	return dp[dir][x][y];
}

void init() {
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin >> graph[i][j];
	dfs(1, 1, 0);
	cout << dp[0][1][1] << '\n';
}	

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
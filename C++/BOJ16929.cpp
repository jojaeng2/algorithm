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
#define INF 1000000
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, int> pli;
int n, m, dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
char graph[51][51];
bool visit[51][51], flag = false, nvisit[51][51];

void dfs(int x, int y, int ex, int ey) {
	for(int i=0; i<4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if(nx < 1 || ny < 1 || nx > n || ny > m || graph[x][y] != graph[nx][ny]) continue;
		if(ex == nx && ey == ny) continue;

		if(visit[nx][ny]) {
			flag = true;
			return;
		}
		visit[nx][ny] = true;
		dfs(nx, ny, x, y);
	}
}

void init() {
	memset(graph, 0, sizeof(graph));
	memset(visit, false, sizeof(visit));
	cin >> n >> m;
	for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin >> graph[i][j];
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(visit[i][j] || flag) continue;
			visit[i][j] = true;
			dfs(i, j, 0, 0);
		}
	}
	if(flag) cout << "Yes" << '\n';
	else cout << "No" << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
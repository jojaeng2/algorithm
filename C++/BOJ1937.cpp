#include <iostream>
#include <cstring>
using namespace std;
int n;
int graph[501][501], visit[501][501], ans = 0;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

int dfs(int x, int y) {
	if(visit[x][y] == 0) {
		visit[x][y] = 1;
		for(int i=0; i<4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if(1>nx || nx>n || 1>ny || ny>n || graph[nx][ny] <= graph[x][y]) continue;
			visit[x][y] = max(visit[x][y], dfs(nx, ny)+1);
		}
	}
	return visit[x][y];
}

void dp() {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(visit[i][j] == 0) {
				visit[i][j] = dfs(i, j);
				ans = max(ans, visit[i][j]);
			}
		}
	}
	cout << ans << '\n';
}

void init() {
	memset(visit, 0, sizeof(visit));
	cin >> n;
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin >> graph[i][j];
}

int main() {
	init();
	dp();
}
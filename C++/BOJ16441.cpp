#include <bits/stdc++.h>
#define X first
#define Y second
#define NUM 100010
#define INF 1e18
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
int n, m, dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
char graph[110][110], ans[110][110];
bool vis[4][110][110];
queue<piii> q;

void bfs() {
	while(!q.empty()) {
		int x = q.front().X.X, y = q.front().X.Y, dir = q.front().Y;
		q.pop();
		if(graph[x][y] == '+') {
			int nx = x + dx[dir], ny = y + dy[dir];
			if(nx < 0 || ny < 0 || nx >= n || ny >= m || vis[dir][nx][ny]) continue;
			if(graph[nx][ny] == '#') {
				for(int i=0; i<4; i++) {
					int nx = x + dx[i], ny = y + dy[i];
					if(nx < 0 || ny < 0 || nx >=n || ny >= m || vis[i][nx][ny] || graph[nx][ny] == '#') continue;
					vis[i][nx][ny] = true;
					q.push({{nx, ny}, i});
				}
			}
			else {
				vis[dir][nx][ny] = true;
				q.push({{nx, ny}, dir});
			}
		}
		else {
			for(int i=0; i<4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if(nx < 0 || ny < 0 || nx >= n || ny >= m || graph[nx][ny] == '#' || vis[i][nx][ny]) continue;
				vis[i][nx][ny] = true;
				q.push({{nx, ny}, i});
			}
		}
		
	}
}

void init() {
	memset(vis, false, sizeof(vis));
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		string s;
		cin >> s;
		for(int j=0; j<m; j++) graph[i][j] = s[j], ans[i][j] = s[j];
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(graph[i][j] == 'W') {
				q.push({{i, j}, 0});
				vis[0][i][j] = true;
				bfs();
			}
		}
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(ans[i][j] == '.' && !vis[0][i][j] && !vis[1][i][j] && !vis[2][i][j] && !vis[3][i][j]) ans[i][j] = 'P';
		}
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cout << ans[i][j];
		}
		cout << '\n';
	}

}		

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;
int n, m, oil, taxi_x, taxi_y;
int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1}, graph[21][21], visit[21][21];
vector<pii> destination[21][21];
void bfs() {
	memset(visit, 0, sizeof(visit));
	queue<pii> q;
	q.push(make_pair(taxi_x,taxi_y));
	visit[taxi_x][taxi_y] = 1;
	while(!q.empty()) {
		int x = q.front().X, y = q.front().Y;
		q.pop();
		for(int i=0;i<4;i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if(1<=nx && nx<=n && 1<=ny && ny<=n) {
				if(graph[nx][ny] != -1 && visit[nx][ny] == 0) {
					visit[nx][ny] = visit[x][y] + 1;
					q.push(make_pair(nx,ny));
				}
			}
		}
	}
	int p_x, p_y, people, p_val = 1000;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			if(graph[i][j]>0 && visit[i][j]<p_val && visit[i][j] != 0) {
				p_x = i, p_y = j;
				people = graph[i][j];
				p_val = visit[i][j];
			}
		}
	}
	if(p_val == 1000) oil = -1;
	oil -= (p_val-1);
	if(oil<0) return;
	graph[p_x][p_y] = 0;
	memset(visit, 0, sizeof(visit));
	q.push(make_pair(p_x, p_y));
	visit[p_x][p_y] = 1;
	int dest_x = destination[p_x][p_y][0].X;
	int dest_y = destination[p_x][p_y][0].Y;

	while(!q.empty()) {
		int x = q.front().X, y = q.front().Y;
		q.pop();
		if(dest_x == x && dest_y == y) {
			oil -= (visit[x][y]-1);
			if(oil<0) oil = -1;
			else {
				oil += (visit[x][y]-1)*2;
				taxi_x = x, taxi_y = y;
			}
			return;
		}
		for(int i=0;i<4;i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if(1<=nx && nx<=n && 1<=ny && ny<=n) {
				if(graph[nx][ny] != -1 && visit[nx][ny] == 0) {
					visit[nx][ny] = visit[x][y] + 1;
					q.push(make_pair(nx,ny));
				}
			}
		}
	}
	oil = -1;
}

int main(){
	cin >> n >> m >> oil;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			cin >> graph[i][j];
			if(graph[i][j] == 1) {
				graph[i][j] = -1;
			}
		}
	}
	cin >> taxi_x >> taxi_y;
	for(int i=1;i<=m;i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		graph[a][b] = i;
		destination[a][b].push_back(make_pair(c,d));
	}
	for(int i=1;i<=m;i++) {
		if(oil<0) break;
		bfs();
	}
	if(oil<0) cout << -1 << '\n';
	else {
		cout << oil << '\n';
	}
}
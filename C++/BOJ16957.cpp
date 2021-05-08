#include <iostream>
#include <cstring>
#include <tuple>
using namespace std;
struct str{
	int xx;
	int yy;
};
int dx[8] = {-1,1,0,0,-1,-1,1,1}, dy[8] = {0,0,-1,1,1,-1,1,-1};
int n, m, graph[501][501], now[501][501], dir[501][501][2];

str dfs(int x,int y) {
	if(dir[x][y][0] == x && dir[x][y][1] == y) {
		now[x][y] += 1;
		str s;
		s.xx = x;
		s.yy = y;
		return s;
	}
	str k = dfs(dir[x][y][0], dir[x][y][1]);
	dir[x][y][0] = k.xx, dir[x][y][1] = k.yy;
	return k;
}

int main() {
	memset(now,0,sizeof(now));
	cin >> n >> m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin >> graph[i][j];
	
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			int mini = graph[i][j];
			dir[i][j][0] = i, dir[i][j][1] = j;
			for(int p=0;p<8;p++) {
				int nx = i + dx[p], ny = j + dy[p];
				if(1<=nx && nx<=n && 1<=ny && ny<=m) {
					if(mini>graph[nx][ny]) {
						mini = graph[nx][ny];
						dir[i][j][0] = nx, dir[i][j][1] = ny;
					}
				}
			}
		}
	}

	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			dfs(i,j);
		}
	}


	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			cout << now[i][j] << " ";
		}
		cout << '\n';
	}
}
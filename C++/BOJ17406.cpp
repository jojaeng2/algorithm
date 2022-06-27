#include <iostream>
#include <vector>
#include <deque>
#define X first
#define Y second
using namespace std;
typedef pair<pair<int,int>, int> pii;
int n, m, k, dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int now[51][51], ans = 987654321;
vector<pii> cycle;
bool visit[6];

void find_max() {
	for(int i=1;i<=n;i++) {
		int row_cnt = 0;
		for(int j=1;j<=m;j++) {
			row_cnt += now[i][j];
		}
		ans = min(ans, row_cnt);
	}
}

void rotation(int row, int column, int count) {
	deque<int> dq;
	for(int i=1;i<=count;i++) {
		dq.clear();
		int x = row-i, y = column-i+1, dir = 0;
		dq.push_back(now[x][y-1]);
		while(true) {
			dq.push_back(now[x][y]);
			now[x][y] = dq.front();
			dq.pop_front();
			if(x == row-i && y == column-i) break;
			if((x == row-i && y == column+i) || (x == row+i && y == column+i) || (x == row+i && y == column-i)) dir++;
			x = x + dx[dir];
			y = y + dy[dir];
		}
	}
}

void dfs(int cnt) {
	if(cnt == k) {
		find_max();
		return;
	}
	int before[51][51];
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) before[i][j] = now[i][j];
	for(int i=0;i<k;i++) {
		if(visit[i]) continue;
		visit[i] = true;
		int row = cycle[i].X.X, column = cycle[i].X.Y, count = cycle[i].Y;
		rotation(row, column, count);
		dfs(cnt+1);
		visit[i] = false;
		for(int j=1;j<=n;j++) for(int p=1;p<=m;p++) now[j][p] = before[j][p];
	}
}

void init() {
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin >> now[i][j];
	for(int i=0;i<k;i++) {
		int row, column, count;
		cin >> row >> column >> count;
		cycle.push_back(make_pair(make_pair(row,column),count));
		visit[i] = false;
	}
}

int main() {
	init();
	dfs(0);
	cout << ans << '\n';
}	
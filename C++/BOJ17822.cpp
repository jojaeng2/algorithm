#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;
int n, m, t, x, d, k, dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
vector<deque<int> > circle;

void print() {
	int ans = 0;
	
	for(int i=0; i<n; i++) for(int j=0; j<m; j++) ans += circle[i][j];
	cout << ans << '\n';
}

void average() {
	int son = 0, mother = 0;
	for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
		if(circle[i][j] != 0) {
			mother++;
			son += circle[i][j];
		}
	}
	float number = (float) son / (float) mother;

	for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
		if(circle[i][j] == 0) continue;
		if(number > circle[i][j]) circle[i][j]++;
		else if(number < circle[i][j]) circle[i][j]--;
	}

}

bool bfs() {
	bool flag = false;
	queue<pii> q;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(circle[i][j] == 0) continue;
			q.push(make_pair(i, j));
			int now = circle[i][j];
			while(!q.empty()) {
				int x = q.front().X, y = q.front().Y;
				q.pop();
				for(int p=0; p<4; p++) {
					int nx = x + dx[p], ny = y + dy[p];
					if(nx == -1 || nx == n) continue;
					if(ny == -1) ny = m-1;
					if(ny == m) ny = 0;
					if(circle[nx][ny] == now) {
						flag = true;
						circle[x][y] = 0;
						circle[nx][ny] = 0;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
	if(flag) return true;
	return false;
}

void spin(int num, int dir, int cnt) {
	cnt %= m;
	for(int i=0; i<circle.size(); i++) {
		if((i+1)%num != 0) continue;
		if(dir == 1) {
			for(int j=0; j<cnt; j++) {
				int next = circle[i].front();
				circle[i].push_back(next);
				circle[i].pop_front();
			}
		}
		else {
			for(int j=0; j<cnt; j++) {
				int next = circle[i].back();
				circle[i].push_front(next);
				circle[i].pop_back();
			}
		}
	}
}

void init() {
	cin >> n >> m >> t;
	for(int i=0; i<n; i++) {
		deque<int> dq;
		for(int j=0; j<m; j++) {
			int a;
			cin >> a;
			dq.push_back(a);
		}
		circle.push_back(dq);
	}

	for(int i=0; i<t; i++) {
		cin >> x >> d >> k;
		spin(x, d, k);
		if(bfs()) continue;
		average();
	}
}

int main() {
	init();
	print();
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <bitset>
#include <set>
#include <map>
#define X first
#define Y second
#define NUM 200010
#define MOD 1000000007
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int num[10][10], answer = 0, dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
bool visit[10][10], bfs_visit[10][10];
vector<pii> v;
queue<pii> q;

bool bfs() {
	memset(bfs_visit, false, sizeof(bfs_visit));	
	int cnt = 0;
	for(int i=1; i<5; i++) {
		for(int j=1; j<5; j++) {
			if(visit[i][j] && !bfs_visit[i][j]) {
				cnt++;
				bfs_visit[i][j] = true;
				q.push({i, j});
				while(!q.empty()) {
					int x = q.front().X, y = q.front().Y;
					q.pop();
					for(int k=0; k<4; k++) {
						int nx = x + dx[k], ny = y + dy[k];
						if(nx<1 || ny<1 || nx>4 || ny>4 || bfs_visit[nx][ny] || !visit[nx][ny]) continue;
						bfs_visit[nx][ny] = true;
						q.push({nx, ny}); 
					}
				}
			}
		}
	}
	if(cnt != 1) return false;
	memset(bfs_visit, false, sizeof(bfs_visit));	
	for(int i=0; i<6; i++) {
		for(int j=0; j<6; j++) {
			if(!visit[i][j] && !bfs_visit[i][j]) {
				cnt++;
				bfs_visit[i][j] = true;
				q.push({i, j});
				while(!q.empty()) {
					int x = q.front().X, y = q.front().Y;
					q.pop();
					for(int k=0; k<4; k++) {
						int nx = x + dx[k], ny = y + dy[k];
						if(nx<0 || ny<0 || nx>5 || ny>5 || bfs_visit[nx][ny] || visit[nx][ny]) continue;
						bfs_visit[nx][ny] = true;
						q.push({nx, ny}); 
					}
				}
			}
		}
	}
	return cnt == 2;
}

void dfs(int now) {
	if(bfs()) {
		bool flag = false;
		for(int i=0; i<v.size(); i++) {
			int x = v[i].X, y = v[i].Y;
			if(!visit[x][y]) flag = true;
		}
		if(!flag) answer++;
	}
	if(now == 35) return;
	for(int i=now+1; i<36; i++) {
		if(i/6 == 0 || i%6 == 5 || i%6 == 0 || i/6 == 5) continue;
		visit[i/6][i%6] = true;
		dfs(i);
		visit[i/6][i%6] = false;
	}
}

void init() {
	memset(num, 0, sizeof(num));
	memset(visit, false, sizeof(visit));
	for(int i=1; i<=4; i++) for(int j=1; j<=4; j++) {
		cin >> num[i][j];
		if(num[i][j]) v.push_back({i, j});
	}
	for(int i=0; i<36; i++) {
		if(i/6 == 0 || i%6 == 5 || i%6 == 0 || i/6 == 5) continue;
		visit[i/6][i%6] = true;
		dfs(i);
		visit[i/6][i%6] = false;
	}
	cout << answer << '\n';
}
int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}

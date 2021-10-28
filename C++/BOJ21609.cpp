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
int n, m, graph[21][21], dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1}, bsize, brain, msize, mrain, mrow, mcol, answer = 0;
bool visit[21][21];
queue<pii> q;

void bfs(int s, int e) {
	bsize = 1, brain = 0;
	while(!q.empty()) {
		int x = q.front().X, y = q.front().Y;
		q.pop();
		for(int i=0; i<4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if(nx < 1 || ny < 1 || nx > n || ny > n || visit[nx][ny]) continue;
			if(graph[nx][ny] != s && graph[nx][ny] != 0) continue;
			visit[nx][ny] = true;
			if(graph[nx][ny] == 0) brain++;
			if(e == -1) graph[nx][ny] = -2;
			bsize++;
			q.push({nx, ny});
		}
	}
}

void gravity() {
	for(int i=n; i>=1; i--) {
		for(int j=n; j>=1; j--) {
			if(graph[i][j] == -2) {
				for(int k=i-1; k>=1; k--) {
					if(graph[k][j] >= 0) {
						swap(graph[i][j], graph[k][j]);
						break;
					}
					if(graph[k][j] == -1) break;
				}
			}
		}
	}
}

void _rotate() {
	int ngraph[21][21];
	memset(ngraph, 0, sizeof(ngraph));
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			ngraph[i][j] = graph[j][n-i+1];
		}
	}
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) graph[i][j] = ngraph[i][j];
	return;
}

void init() {
	cin >> n >> m;
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin >> graph[i][j];
	while(true) {
		memset(visit, false, sizeof(visit));
		msize = 0, mrain = 0, mrow = 0, mcol = 0;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(graph[i][j] > 0 && !visit[i][j]) {
					visit[i][j] = true;
					q.push({i, j});
					bfs(graph[i][j], 0);
					for(int k=1; k<=n; k++) for(int p=1; p<=n; p++) if(graph[k][p] == 0) visit[k][p] = false;
					if(bsize < 2) continue;
					if(bsize > msize || (bsize == msize && brain > mrain) || (bsize == msize && brain == mrain && i > mrow) || (bsize == msize && brain == mrain && i == mrow && j > mcol)) {
						msize = bsize;
						mrain = brain;
						mrow = i, mcol = j;
					}
				}
			}
		}
		if(msize < 2) break;
		answer += POW2(msize);
		memset(visit, false, sizeof(visit));
		visit[mrow][mcol] = true;
		q.push({mrow, mcol});
		bfs(graph[mrow][mcol], -1);
		graph[mrow][mcol] = -2;
		
		gravity();
		_rotate();
		gravity();

	}
	cout << answer << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
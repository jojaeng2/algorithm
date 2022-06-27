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
#define INF 2000000000
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
int n, m, t, d, dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1}, visit[30][30][30][30], graph[30][30];
int answer = 0;

void dijkstra(int sx, int sy) {
	visit[sx][sy][sx][sy] = 0;
	priority_queue<piii> pq;
	pq.push({{0, sx}, sy});
	while(!pq.empty()) {
		int dist = -pq.top().X.X, x = pq.top().X.Y, y = pq.top().Y;
		pq.pop();
		if(visit[sx][sy][x][y] < dist) continue;
		for(int i=0; i<4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
			int cost = graph[nx][ny] - graph[x][y];
			if(abs(cost) > t) continue;
			if(graph[nx][ny] > graph[x][y]) {
				if(visit[sx][sy][nx][ny] <= dist + pow(cost, 2) || dist+pow(cost, 2) > d) continue;
				visit[sx][sy][nx][ny] = dist + pow(cost, 2);
				pq.push({{-visit[sx][sy][nx][ny], nx}, ny});
			}
			else {
				if(visit[sx][sy][nx][ny] <= dist + 1 || dist+1 > d) continue;
				visit[sx][sy][nx][ny] = dist + 1;
				pq.push({{-visit[sx][sy][nx][ny], nx}, ny});
			}
		}
	}
}

void init() {
	memset(visit, 1e4, sizeof(visit));
	cin >> n >> m >> t >> d;
	for(int i=1; i<=n; i++) {
		string s;
		cin >> s;
		for(int j=0; j<s.size(); j++) {
			if('a' <= s[j] && s[j] <= 'z') graph[i][j+1] = s[j] - 'A' - 6;
			else graph[i][j+1] = s[j] - 'A';
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=0; j<m; j++) {
			dijkstra(i, j+1);
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(visit[1][1][i][j] + visit[i][j][1][1] <= d) {
				answer = max(answer, graph[i][j]);
			}
		}
	}
	cout << answer << '\n';

}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
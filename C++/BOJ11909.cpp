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
#define NUM 1000010
#define INF 987654321
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> plll;
int n, dx[4] = {1, 0}, dy[4] = {0, 1};
ll graph[2500][2500], visit[2500][2500];

void dijkstra() {
	priority_queue<plll> pq;
	pq.push({{0, 1}, 1});
	visit[1][1] = 0;
	while(!pq.empty()) {
		ll dist = -pq.top().X.X, x = pq.top().X.Y, y = pq.top().Y;
		pq.pop();
		if(visit[x][y] < dist) continue;
		for(int i=0; i<2; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			ll cost = graph[nx][ny];
			if(nx < 1 || ny < 1 || nx > n || ny > n) continue;
			if(graph[x][y] > graph[nx][ny] && dist < visit[nx][ny]) {
				visit[nx][ny] = dist;
				pq.push({{-dist, nx}, ny});
			} 
			if(graph[x][y] <= graph[nx][ny] && abs(graph[x][y] - graph[nx][ny]) + dist + 1 < visit[nx][ny]) {
				visit[nx][ny] = dist + abs(graph[x][y] - graph[nx][ny])+1;
				pq.push({{-visit[nx][ny], nx}, ny});
			} 
		}
	}
}

void init() {
	cin >> n;
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) {
		cin >> graph[i][j];
		visit[i][j] = INF;
	}
	dijkstra();
	cout << visit[n][n] << '\n';

}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
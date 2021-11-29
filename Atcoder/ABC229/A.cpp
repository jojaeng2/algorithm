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
#define INF 987654321
#define MOD 1000000007
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, double> piib;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> plll;
int cnt = 0, dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
char graph[2][2];
bool visit[2][2] = {false};
queue<pii> q;

void bfs() {
	while(!q.empty()) {
		int x = q.front().X, y = q.front().Y;
		q.pop();
		for(int i=0; i<4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if(nx < 0 || ny < 0 || nx > 1 || ny > 1 || visit[nx][ny] || graph[nx][ny] != '#') continue;
			q.push({nx, ny});
			visit[nx][ny] = true;
		}
	}
}

void init() {
	for(int i=0; i<2; i++) for(int j=0; j<2; j++) cin >> graph[i][j];
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++) {
			if(graph[i][j] == '#' && !visit[i][j]) {
				q.push({i, j});
				cnt++;
				bfs();
			}
		}
	}
	if(cnt <= 1) cout << "Yes" << '\n';
	else cout << "No" << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
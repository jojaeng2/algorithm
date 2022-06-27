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
#include <cmath>
#define X first
#define Y second
#define NUM 10010
#define INF 1000000000
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, int> pli;
struct st {
	int x, y, gcnt, scnt;
};

struct compare {
	bool operator() (st a, st b) {
		if(a.gcnt == b.gcnt) {
			return a.scnt > b.scnt;
		}
		return a.gcnt > b.gcnt;
	}
};
int N, M, sx, sy, dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
bool visit[51][51];
char graph[51][51];
priority_queue<st, vector<st>, compare> pq;

void dijkstra() {
	st str;
	str.gcnt = 0, str.scnt = 0, str.x = sx, str.y = sy;
	pq.push(str);

	while(!pq.empty()) {
		int x = pq.top().x, y = pq.top().y, gcnt = pq.top().gcnt, scnt = pq.top().scnt;
		pq.pop();
		if(graph[x][y] == 'F') {
			cout << gcnt << " " << scnt << '\n';
			break;
		}
		for(int i=0; i<4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if(nx < 1 || ny < 1 || nx > N || ny > M || visit[nx][ny]) continue;
			st s;
			s.x = nx, s.y = ny, s.gcnt = gcnt, s.scnt = scnt;
			visit[nx][ny] = true;
			if(graph[nx][ny] == 'g') s.gcnt++;
			for(int j=0; j<4; j++) {
				int nnx = nx + dx[j], nny = ny + dy[j];
				if(nnx < 1 || nny < 1 || nnx > N || nny > M) continue;
				if(graph[nnx][nny] == 'g' && graph[nx][ny] == '.') {
					s.scnt++;
					break;
				}
			}
			pq.push(s);
		}
	}
}

void init() {
	memset(visit, false, sizeof(visit));
	cin >> N >> M;
	for(int i=1; i<=N; i++) {
		string s;
		cin >> s;
		for(int j=0; j<s.size(); j++) {
			graph[i][j+1] = s[j];
			if(graph[i][j+1] == 'S') sx = i, sy = j+1;
		}
	}
	dijkstra();
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
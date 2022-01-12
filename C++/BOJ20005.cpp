#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <cstring>
#include <queue>
#include <map>
#include <string>

#define X first
#define Y second
#define NUM 1010
#define INF 1e9
#define MINF 0x7f7f7f7f
#define MOD 1000000007
#define LOG 22
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<int, ll> pil;
typedef pair<pii, int> piii;
typedef pair<piii, int> piiii;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> plll;
int n, m, p, sx, sy, hp, dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1}, now = 0,  psum = 0, cnt = 0;
char graph[1010][1010];
int visit[1010][1010];
map<char, pii> mp;
map<int, int> at, cc;
queue<pii> q;
set<int> key;
priority_queue<piii> pq;

void bfs() {
	q.push({sx, sy});
	while(!q.empty()) {
		int x = q.front().X, y = q.front().Y;
		q.pop();
		for(int i=0; i<4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if(nx < 0 || ny < 0 || nx >= n || ny >= m || visit[nx][ny] != -1 || graph[nx][ny] == 'X') continue;
			visit[nx][ny] = visit[x][y] + 1;
			q.push({nx, ny});
		}
	}
}

void init() {
	memset(visit, -1, sizeof(visit));
	cin >> n >> m >> p;
	for(int i=0; i<n; i++) {
		string s;
		cin >> s;
		for(int j=0; j<m; j++) {
			graph[i][j] = s[j];
			if('a' <= s[j] && s[j] <= 'z') mp[s[j]] = pii(i, j);
			if(s[j] == 'B') sx = i, sy = j;
		}
	}
	visit[sx][sy] = 0;
	bfs();
	for(int i=0; i<p; i++) {
		char x;
		int y;
		cin >> x >> y;
		if(visit[mp[x].X][mp[x].Y] == -1) continue;
		at[visit[mp[x].X][mp[x].Y]] += y;
		cc[visit[mp[x].X][mp[x].Y]]++;
		key.insert(visit[mp[x].X][mp[x].Y]);
	}
	cin >> hp;
	for(auto k : key) pq.push({{-k, at[k]}, cc[k]});

	while(!pq.empty()) {
		int d = -pq.top().X.X, atack = pq.top().X.Y, c = pq.top().Y;
		pq.pop();
		hp -= (d-now) * psum;
		if(hp <= 0) break;
		now = d;
		psum += atack;
		cnt += c;
	}
	cout << cnt << '\n';

}																		

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
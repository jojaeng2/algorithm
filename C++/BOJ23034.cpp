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
#define NUM 1010
#define INF 2000000000
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
int n, m, par[1010], query, maxi, se, ee, answer;
bool visit[1010];
vector<pii> adj[1010];
vector<piii> conn, v;
bool flag;

int find(int start) {
	if(start == par[start]) return start;
	return par[start] = find(par[start]);
}

bool uni(int x, int y) {
	int xx = find(x), yy = find(y);
	if(xx == yy) return false;
	if(yy < xx) par[xx] = yy;
	else par[yy] = xx;
	return true;
}

void dfs(int curr, int prev, int e) {
	if(curr == e) {
		flag = true;
		return;
	}
	for(auto next : adj[curr]) {
		if(next.X == prev || flag) continue;
		v.push_back({{curr, next.X}, next.Y});
		dfs(next.X, curr, e);
		if(flag) return;
		v.pop_back();
	}
}

bool compare(piii a, piii b) {
	return a.Y < b.Y;
}

void bfs(int start, int ns, int ne) {
	memset(visit, false, sizeof(visit));
	queue<pii> q;
	while(!q.empty()) q.pop();
	q.push({start, 0});
	visit[start] = true;
	while(!q.empty()) {
		int curr = q.front().X, psum = q.front().Y;
		q.pop();
		answer = max(answer, psum);
		for(auto next : adj[curr]) {
			if(visit[next.X]) continue;
			visit[next.X] = true;
			if(curr == ns && next.X == ne) continue;
			if(curr == ne && next.X == ns) continue;
			answer += next.Y;
			q.push({next.X, next.Y});
		}
	}
}

void init() {
	for(int i=0; i<1010; i++) par[i] = i;
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		conn.push_back({{x, y}, d});
	}
	sort(conn.begin(), conn.end(), compare);
	for(auto edge : conn) {
		int x = edge.X.X, y = edge.X.Y, dist = edge.Y;
		if(uni(x, y)) {
			adj[x].push_back({y, dist});
			adj[y].push_back({x, dist});
		}
	}
	cin >> query;
	for(int i=0; i<query; i++) {
		maxi = 0;
		answer = 0;
		v.clear();
		flag = false;

		int x, y;
		cin >> x >> y;
		dfs(x, -1, y);
		for(auto next : v) {
			if(next.Y > maxi) {
				maxi = next.Y;
				se = next.X.X, ee = next.X.Y;
			}
		}
		int ans = 0;
		bfs(x, se, ee);
		ans += answer;
		answer = 0;
		bfs(y, se, ee);
		ans += answer;
		cout << ans << '\n';
	}
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
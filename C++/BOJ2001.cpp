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
#define X first
#define Y second
#define NUM 1000010
#define INF 1e15
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, int> pli;
int n, m, k, gem[110], answer = 0;
bool visit[33000][110];
vector<pii> graph[110];
queue<piii> q;

void bfs() {
	visit[0][1] = true;
	q.push({{1, 0}, 0});
	while(!q.empty()) {
		int now = q.front().X.X, psum = q.front().X.Y, cnt = q.front().Y;
		q.pop();
		if(now == 1) answer = max(answer, cnt);
		for(int i=0; i<graph[now].size(); i++) {
			int next = graph[now][i].X, h = graph[now][i].Y;
			if(h < cnt || visit[psum][next]) continue;
			visit[psum][next] = true;
			q.push({{next, psum}, cnt});
			if(gem[next] != 0) {
				if(visit[psum | (1 << gem[next])][next]) continue;
				visit[psum | (1 << gem[next])][next] = true;
				q.push({{next, psum | (1<<gem[next])}, cnt+1});
			}
		}
	}
}

void init() {
	memset(visit, false, sizeof(visit));
	memset(gem, 0, sizeof(gem));
	cin >> n >> m >> k;
	for(int i=1; i<=k; i++) {
		int x;
		cin >> x;
		gem[x] = i;
	}
	for(int i=0; i<m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		graph[x].push_back({y, z});
		graph[y].push_back({x, z});
	}
	bfs();
	cout << answer << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
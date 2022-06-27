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
#define INF 1e14
#define NUM 100010
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
typedef pair<int, int> pii;
int n, m, k, s, p, q, visit[NUM];
ll ans[NUM];
bool bvisit[NUM];
vector<int> graph[NUM];
queue<pii> qu;

void dijkstra() {
	priority_queue<pli> pq;
	ans[1] = 0;
	pq.push({0, 1});
	while(!pq.empty()) {
		int now = pq.top().Y;
		ll dist = -pq.top().X;
		pq.pop();
		if(ans[now]<dist) continue;
		for(int i=0; i<graph[now].size(); i++) {
			int next = graph[now][i];
			if(visit[next]==1) continue;
			if(visit[next]==2) {
				if(ans[next] <= dist+q) continue;
				ans[next] = dist+(ll)q;
				pq.push({-ans[next], next});
			}
			else {
				if(ans[next]<=dist+p) continue;
				ans[next] = dist+(ll)p;
				pq.push({-ans[next], next});
			}
		}
	}
}

void bfs() {
	while(!qu.empty()) {
		int now = qu.front().X, d = qu.front().Y;
		qu.pop();
		if(d == s) continue;
		for(int i=0; i<graph[now].size(); i++) {
			int next = graph[now][i];
			if(visit[next] || bvisit[next]) continue;
			bvisit[next] = true;
			visit[next] = 2;
			qu.push({next, d+1});
		}
	}
}

void init() {
	memset(visit, 0, sizeof(visit));
	memset(bvisit, false, sizeof(bvisit));
	fill(ans, ans+NUM, INF);
	cin >> n >> m >> k >> s >> p >> q;
	for(int i=0; i<k; i++) {
		int x;
		cin >> x;
		visit[x] = 1;
		bvisit[x] = true;
		qu.push({x, 0});
	}
	for(int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	bfs();
	dijkstra();
	if(visit[n] == 2) ans[n] -= q;
	else ans[n] -= p;
	cout << ans[n] << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
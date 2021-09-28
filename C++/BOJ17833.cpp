#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
#define X first
#define Y second
#define INF 1e10
using namespace std;
struct st {
	int h, c, x, y;
};
typedef long long ll;
typedef pair<ll, int> piii;
ll visit[2001];
int n, r, d, m;
vector<st> graph;


void dijkstra(int s) {
	priority_queue<piii> pq;
	pq.push({0, s});
	visit[s] = 0;
	while(!pq.empty()) {
		ll dist = -pq.top().X;
		int now = pq.top().Y;
		pq.pop();
		if(visit[now] < dist) continue;
		for(int i=0; i<graph.size(); i++) {
			int h = graph[i].h, cost = graph[i].c, x = graph[i].x, y = graph[i].y;
			int next1 = now+y-x, next2 = now+x-y;
			if(next1 > 0 && visit[next1]>(ll)cost+dist && (now+h-x) <= n && x <= now) {
				visit[next1] = (ll)cost + dist;

				pq.push({-visit[next1], next1});
			}
			if(next2 > 0 && visit[next2]>(ll)cost+dist && (now+h-y) <= n && y <= now) {
				visit[next2] = (ll)cost + dist;
				pq.push({-visit[next2], next2});
			}
		}
	}
}

void init() {
	fill(visit, visit+2001, INF);
	cin >> n >> r >> d >> m;
	for(int i=0; i<m; i++) {
		st s;
		cin >> s.h >> s.c >> s.x >> s.y;
		graph.push_back(s);
	}
	dijkstra(r);
	if(visit[d]==INF) cout << -1 << '\n';
	else cout << visit[d] << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
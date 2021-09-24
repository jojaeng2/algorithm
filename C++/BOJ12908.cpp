#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e10
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
ll sx, sy, ex, ey, cnt = 1; 
ll visit[10];
vector<pii> graph[10];
vector<pii> v;

void dijkstra(ll s) {
	priority_queue<pii> pq;
	pq.push(make_pair(0, s));
	visit[s] = 0;
	while(!pq.empty()) {
		ll dist = -pq.top().X, now = pq.top().Y;
		pq.pop();
		if(visit[now] < dist) continue;
		for(int i=0; i<graph[now].size(); i++) {
			ll next = graph[now][i].X, cost = dist + graph[now][i].Y;
			if(visit[next] <= cost) continue;
			visit[next] = cost;
			pq.push(make_pair(-cost, next));
		}
	}
	cout << visit[7] << '\n';
}

void init() {
	fill(visit, visit+10, INF);
	cin >> sx >> sy >> ex >> ey;
	graph[0].push_back(make_pair(7, abs(sx-ex) + abs(sy-ey)));
	for(int i=0; i<3; i++) {
		ll x, y, xx, yy;
		cin >> x >> y >> xx >> yy;
		v.push_back(make_pair(x, y));
		v.push_back(make_pair(xx, yy));
		graph[0].push_back(make_pair(cnt++, abs(sx-x) + abs(sy-y)));
		graph[0].push_back(make_pair(cnt++, abs(sx-xx) + abs(sy-yy)));
	}
	for(int i=0; i<v.size(); i++) {
		ll x = v[i].X, y = v[i].Y;
		graph[i+1].push_back(make_pair(7, abs(x-ex) + abs(y-ey)));
		for(int j=0; j<v.size(); j++) {
			if(i == j) continue;
			ll nx = v[j].X, ny = v[j].Y;
			if(i%2 == 0 && i+1 == j) graph[i+1].push_back(make_pair(j+1, 10));
			else if(i%2 == 1 && i-1 == j) graph[i+1].push_back(make_pair(j+1, 10));
			else graph[i+1].push_back(make_pair(j+1, abs(x-nx)+abs(y-ny)));
		}
	}
	dijkstra(0);
}

int main() {
	init();
}
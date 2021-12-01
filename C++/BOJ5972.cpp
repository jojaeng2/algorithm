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
#define NUM 10000
#define INF 987654321
#define MOD 1000000007
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
int n, m, visit[50010];
vector<pii> adj[50010];

void dijkstra() {
	visit[1] = 0;
	priority_queue<pii> pq;
	pq.push({0, 1});
	while(!pq.empty()) {
		int dist = -pq.top().X, curr = pq.top().Y;
		pq.pop();
		if(visit[curr] < dist) continue;
		for(auto next : adj[curr]) {
			if(visit[next.X] <= dist + next.Y) continue;
			visit[next.X] = dist + next.Y;
			pq.push({-visit[next.X],next.X});
		}
	}
}

void init() {
	memset(visit, 1e4, sizeof(visit));
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		adj[x].push_back({y, d});
		adj[y].push_back({x, d});
	}
	dijkstra();
	cout << visit[n] << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
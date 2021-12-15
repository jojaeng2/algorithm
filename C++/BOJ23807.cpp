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
#define INF 20000000000000
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
int n, m, k;
ll visit[110][NUM], s, e;
map<int, ll> mp;
vector<pll> adj[NUM];

void dijkstra(int idx, ll ss) {
	priority_queue<pll> pq;
	visit[idx][ss] = 0;
	pq.push({0, ss});
	while(!pq.empty()) {
		ll dist = -pq.top().X, curr = pq.top().Y;
		pq.pop();
		if(visit[idx][curr] < dist) continue;
		for(auto next : adj[curr]) {
			if(visit[idx][next.X] <= dist + next.Y) continue;
			visit[idx][next.X] = dist + next.Y;
			pq.push({-visit[idx][next.X], next.X});
		}
	}
}

void init() {
	cin >> n >> m;
	for(int i=0; i<110; i++) for(int j=0; j<=n; j++) visit[i][j] = INF;
	for(int i=0; i<m; i++) {
		ll x, y, z;
		cin >> x >> y >> z;
		adj[x].push_back({y, z});
		adj[y].push_back({x, z});
	}
	cin >> s >> e >> k;
	dijkstra(0, s);
	for(int i=1; i<=k; i++) {
		ll x;
		cin >> x;
		mp[i] = x;
		dijkstra(i, x);
	}
	ll answer = INF;
	for(int i=1; i<=k; i++) {
		ll s1 = mp[i];
		for(int j=1; j<=k; j++) {
			ll s2 = mp[j];
			for(int p=1; p<=k; p++) {
				ll s3 = mp[p];
				if(i == j || j == p || i == p) continue;
				answer = min(answer, visit[0][s1] + visit[i][s2] + visit[j][s3] + visit[p][e]);
			}
		}
	}
	if(answer == INF) answer = -1;
	cout << answer << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
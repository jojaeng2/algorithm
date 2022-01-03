#include <bits/stdc++.h>
#define X first
#define Y second
#define NUM 410
#define INF 1e9
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
int n, m, c[2*NUM+100][2*NUM+100], f[2*NUM+100][2*NUM+100], d[2*NUM+100][2*NUM+100], s = 900, e = 901;
vector<int> adj[2*NUM+100];

void bfs() {
	int cost = 0, cnt = 0;
	while(true) {
		int prev[2*NUM+100], dist[2*NUM+100];
		bool isq[2*NUM+100];
		memset(prev, -1, sizeof(prev));
		fill(dist, dist+2*NUM+100, INF);
		memset(isq, false, sizeof(isq));
		queue<int> q;
		q.push(s);
		isq[s] = true;
		dist[s] = 0;
		while(!q.empty()) {
			int curr = q.front();
			q.pop();
			isq[curr] = false;
			for(int next : adj[curr]) {
				if(c[curr][next] - f[curr][next] > 0 && dist[next] > dist[curr] + d[curr][next]) {
					dist[next] = dist[curr] + d[curr][next];
					prev[next] = curr;
					if(!isq[next]) {
						q.push(next);
						isq[next] = true;
					}
				}
			}
		}
		if(prev[e] == -1) break;
		int flow = INF;
		for(int i=e; i!=s; i=prev[i]) flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
		for(int i=e; i!=s; i=prev[i]) {
			cost += flow * d[prev[i]][i];
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}
		cnt++;
	}
	cout << cnt << "\n" << cost << '\n';
}

void init() {
	memset(c, 0, sizeof(c));
	memset(f, 0, sizeof(f));
	memset(d, 0, sizeof(d));
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		int x;
		cin >> x;
		c[s][i] = 1;
		adj[s].push_back(i);
		while(x--) {
			int y, z;
			cin >> y >> z;
			y += NUM;
			c[y][e] = 1, c[i][y] = 1;
			d[i][y] = z, d[y][i] = -z;
			adj[i].push_back(y);
			adj[y].push_back(e);
		}
	}
	bfs();
}		

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
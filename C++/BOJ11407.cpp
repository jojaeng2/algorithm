#include <bits/stdc++.h>
#define X first
#define Y second
#define NUM 100
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
int n, m, c[2*NUM+10][2*NUM+10], f[2*NUM+10][2*NUM+10], d[2*NUM+10][2*NUM+10], src = 201, sink = 202;
vector<int> adj[2*NUM+10];

void bfs() {
	int cost = 0, cnt = 0;
	while(true) {
		int prev[2*NUM+10], dist[2*NUM+10];
		bool isq[2*NUM+10];
		queue<int> q;
		memset(dist, MINF, sizeof(dist));
		memset(prev, -1, sizeof(prev));
		memset(isq, false, sizeof(isq));
		q.push(src);
		isq[src] = true;
		dist[src] = 0;
		while(!q.empty()) {
			int curr = q.front();
			q.pop();
			isq[curr] = false;
			for(int next : adj[curr]) {
				if(c[curr][next] - f[curr][next] > 0 && dist[next] > dist[curr] + d[curr][next]) {
					dist[next] = dist[curr] + d[curr][next];
					prev[next] = curr;
					if(!isq[next]) {
						isq[next] = true;
						q.push(next);
					}
				}
			}
		}
		if(prev[sink] == -1) break;
		int flow = INF;
		for(int i=sink; i!=src; i=prev[i]) flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
		for(int i=sink; i!=src; i=prev[i]) {
			cost += d[prev[i]][i] * flow;
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}
		cnt += flow;
	}
	cout << cnt << '\n' << cost << '\n';
}

void init() {
	memset(c, 0, sizeof(c));
	memset(f, 0, sizeof(f));
	memset(d, 0, sizeof(d));
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		int x;
		cin >> x;
		c[i+NUM][sink] = x;
		adj[i+NUM].push_back(sink);
		adj[sink].push_back(i+NUM);
	}
	for(int i=1; i<=m; i++) {
		int x;
		cin >> x;
		c[src][i] = x;
		adj[src].push_back(i);
		adj[i].push_back(src);
	}
	
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=n; j++) {
			int x;
			cin >> x;
			if(!x) continue;
			c[i][j+NUM] = x;
			adj[i].push_back(j+NUM);
			adj[j+NUM].push_back(i);
		}
	}
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=n; j++) {
			int x;
			cin >> x;
			d[i][j+NUM] = x;
			d[j+NUM][i] = -x;
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
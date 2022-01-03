#include <bits/stdc++.h>
#define X first
#define Y second
#define NUM 1000
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
int v, e, c[3*NUM][3*NUM], f[3*NUM][3*NUM], src = 2001, sink = 2002;
vector<pii> adj[3*NUM];

void bfs() {
	int cost = 0;
	while(true) {
		int prev[3*NUM], dist[3*NUM], edge[3*NUM];
		bool isq[3*NUM];
		memset(prev, -1, sizeof(prev));
		memset(edge, 0, sizeof(edge));
		fill(dist, dist+(3*NUM), INF);
		memset(isq, false, sizeof(isq));
		queue<int> q;
		q.push(src);
		dist[src] = 0;
		isq[src] = true;
		while(!q.empty()) {
			int curr = q.front();
			q.pop();
			isq[curr] = false;
			for(auto next : adj[curr]) {
				if(c[curr][next.X] - f[curr][next.X] > 0 && dist[next.X] > dist[curr] + next.Y) {
					dist[next.X] = dist[curr] + next.Y;
					prev[next.X] = curr;
					edge[next.X] = next.Y;
					if(!isq[next.X]) {
						isq[next.X] = true;
						q.push(next.X);
					}
				}
			}	
		}
		if(prev[sink] == -1) break;
		int flow = INF;
		for(int i=sink; i!=1; i=prev[i]) flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
		for(int i=sink; i!=1; i=prev[i]) {
			cost += flow * edge[i];
			f[prev[i]][i]++;
			f[i][prev[i]]--;
		}
	}
	cout << cost << '\n';
}

void init() {
	while(cin >> v >> e) {
		memset(c, 0, sizeof(c));
		memset(f, 0, sizeof(f));
		for(int i=0; i<3*NUM; i++) adj[i].clear();
		for(int i=1; i<=v; i++) {
			adj[i].push_back({i+NUM, 0}), adj[i+NUM].push_back({i, 0});
			c[i][i+NUM] = 1;
			if(i == 1 || i == v) c[i][i+NUM] = 2;
		}
		for(int i=0; i<e; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			adj[x+NUM].push_back({y, z});
			adj[y].push_back({x+NUM, -z});
			c[x+NUM][y] = 1;
		}
		c[v+NUM][sink] = 2;
		c[src][1] = 2;
		adj[src].push_back({1, 0}), adj[1].push_back({src, 0});
		adj[v+NUM].push_back({sink, 0}), adj[sink].push_back({v+NUM, 0});
		bfs();
	}

}		

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
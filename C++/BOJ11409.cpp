#include <bits/stdc++.h>
#define X first
#define Y second
#define NUM 1010
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
int n, m, c[NUM+10][NUM+10], f[NUM+10][NUM+10], d[NUM+10][NUM+10], src = NUM+1, sink = NUM+2;
vector<int> adj[NUM+10];

void bfs() {
	int cost = 0, cnt = 0;
	while(true) {
		int prev[NUM+10], dist[NUM+10];
		bool isq[NUM+10];
		queue<int> q;
		memset(dist, 0x7f7f7f7f, sizeof(dist));
		memset(prev, -1, sizeof(prev));
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
					isq[next] = true;
					q.push(next);
				}
			}
		}
		if(prev[sink] == -1) break;
		for(int i=sink; i!=src; i=prev[i]) {
			if(i == 0) break;
			cost += d[prev[i]][i];
			f[prev[i]][i]++;
			f[i][prev[i]]--;
		}
		cnt++;
	}
	cout << cnt << '\n' << -cost << '\n';
}

void init() {
	memset(c, 0, sizeof(c));
	memset(f, 0, sizeof(f));
	memset(d, 0, sizeof(d));
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		int x;
		cin >> x;
		while(x--) {
			int y, z;
			cin >> y >> z;
			adj[i].push_back(y+400);
			adj[y+400].push_back(i);
			d[i][y+400] = -z;
			d[y+400][i] = z;
			c[i][y+400] = 1;
			if(!c[y+400][sink]) {
				c[y+400][sink] = 1;
				adj[y+400].push_back(sink);
				adj[sink].push_back(y+400);
			}
		}	
		adj[src].push_back(i);
		adj[i].push_back(src);
		c[src][i] = 1;
	}
	bfs();

}		

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
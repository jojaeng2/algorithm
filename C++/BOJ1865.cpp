#include <bits/stdc++.h>
#define X first
#define Y second
#define NUM 510
#define INF 2000000000
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
int n, m, t, k;
bool vis[NUM];
ll dist[NUM];
vector<pii> adj[NUM];

void init() {
	cin >> t;
	while(t--) {
		bool flag = false;
		memset(vis, false, sizeof(vis));
		fill(dist, dist + NUM, INF);
		for(int i=0; i<510; i++) adj[i].clear();
		cin >> n >> m >> k;
		for(int i=0; i<m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			adj[a].push_back({b, c});
			adj[b].push_back({a, c});
		}
		for(int i=0; i<k; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			adj[a].push_back({b, -c});
		}
		for(int i=0; i<n; i++) {
			for(int j=1; j<=n; j++) {
				if(!vis[j]) {
					vis[j] = true;
					dist[j] = 0;
				}
				for(auto curr : adj[j]) {
					int next = curr.X, d = curr.Y;
					if((dist[j] != INF) && dist[next] > dist[j] + (ll)d) {
						dist[next] = dist[j] + (ll)d;
						vis[next] = true;
						if(i == n-1) flag = true;
					}
				}
			}
		}
		if(flag) cout << "YES" << '\n';
		else {
			cout << "NO" << '\n';
		}
	}
}		

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
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
#define NUM 310
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
int t, n, m, c[NUM][NUM], f[NUM][NUM];
vector<pii> adj[NUM];

void bfs() {
	while(true) {
		int prev[NUM];
		memset(prev, -1, sizeof(prev));
		queue<int> q;
		q.push(1);
		while(!q.empty() && prev[n] == -1) {
			int curr = q.front();
			q.pop();
			for(auto next : adj[curr]) {
				if(c[curr][next.X] - f[curr][next.X] > 0 && prev[next.X] == -1) {
					q.push(next.X);
					prev[next.X] = curr;
					if(next.X == n) break;
				}
			}
		}
		if(prev[n] == -1) break;
		int flow = INF;
		for(int i=n; i!=1; i=prev[i]) flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
		for(int i=n; i!=1; i=prev[i]) {
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}
	}
}

void init() {
	cin >> t;
	while(t--) {
		memset(c, 0, sizeof(c));
		memset(f, 0, sizeof(f));
		for(int i=0; i<NUM; i++) adj[i].clear();
		cin >> n >> m;
		for(int i=0; i<m; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			adj[x].push_back({y, z});
			adj[y].push_back({x, 0});
			c[x][y] += z;
		}
		bfs();
		int cnt = 0;
		for(int i=1; i<=n; i++) {
			for(auto j : adj[i]) {
				if(j.Y == 0 || c[i][j.X] != f[i][j.X]) continue;
				int prev[NUM];
				memset(prev, -1, sizeof(prev));
				queue<int> q;
				q.push(i);
				while(!q.empty() && prev[j.X] == -1) {
					int curr = q.front();
					q.pop();
					for(auto next : adj[curr]) {
						if(curr == i && next.X == j.X) continue;
						if(c[curr][next.X] - f[curr][next.X] > 0 && prev[next.X] == -1) {
							prev[next.X] = curr;
							q.push(next.X);
							if(next.X == j.X) break;
						}
					}						
				}
				if(prev[j.X] == -1) cnt++; 
			}
		}
		cout << cnt << '\n';
	}
}		

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
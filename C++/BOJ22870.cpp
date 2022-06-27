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
#define NUM 200010
#define INF 2000000000
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
int n, m, par[NUM], st, en;
ll visit[NUM], answer = 0;
bool node[NUM];
vector<pii> adj[NUM];

void dijkstra(int s) {
    priority_queue<pll> pq;
    visit[s] = 0;
    pq.push({0, (ll)s});
    while(!pq.empty()) {
        ll dist = -pq.top().X, curr = pq.top().Y;
        pq.pop();
        if(visit[curr] < dist) continue;
		if(node[curr]) continue;
        for(auto next : adj[curr]) {
            if(visit[next.X] == dist + (ll) next.Y) {
                par[next.X] = min(par[next.X], (int)curr);
            }
            else if(visit[next.X] > dist + (ll)next.Y) {
				par[next.X] = curr;
				visit[next.X] = dist + (ll) next.Y;
				pq.push({-visit[next.X], next.X});
			}
        }
    }
}

void dfs(int s) {
	if(s == st) return;
	node[s] = true;
	dfs(par[s]);
}

void init() {
    memset(node, false, sizeof(node));
    cin >> n >> m;
    for(int i=1; i<=n; i++) par[i] = NUM, visit[i] = INF;
    for(int i=0; i<m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
		adj[y].push_back({x, z});
    }
    cin >> st >> en;
    dijkstra(en);
	answer += visit[st];
	dfs(en);
	for(int i=0; i<=n; i++) visit[i] = INF;
	dijkstra(st);
	answer += visit[en];
	cout << answer << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
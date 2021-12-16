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
int n, graph[51][51], l = 0, r = 0, answer = 1e9, dfsn[51], sccn[51], cnt, sccnt;
bool visit[51];
vector<int> adj[51];
stack<int> stak;

int dfs(int s) {
	dfsn[s] = cnt++;
	int res = dfsn[s];
	stak.push(res);
	for(auto next : adj[s]) {
		if(!dfsn[next]) res = min(res, dfs(next));
		else if(!visit[next]) res = min(res, dfsn[next]);
	}
	if(res == dfsn[s]) {
		while(!stak.empty()) {
			int t = stak.top();
			stak.pop();
			visit[t] = true;
			sccn[t] = sccnt;
			if(t == s) break;
		}
		sccnt++;
	}
	return res;
}

void init() {
	cin >> n;
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin >> graph[i][j];
	while(l <= r && r <= 150000) {
		for(int i=1; i<=n; i++) adj[i].clear();
		memset(dfsn, 0, sizeof(dfsn));
		memset(visit, false, sizeof(visit));
		memset(sccn, 0, sizeof(sccn));
		while(!stak.empty()) stak.pop();
		cnt = 1, sccnt = 1;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(i == j) continue;
				if(l <= graph[i][j] && graph[i][j] <= r) {
					adj[i].push_back(j);
				}
			}
		}
		for(int i=1; i<=n; i++) if(!dfsn[i]) dfs(i);
		bool flag = false;
		for(int i=1; i<=n; i++) if(sccn[1] != sccn[i]) flag = true;
		if(!flag) {
			answer = min(answer, r-l);
			l++;
		}
		else r++;
	}
	cout << answer << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
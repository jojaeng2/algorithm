#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> pii;
int n, m, visit[1010], par[1010], in[1010];
queue<pii> q;
vector<pii> graph[1010];
vector<int> ans;

void print() {
	cout << visit[1] << '\n';
	ans.push_back(1);
	for(int i=par[1]; i!=1; i=par[i]) ans.push_back(i);
	ans.push_back(1);
	for(int i=ans.size()-1; i>=0; i--) cout << ans[i] << " ";
}

void topo() {
	visit[1] = 0;
	q.push(make_pair(1, 0));
	while(!q.empty()) {
		int now = q.front().X, dist = q.front().Y;
		q.pop();
		for(int i=0; i<graph[now].size(); i++) {
			int next = graph[now][i].X, cost = dist + graph[now][i].Y;
			if(visit[next] < cost) {
				par[next] = now;
				visit[next] = cost;
			}
			if(--in[next] == 0) {
				if(next != 1) q.push(make_pair(next, visit[next]));
			}
		}
	}
}

void init() {
	memset(visit, -1, sizeof(visit));
	memset(par, -1, sizeof(par));
	memset(in, 0, sizeof(in));
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		graph[x].push_back(make_pair(y, d));
		in[y]++;
	}
	topo();
	print();
}

int main() {
	init();
}
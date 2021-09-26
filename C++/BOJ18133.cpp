#include <iostream>
#include <stack>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int n, m, sccn[100010], dfsn[100010], in[100010], cnt=1, sccnt=1, answer = 0;
bool visit[100010];
vector<int> graph[100010];
stack<int> stak;

void indegree() {
	for(int i=1; i<=n; i++) {
		for(int j=0; j<graph[i].size(); j++) {
			int next = graph[i][j];
			if(sccn[i] != sccn[next]) in[sccn[next]]++;
		}
	}
	for(int i=1; i<sccnt; i++) if(!in[i]) answer++;
	cout << answer << '\n';
}

int dfs(int s) {
	dfsn[s] = cnt++;
	int res = dfsn[s];
	stak.push(s);
	for(int i=0; i<graph[s].size(); i++) {
		int next = graph[s][i];
		if(!dfsn[next]) res = min(res, dfs(next));
		else if(!visit[next]) res = min(res, dfsn[next]);
	}
	if(res == dfsn[s]) {
		while(true) {
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
	memset(sccn, 0, sizeof(sccn));
	memset(dfsn, 0, sizeof(dfsn));
	memset(visit, false, sizeof(visit));
	memset(in, 0, sizeof(in));
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
	}
	for(int i=1; i<=n; i++) if(!dfsn[i]) dfs(i);
	indegree();
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
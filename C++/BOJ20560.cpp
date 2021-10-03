#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#define X first
#define Y second
#define NUM 500010
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int in[NUM], dfsn[NUM], sccn[NUM], cnt = 1, sccnt = 1, n, m, ndp[NUM], edp[NUM], node[NUM], e[NUM];
bool visit[NUM];
vector<int> graph[NUM], sgraph[NUM];
stack<int> st;

void print() {
	bool a = true, b = true;
	int nmax = 0, emax = 0;
	for(int i=1; i<sccnt; i++) {
		nmax = max(nmax, ndp[i]);
		emax = max(emax, edp[i]);
	}
	if(nmax != n) a = false;
	if(emax != m) b = false;
	cout << a << '\n' << b << '\n';
	if(a && b) cout << true << '\n';
	else cout << false << '\n';
}

void topo() {
	queue<int> q;
	q.push(0);
	ndp[0] = 0;
	edp[0] = -1;
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		for(int i=0; i<sgraph[now].size(); i++) {
			int next = sgraph[now][i];
			ndp[next] = max(ndp[next], ndp[now]+node[next]);
			edp[next] = max(edp[next], edp[now]+e[next]+1);
			in[next]--;
			if(!in[next]) {
				q.push(next);
			}
		}
	}
}

void indegree() {
	for(int i=1; i<=n; i++) {
		node[sccn[i]]++;
		for(int j=0; j<graph[i].size(); j++) {
			int next = graph[i][j];
			if(sccn[i] != sccn[next]) {
				sgraph[sccn[i]].push_back(sccn[next]);
				in[sccn[next]]++;
			}
			else e[sccn[next]]++;
		}
	}
	for(int i=1; i<sccnt; i++) {
		if(!in[i]) {
			sgraph[0].push_back(i);
			in[i]++;
		}
	}
}

int dfs(int s) {
	dfsn[s] = cnt++;
	int res = dfsn[s];
	st.push(s);
	for(int i=0; i<graph[s].size(); i++) {
		int next = graph[s][i];
		if(!dfsn[next]) res = min(res, dfs(next));
		else if(!visit[next]) res = min(res, dfsn[next]);
	}
	if(dfsn[s] == res) {
		while(!st.empty()) {
			int t = st.top();
			st.pop();
			visit[t] = true;
			sccn[t] = sccnt;
			if(t == s) break;
		}
		sccnt++;
	}
	return res;
}

void init() {
	memset(in, 0, sizeof(in));
	memset(dfsn, 0, sizeof(dfsn));
	memset(visit, false, sizeof(visit));
	memset(sccn, 0, sizeof(sccn));
	memset(ndp, 0, sizeof(ndp));
	memset(edp, 0, sizeof(edp));
	memset(node, 0, sizeof(node));
	memset(e, 0, sizeof(e));
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		if(x == y) continue;
		graph[x].push_back(y);
	}
	for(int i=1; i<=n; i++) if(!dfsn[i]) dfs(i);
	
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
	indegree();
	topo();
	print();
}

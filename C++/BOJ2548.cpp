#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> graph[501];
bool visit[501][501];
bool node[501];
void count() {
	int cnt = 0;
	for(int i=1; i<=n; i++) {
		bool flag = false;
		for(int j=1; j<=n; j++) {
			if(!visit[i][j] && !visit[j][i]) {
				flag = true;
				break;
			}
		}
		if(!flag) cnt++;
	}
	cout << cnt << '\n';
}

void dfs(int start, int now) {
	visit[start][now] = true;
	cout << start << " " << now << '\n';
	for(int i=0; i<graph[now].size(); i++) {
		int next = graph[now][i];
		if(node[next]) continue;
		node[next] = true;
		dfs(start, next);
	}
}

void init() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}
	for(int i=1; i<=n; i++) {
		fill(node, node+501, false);
		node[i] = true;
		dfs(i, i);
	}
}

int main() {
	init();
	count();
}
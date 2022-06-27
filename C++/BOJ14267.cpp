#include <iostream>
#include <vector>
using namespace std;

int n, m, score[100001], prefix[100001];
vector<int> graph[100001];

void dfs(int start, int cnt) {
	score[start] += cnt;
	for(int i=0; i<graph[start].size(); i++) {
		int next = graph[start][i];
		dfs(next, cnt);
	}
}

void print() {
	for(int i=1; i<=n; i++) {
		if(prefix[i] != 0) dfs(i, prefix[i]);
	}
	for(int i=1; i<=n; i++) {
		cout << score[i] << ' ';
	}
	cout << '\n';
}


void init() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fill(score, score+100001, 0);
	fill(score, score+100001, 0);
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		int par;
		cin >> par;
		if(par==-1) continue;
		graph[par].push_back(i);
	}
	for(int i=0; i<m; i++) {
		int node, num;
		cin >> node >> num;
		prefix[node] += num;
	}
}

int main() {
	init();
	print();
}
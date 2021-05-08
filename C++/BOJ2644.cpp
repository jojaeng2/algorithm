#include <iostream>
#include <vector>
using namespace std;
vector<int> parent[101];
int n, m, a, b, ans = -1;
bool visit[101];
void dfs(int now, int cnt) {
	visit[now] = true;
	if(now == b) {
		ans = cnt;
		return;
	}
	for(int i=0;i<parent[now].size();i++) {
		int next = parent[now][i];
		if(visit[next]) continue;
		dfs(next,cnt+1);
	}
}

int main(){
	cin >> n >> a >> b >> m;
	for(int i=1;i<=m;i++) {
		int x, y;
		cin >> x >> y;
		parent[x].push_back(y);
		parent[y].push_back(x);
	}
	dfs(a,0);
	cout << ans << '\n';
}
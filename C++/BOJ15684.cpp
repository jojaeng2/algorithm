#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,h,ans=987654321;
bool visit[11][31][2];

bool solve(){
	for(int i=1;i<=n;i++){
		int line = i;
		for(int j=1;j<=h;j++){
			if(visit[line][j][0]) line -= 1;
			else if(visit[line][j][1]) line += 1;
		}
		if(line!=i) return false;
	}
	return true;
}

void dfs(int cnt,int column){
	if(solve()){
		ans = min(ans,cnt);
		return;
	}
	if(cnt==3) return;
	for(int i=1;i<n;i++){
		for(int j=column+1;j<=h;j++){
			bool goal = visit[i][j][1];
			bool left = visit[i][j][0];
			bool right = visit[i+1][j][0];
			if(goal || left || right) continue;
			visit[i][j][1] = true;
			visit[i+1][j][0] = true;
			cout << column << " " << i << '\n';
			dfs(cnt+1,j);
			visit[i][j][1] = false;
			visit[i+1][j][0] = false;
		}
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> h;
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		visit[b][a][1] = true;
		visit[b+1][a][0] = true;
	}
	dfs(0,1);
	if(ans==987654321) ans = -1;
	cout << ans << '\n';
}
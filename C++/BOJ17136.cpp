#include <iostream>
#include <vector>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;
int graph[11][11], paper[6] = {0}, ans = 100;
vector<pii> v;
bool finded = false;

void dfs(int cnt) {
	if(cnt == v.size()){
		int a = 0;
		for(int i=1;i<=5;i++) {
			a += paper[i];
		}
		ans = min(ans,a);
		return;
	}
	int x = v[cnt].X, y = v[cnt].Y;
	if(graph[x][y] == 0) {
		dfs(cnt+1);
		return;
	}
	for(int i=1;i<=5;i++) {
		int nx = x + i - 1, ny = y + i - 1;
		if(nx>10 || ny>10 || paper[i] == 5) continue;
		bool flag = false;
		for(int j=x;j<=nx;j++) {
			if(flag) break;
			for(int p=y;p<=ny;p++) {
				if(graph[j][p] == 0) {
					flag = true;
					break;
				}
			}
		}
		if(!flag) {
			paper[i]++;
			for(int j=x;j<=nx;j++) for(int p=y;p<=ny;p++) graph[j][p] = 0;
			dfs(cnt+1);
			for(int j=x;j<=nx;j++) for(int p=y;p<=ny;p++) graph[j][p] = 1;
			paper[i]--;
		}
	}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=1;i<=10;i++) for(int j=1;j<=10;j++) {
		cin >> graph[i][j];
		if(graph[i][j] == 1) v.push_back({i,j});
	}
	dfs(0);
	if(ans==100) ans = -1;
	cout << ans << '\n';
}
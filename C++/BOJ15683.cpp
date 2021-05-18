#include <iostream>
#include <queue>
#include <vector>
#define X first
#define Y second
using namespace std;
typedef pair<pair<int,int>, int> pii;
struct cctvs{
	int num, x, y;
};
vector<cctvs> v;
int n, m, graph[9][9], dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1}, mini = 100;
bool visit[9][9];

void find_min() {
	int cnt = 0;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(!visit[i][j] && graph[i][j] != 6) cnt++;
		}
	}
	mini = min(cnt, mini);
}

void dfs(int cnt) {
	bool cp_visit[9][9];
	for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cp_visit[i][j] = visit[i][j];
	if(cnt==v.size()) {
		find_min();
		return;
	}
	for(int i=cnt; i<=v.size(); i++) {
		int num = v[i].num, x = v[i].x, y = v[i].y;
		if(num==1) {
			for(int j=0; j<4; j++) {
				queue<pii> q;
				q.push({{x+dx[j], y+dy[j]}, j});
				while(!q.empty()) {
					int nx = q.front().X.X, ny = q.front().X.Y, dir = q.front().Y;
					q.pop();
					if(nx<1 || nx>n || ny<1 || ny>m || graph[nx][ny] == 6) continue;
					visit[nx][ny] = true;
					q.push({{nx+dx[dir],ny+dy[dir]},dir});
				}
				dfs(cnt+1);
				for(int k=1; k<=n; k++) for(int p=1; p<=m; p++) visit[k][p] = cp_visit[k][p];
			}
			return;
		}
		else if(num==2) {
			for(int j=0; j<2; j++) {
				queue<pii> q;
				if(j==0) {
					q.push({{x+dx[0],y+dy[0]},0});
					q.push({{x+dx[1],y+dy[1]},1});
				}
				else {
					q.push({{x+dx[2],y+dy[2]},2});
					q.push({{x+dx[3],y+dy[3]},3});
				}
				while(!q.empty()) {
					int nx = q.front().X.X, ny = q.front().X.Y, dir = q.front().Y;
					q.pop();
					if(nx<1 || nx>n || ny<1 || ny>m || graph[nx][ny] == 6) continue;
					visit[nx][ny] = true;
					q.push({{nx+dx[dir],ny+dy[dir]},dir});
				}
				dfs(cnt+1);
				for(int k=1; k<=n; k++) for(int p=1; p<=m; p++) visit[k][p] = cp_visit[k][p];
			}
			return;
		}
		else if(num==3) {
			for(int j=0; j<4; j++) {
				queue<pii> q;
				if(j==0) {
					q.push({{x+dx[0],y+dy[0]},0});
					q.push({{x+dx[2],y+dy[2]},2});
				}
				else if(j==1) {
					q.push({{x+dx[0],y+dy[0]},0});
					q.push({{x+dx[3],y+dy[3]},3});
				}
				else if(j==2) {
					q.push({{x+dx[1],y+dy[1]},1});
					q.push({{x+dx[2],y+dy[2]},2});
				}
				else {
					q.push({{x+dx[1],y+dy[1]},1});
					q.push({{x+dx[3],y+dy[3]},3});
				}
				while(!q.empty()) {
					int nx = q.front().X.X, ny = q.front().X.Y, dir = q.front().Y;
					q.pop();
					if(nx<1 || nx>n || ny<1 || ny>m || graph[nx][ny] == 6) continue;
					visit[nx][ny] = true;
					q.push({{nx+dx[dir],ny+dy[dir]},dir});
				}
				dfs(cnt+1);
				for(int k=1; k<=n; k++) for(int p=1; p<=m; p++) visit[k][p] = cp_visit[k][p];
			}
			return;

		}
		else if(num==4) {
			for(int j=0; j<4; j++) {
				queue<pii> q;
				if(j==0) {
					q.push({{x+dx[0],y+dy[0]},0});
					q.push({{x+dx[1],y+dy[1]},1});
					q.push({{x+dx[2],y+dy[2]},2});
				}
				else if(j==1) {
					q.push({{x+dx[0],y+dy[0]},0});
					q.push({{x+dx[1],y+dy[1]},1});
					q.push({{x+dx[3],y+dy[3]},3});
				}
				else if(j==2) {
					q.push({{x+dx[0],y+dy[0]},0});
					q.push({{x+dx[3],y+dy[3]},3});
					q.push({{x+dx[2],y+dy[2]},2});
				}
				else {
					q.push({{x+dx[1],y+dy[1]},1});
					q.push({{x+dx[3],y+dy[3]},3});
					q.push({{x+dx[2],y+dy[2]},2});
				}
				while(!q.empty()) {
					int nx = q.front().X.X, ny = q.front().X.Y, dir = q.front().Y;
					q.pop();
					if(nx<1 || nx>n || ny<1 || ny>m || graph[nx][ny] == 6) continue;
					visit[nx][ny] = true;
					q.push({{nx+dx[dir],ny+dy[dir]},dir});
				}
				dfs(cnt+1);
				for(int k=1; k<=n; k++) for(int p=1; p<=m; p++) visit[k][p] = cp_visit[k][p];
			}
			return;
		}
		else {
			queue<pii> q;
			q.push({{x+dx[0],y+dy[0]},0});
			q.push({{x+dx[1],y+dy[1]},1});
			q.push({{x+dx[2],y+dy[2]},2});
			q.push({{x+dx[3],y+dy[3]},3});
			while(!q.empty()) {
				int nx = q.front().X.X, ny = q.front().X.Y, dir = q.front().Y;
				q.pop();
				if(nx<1 || nx>n || ny<1 || ny>m || graph[nx][ny] == 6) continue;
				visit[nx][ny] = true;
				q.push({{nx+dx[dir],ny+dy[dir]},dir});
			}
			dfs(cnt+1);
			for(int k=1; k<=n; k++) for(int p=1; p<=m; p++) visit[k][p] = cp_visit[k][p];
			return;
		}
	}
}

void init() {
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> graph[i][j];
            if(graph[i][j] != 0 && graph[i][j] != 6) {
				visit[i][j] = true;
				cctvs cctv;
				cctv.num = graph[i][j], cctv.x = i, cctv.y = j;
				v.push_back(cctv);
            }
        }
    }
}

int main() {
	init();
	dfs(0);
	cout << mini << '\n';
}
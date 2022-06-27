#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;
struct robots {
	int a, b, length;
};
int n, m, dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1}, graph_node[51][51], visit[51][51], par[251], answer = 0;
char graph[51][51];
vector<pii> node;
vector<robots> connect;

void print() {
	int cnt = 0;
	for(int i=0; i<=m; i++) {
		if(par[i] == i) cnt++;
	}
	if(cnt > 1) answer = -1;
	cout <<  answer << '\n';
}


int find(int start) {
	if(start == par[start]) return start;
	return par[start] = find(par[start]);
}

bool uni(int a, int b) {
	int aa = find(a), bb = find(b);
	if(aa == bb) return false;
	par[bb] = aa;
	return true;
}

void kruscal() {
	for(int i=0; i<=m; i++) par[i] = i;
	for(int i=0; i<connect.size(); i++) {
		int x = connect[i].a, y = connect[i].b, length = connect[i].length;
		if(uni(x, y)) answer += length;
	}
}

bool compare(robots a, robots b) {
	return a.length < b.length;
}

void bfs(int s_x, int s_y) {
	memset(visit, 0, sizeof(visit));
	queue<pii> q;
	q.push(make_pair(s_x, s_y));
	visit[s_x][s_y] = 1;
	while(!q.empty()) {
		int x = q.front().X, y = q.front().Y;
		q.pop();
		for(int i=0; i<4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if(nx<0 || nx>=n || ny<0 || ny>=n || visit[nx][ny] != 0 || graph[nx][ny] == '1') continue;
			visit[nx][ny] = visit[x][y] + 1;
			q.push(make_pair(nx, ny));
			if(graph[nx][ny] == 'S' || graph[nx][ny] == 'K') {
				robots robot;
				robot.a = graph_node[s_x][s_y];
				robot.b = graph_node[nx][ny];
				robot.length = visit[nx][ny] - 1;
				connect.push_back(robot);
			}
		}
	}
}

void init() {
	cin >> n >> m;
	int cnt = 0;
	for(int i=0; i<n; i++) {
		string s;
		cin >> s;
		for(int j=0; j<n; j++) {
			graph[i][j] = s[j];
			if(graph[i][j] == 'S' || graph[i][j] == 'K') {
				graph_node[i][j] = cnt;
				cnt++;
				node.push_back(make_pair(i, j));
			}
		}
	}
	for(int i=0; i<node.size(); i++) {
		int x = node[i].X, y = node[i].Y;
		bfs(x, y);
	}
	sort(connect.begin(), connect.end(), compare);
}

int main() {
	init();
	kruscal();
	print();
}
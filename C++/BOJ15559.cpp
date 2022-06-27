#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <vector>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> pii;
int n, m, cnt = 0, visit[1001][1001], answer = 0, par[10000001];
char graph[1001][1001];
vector<int> conn[1000001];

void print() {
    for(int i=1; i<=cnt; i++) {
        if(par[i] == i) answer++;
    }
    cout << answer << '\n';
}

int find(int start) {
    if(start == par[start]) return start;
    return par[start] = find(par[start]);
}

void uni(int x, int y) {
    int xx = find(x), yy = find(y);
    if(xx < yy) par[yy] = xx;
    else par[xx] = yy;
}

void dfs(int sx, int sy) {
    stack<pii> s;
    s.push(make_pair(sx, sy));
    visit[sx][sy] = cnt;
    while(!s.empty()) {
        int x = s.top().X, y = s.top().Y;
        s.pop();
        int nx = x, ny = y;
        if(graph[x][y] == 'S') nx++;
        if(graph[x][y] == 'W') ny--;
        if(graph[x][y] == 'E') ny++;
        if(graph[x][y] == 'N') nx--;
        if(nx<1 || ny<1 || nx>n || ny>m) continue;
        if(visit[nx][ny] == -1) {
            visit[nx][ny] = cnt;
            s.push(make_pair(nx, ny));
        } 
        else {
            if(visit[nx][ny] == visit[x][y]) continue;
            conn[visit[nx][ny]].push_back(visit[x][y]);
        }
    }
}

void init() {
    memset(visit, -1, sizeof(visit));
    cin >> n >> m;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin >> graph[i][j];
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(visit[i][j] != -1) continue;
            cnt++;
            dfs(i, j);
        }
    }
    for(int i=0; i<=10000000; i++) par[i] = i;
    for(int i=1; i<=cnt; i++) {
        int now = i;
        for(int j=0; j<conn[i].size(); j++) {
            int next = conn[i][j];
            uni(now, next);
        }
    }
}

int main() {
    init();
    print();
}
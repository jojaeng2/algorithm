#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> pii;
int n, m, dx[3] = {-1, 1, 0}, dy[3] = {1, 1, 1}, sx, sy, graph[1001][1001], visit[1001][1001], ans = -1;
queue<pii> q;

void bfs() {
    visit[q.front().X][q.front().Y] = 0;
    while(!q.empty()) {
        int x = q.front().X, y = q.front().Y;
        q.pop();
        if(graph[x][y] == 'O') ans = max(ans, visit[x][y]);
        for(int i=0; i<3; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx<1 || ny<1 || nx>n || ny>m || graph[nx][ny] == '#') continue;
            if(graph[nx][ny] == 'C') {
                if(visit[nx][ny] >= visit[x][y] + 1) continue;
                visit[nx][ny] = visit[x][y] + 1;
                q.push(make_pair(nx, ny));
            } 
            else {
                if(visit[nx][ny] >= visit[x][y]) continue;
                visit[nx][ny] = visit[x][y];
                q.push(make_pair(nx, ny));
            }
        }
    }
}

void init() {
    memset(visit, -1, sizeof(visit));
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        string s;
        cin >> s;
        for(int j=0; j<=m; j++) {
            graph[i][j+1] = s[j];
            if(graph[i][j+1] == 'R') q.push(make_pair(i, j+1));
        }
    }
    if(q.size() != 0) bfs();
}

int main() {
    init();
    cout << ans << '\n';
}
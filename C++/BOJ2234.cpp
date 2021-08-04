#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> pii;
int n, m, graph[51][51], cnt = 0, dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0}, maxi = 0, crush = 0, visit[51][51], psum[2501];
queue<pii> q;

void print() {
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            maxi = max(maxi, psum[visit[i][j]]);
            for(int k=0; k<4; k++) {
                int nx = i + dx[k], ny = j + dy[k];
                if(nx < 1 || ny < 1 || nx > m || ny > n) continue;
                if(visit[i][j] == visit[nx][ny]) continue;
                crush = max(crush, psum[visit[i][j]] + psum[visit[nx][ny]]);
            }
        }
    }
    cout << cnt << '\n' << maxi << '\n' << crush << '\n';
}

void bfs() {
    int now = 0;
    while(!q.empty()) {
        int x = q.front().X, y = q.front().Y;
        now++;
        psum[cnt] = max(psum[cnt], now);
        q.pop();
        for(int i=0; i<4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 1 || ny < 1 || nx > m || ny > n || visit[nx][ny] != 0 || ((graph[x][y] & (1<<i)) != 0)) continue;
            visit[nx][ny] = cnt;
            q.push(make_pair(nx, ny));
        }
    }
}

void init() {
    memset(graph, 0, sizeof(graph));
    memset(visit, 0, sizeof(visit));
    memset(psum, 0, sizeof(psum));
    cin >> n >> m;
    for(int i=1; i<=m; i++) for(int j=1; j<=n; j++) cin >> graph[i][j];
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(visit[i][j] != 0) continue;
            q.push(make_pair(i, j));
            cnt++;
            visit[i][j] = cnt;
            bfs();
        }
    }
}

int main() {
    init();
    print();
}
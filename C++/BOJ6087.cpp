#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> pii;
struct st {
    int x, y, dir;
};
int n, m, graph[101][101], visit[4][101][101], dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
vector<pii> pos;

void print() {
    int answer = 1e9;
    for(int i=0; i<4; i++) {
        answer = min(answer, visit[i][pos[1].X][pos[1].Y]);
    }
    cout << answer << '\n';
}

void bfs() {
    queue<st> q;
    for(int i=0; i<4; i++) {
        st s;
        s.x = pos[0].X, s.y = pos[0].Y;
        visit[i][s.x][s.y] = 0;
        int nx = s.x + dx[i], ny = s.y + dy[i];
        if(nx < 1 || ny < 1 || nx > m || ny > n || graph[nx][ny] == -1) continue;
        visit[i][nx][ny] = 0;
        s.x = nx, s.y = ny, s.dir = i;
        q.push(s);
    }
    while(!q.empty()) {
        st now = q.front();
        q.pop();
        for(int i=0; i<4; i++) {
            int nx = now.x + dx[i], ny = now.y + dy[i], ndir = now.dir;
            if(nx < 1 || ny < 1 || nx > m || ny > n || graph[nx][ny] == -1) continue;
            st next;
            next.x = nx, next.y = ny;
            if(ndir == i && visit[i][nx][ny] > visit[ndir][now.x][now.y]) {
                visit[i][nx][ny] = visit[ndir][now.x][now.y];
                next.dir = i;
                q.push(next);
            } 
            else if(ndir != i && visit[i][nx][ny] > visit[ndir][now.x][now.y] + 1) {
                visit[i][nx][ny] = visit[ndir][now.x][now.y] + 1;
                next.dir = i;
                q.push(next);
            }
        }
    }
}

void init() {
    memset(graph, 0, sizeof(graph));
    for(int i=0; i<4; i++) for(int j=0; j<=100; j++) for(int k=0; k<=100; k++) visit[i][j][k] = 1e9;
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        string s;
        cin >> s;
        for(int j=0; j<n; j++) {
            if(s[j] == '.') graph[i][j+1] = 0;
            else if(s[j] == '*') graph[i][j+1] = -1;
            else graph[i][j+1] = 1;
        }
    }
    for(int i=1; i<=m; i++) for(int j=1; j<=n; j++) if(graph[i][j] == 1) {
        pos.push_back(make_pair(i, j));
    }
}

int main() {
    init();
    bfs();
    print();
}
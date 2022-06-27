#include <iostream>
#include <queue>
#include <string>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> pii;
int n, m, graph[251][251], a, b, apsum = 0, bpsum = 0, dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
bool visit[251][251] = {false};
queue<pii> q;

void bfs() {
    while(!q.empty()) {
        int x = q.front().X, y = q.front().Y;
        q.pop();
        for(int i=0; i<4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx<1 || ny<1 || nx>n || ny>m || visit[nx][ny] || graph[nx][ny] == '#') continue;
            if(graph[nx][ny] == 'v') a++;
            if(graph[nx][ny] == 'k') b++;
            visit[nx][ny] = true;
            q.push(make_pair(nx, ny));
        }
    }
}


void init() {
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        string s;
        cin >> s;
        for(int j=0; j<m; j++) {
            graph[i][j+1] = s[j];
        }
    }
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) {
        if(graph[i][j] != '#' && !visit[i][j]) {
            a = 0, b = 0;
            q.push(make_pair(i, j));
            visit[i][j] = true;
            if(graph[i][j] == 'v') a++;
            if(graph[i][j] == 'k') b++;
            bfs();
            if(a>=b) apsum += a;
            else bpsum += b;
        }
    }
    cout << bpsum << " " << apsum << '\n';
}

int main() {
    init();
}
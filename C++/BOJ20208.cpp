#include <bits/stdc++.h>
#define MINF 0x7f7f7f7f7f7f7f
#define INF 1000000000
#define MOD 1000000007
#define NUM 100010
#define X first
#define Y second
using namespace std;
typedef pair<int, int> pii;
int N, M, H, sx, sy, cnt = 1, graph[11][11], answer = 0;
bool visited[11];
pii milk[11];

void dfs(int x, int y, int s, int e, int hp) {
    if(s == e) {
        if(hp - (abs(sx-x) + abs(sy-y)) >= 0) {
            answer = max(answer, e);
        }
        return;
    }
    for(int i=1; i<cnt; i++) {
        if(visited[i]) continue;
        int nx = milk[i].X, ny = milk[i].Y;
        if(hp - (abs(nx-x) + abs(ny-y)) < 0) continue;
        visited[i] = true;
        dfs(nx, ny, s+1, e, hp - (abs(nx-x) + abs(ny-y))+H);
        visited[i] = false; 
    }
}

void init() {   
    memset(graph, 0, sizeof(graph));
    memset(visited, false, sizeof(visited));
    cin >> N >> M >> H;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> graph[i][j];
            if(graph[i][j] == 1) sx = i, sy = j;
            if(graph[i][j] == 2) milk[cnt++] = {i, j};
        }
    }
    for(int i=1; i<cnt; i++) {
        dfs(sx, sy, 0, i, M);
    }
    cout << answer << '\n';

}


int main() {    
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
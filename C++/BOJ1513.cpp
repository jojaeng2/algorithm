#include <iostream>
#include <algorithm>
#include <cstring>
#define MOD 1000007
using namespace std;
int n, m, k, dp[51][51][51][51], graph[51][51];
int dx[2] = {0, 1}, dy[2] = {1, 0};

int dfs(int x, int y, int cnt, int e) {
    if(cnt < 0) return 0;
    if(x == n && y == m) {
        if(cnt == 0 && (graph[x][y] == 0 || graph[x][y] == e)) return 1;
        if(cnt == 1 && graph[x][y] > e) return 1;
        return 0;
    }
    if(dp[cnt][e][x][y] != -1) return dp[cnt][e][x][y];
    dp[cnt][e][x][y] = 0;
    for(int i=0; i<2; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx>n || ny>m) continue;
        if(graph[nx][ny] != 0 && e < graph[nx][ny]) dp[cnt][e][x][y] += dfs(nx, ny, cnt-1, graph[nx][ny]);
        if(graph[nx][ny] == 0) dp[cnt][e][x][y] += dfs(nx, ny, cnt, e);
    }
    return dp[cnt][e][x][y] % MOD;
}

void init() {
    memset(dp, -1, sizeof(dp));
    memset(graph, 0, sizeof(graph));
    cin >> n >> m >> k;
    for(int i=1; i<=k; i++) {
        int x, y;
        cin >> x >> y;
        graph[x][y] = i;
    }
    int s = 1;
    if(graph[1][1] == 0) s = 0;
    for(int i=0; i<=k; i++) {
        cout << dfs(1, 1, i-s, graph[1][1]) << ' ';
    }
    cout << '\n';
}

int main() {
    init();
}
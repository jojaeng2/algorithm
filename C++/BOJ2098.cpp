#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define INF 1e9
using namespace std;
int n, graph[17][17], dp[130000][17], mini = 1e9;

int dfs(int s, int psum, int e) {
    if(dp[psum][s] != -1) return dp[psum][s];
    if(psum == ((1<<n)-1)) {
        if(graph[s][e] == 0) return INF;
        else return graph[s][e];
    }
    dp[psum][s] = 0;
    int now = 1e9;
    for(int i=1; i<=n; i++) {
        if(((psum & (1<<(i-1))) != 0)) continue;
        if(graph[s][i] == 0) now = min(now, 1000000000);
        else now = min(now, graph[s][i] + dfs(i, (psum | (1<<(i-1))), e));
    }   
    dp[psum][s] += now;
    return dp[psum][s];
}

void init() {
    memset(graph, 0, sizeof(graph));
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin >> graph[i][j];
    cout << dfs(1, 1, 1) << '\n';
}

int main() {
    init();
}
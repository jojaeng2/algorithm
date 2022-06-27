#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> pii;
int t, n, m, dp[1001];
vector<pii> graph[1001];

int dfs(int s, int e) {
    if(dp[s] != -1) return dp[s];
    if(graph[s].size() == 1) return dp[s] = 1e9;
    dp[s] = 0;
    for(int i=0; i<graph[s].size(); i++) {
        int next = graph[s][i].X, cost = graph[s][i].Y;
        if(next == e) continue;
        dp[s] += min(cost, dfs(next, s));
    }
    return dp[s];
}

void init() {
    cin >> t;
    while(t--) {
        for(int i=0; i<1001; i++) graph[i].clear();
        memset(dp, -1, sizeof(dp));
        cin >> n >> m;
        for(int i=0; i<m; i++) {
            int x, y, d;
            cin >> x >> y >> d;
            graph[x].push_back(make_pair(y, d));
            graph[y].push_back(make_pair(x, d));
        }
        if(n == 1) cout << 0 << '\n';
        else cout << dfs(1, 0) << '\n';
    }
}

int main() {
    init();
}
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, h[5001], dp[5001];
vector<int> graph[5001];

int dfs(int s) {
    if(dp[s] != -1) return dp[s];
    dp[s] = 1;
    int now = 0;
    for(int i=0; i<graph[s].size(); i++) {
        int next = graph[s][i];
        now = max(now, dfs(next));
    }
    dp[s] += now;
    return dp[s];
}

void init() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> h[i];
    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        if(h[x] == h[y]) continue;
        else if(h[x]>h[y]) graph[y].push_back(x);
        else graph[x].push_back(y);
    }
    for(int i=1; i<=n; i++) {
        cout << dfs(i) << '\n';
    }
}

int main() {
    init();
}
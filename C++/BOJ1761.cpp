#include <iostream>
#include <vector>
#define NUM 40001
#define X first
#define Y second
#define LOG 20
using namespace std;
typedef pair<int, int> pii;
int n, m, depth[NUM], dp[NUM][LOG+10], dist[NUM][LOG+10];
vector<pii> graph[NUM];

int lca(int x, int y) {
    int cnt = 0;
    if(depth[x] < depth[y]) swap(x, y);
    for(int i=LOG-1; i>=0; i--) {
        if((depth[x] - depth[y]) >= (1<<i)) {
            cnt += dist[x][i];
            x = dp[x][i];
        }
    }
    if(x == y) return cnt;
    for(int i=LOG-1; i>=0; i--) {
        if(dp[x][i] != dp[y][i]) {
            cnt += (dist[x][i] + dist[y][i]);
            x = dp[x][i], y = dp[y][i];
        }
    }
    cnt += (dist[x][0] + dist[y][0]);
    return cnt;
}

void make_sparse() {
    for(int i=1; i<LOG; i++) {
        for(int j=1; j<=n; j++) {
            dist[j][i] = dist[j][i-1] + dist[dp[j][i-1]][i-1];
            dp[j][i] = dp[dp[j][i-1]][i-1];
        }
    }
}

void dfs(int s, int e) {
    for(int i=0; i<graph[s].size(); i++) {
        int next = graph[s][i].X, d = graph[s][i].Y;
        if(next == e) continue;
        depth[next] = depth[s]+1;
        dp[next][0] = s, dist[next][0] = d;
        dfs(next, s);
    }
}

void init() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=1; i<n; i++) {
        int s, e, d;
        cin >> s >> e >> d;
        graph[s].push_back(make_pair(e, d));
        graph[e].push_back(make_pair(s, d));
    }
    depth[1] = 0, dp[1][0] = 0, dist[1][0] = 0;
    dfs(1, 0);
    make_sparse();
    cin >> m;
    for(int i=0; i<m; i++) {
        int s, e; 
        cin >> s >> e;
        cout << lca(s, e) << '\n';
    }
}

int main() {
    init();
}
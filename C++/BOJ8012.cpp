#include <iostream>
#include <vector>
#define LOG 20
using namespace std;
int n, m, depth[30001], par[30001][LOG+10];
vector<int> graph[30001];

int lca(int x, int y) {
    if(depth[x] < depth[y]) swap(x, y);
    int cnt = 0;
    for(int i=LOG-1; i>=0; i--) {
        if((depth[x]-depth[y]) >= (1<<i)) {
            x = par[x][i];
            cnt += (1<<i);
        }
    }
    if(x == y) return cnt;
    for(int i=LOG-1; i>=0; i--) {
        if(par[x][i] == par[y][i]) continue;
        x = par[x][i], y = par[y][i];
        cnt += 2*(1<<i);
    }
    return cnt + 2;
}

void make_sparse() {
    for(int i=1; i<LOG; i++) {
        for(int j=1; j<=n; j++) {
            par[j][i] = par[par[j][i-1]][i-1];
        }
    }
}

void dfs(int s, int e) {
    for(int i=0; i<graph[s].size(); i++) {
        int next = graph[s][i];
        if(next == e) continue;
        depth[next] = depth[s] + 1;
        par[next][0] = s;
        dfs(next ,s);
    }
}

void init() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=1; i<n; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    depth[1] = 0, par[1][0] = 0;
    dfs(1, 0);
    make_sparse();
    cin >> m;
    int now = 1, ans = 0;
    for(int i=0; i<m; i++) {
        int x;
        cin >> x;
        if(now == x) continue;
        ans += lca(now, x);
        now = x;
    }
    cout << ans << '\n';
}

int main() {
    init();
}
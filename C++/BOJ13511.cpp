#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define LOG 20
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int n, m, depth[100010], par[LOG][100010], cnt[LOG][100010];
ll dp[LOG][100010];
vector<pii> graph[100010];

int finding(int s, int sum) {
    int psum = 0;
    for(int i=LOG-1; i>=0; i--) {
        if(psum + cnt[i][s] < sum) {
            psum += cnt[i][s];
            s = par[i][s];
        }
    }
    if(psum != sum) s = par[0][s];
    return s;
}

ll lca(int u, int v, int check) {
    ll cnt = 0;
    if(depth[u] < depth[v]) swap(u, v);
    for(int i=LOG-1; i>=0; i--) {
        if((depth[u] - depth[v]) >= (1<<i)) {
            cnt += dp[i][u];
            u = par[i][u];
        }
    }
    if(u == v) {
        if(check == 1) return cnt;
        else return u;
    }
    for(int i=LOG-1; i>=0; i--) {
        if(par[i][u] != par[i][v]) {
            cnt += (dp[i][u] + dp[i][v]);
            u = par[i][u], v = par[i][v];
        }
    }
    cnt += (dp[0][u] + dp[0][v]);
    if(check == 1) return cnt;
    else return par[0][u];
}

void make_sparse() {
    for(int i=1; i<LOG; i++) {
        for(int j=1; j<=n; j++) {
            cnt[i][j] = cnt[i-1][j] + cnt[i-1][par[i-1][j]];
            dp[i][j] = dp[i-1][j] + dp[i-1][par[i-1][j]];
            par[i][j] = par[i-1][par[i-1][j]];
        }
    }
}

void dfs(int s, int e) {
    for(int i=0; i<graph[s].size(); i++) {
        int next = graph[s][i].first, dist = graph[s][i].second;
        if(next == e) continue;
        depth[next] = depth[s] + 1;
        cnt[0][next] = 1;
        par[0][next] = s, dp[0][next] = dist;
        dfs(next, s);
    }
}

void reset() {
    memset(dp, 0, sizeof(dp));
    memset(cnt, 0, sizeof(cnt));
    memset(par, 0, sizeof(par));
    memset(depth, 0, sizeof(depth));
}

void init() {
    ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    reset();
    cin >> n;
    for(int i=1; i<n; i++) {
        int x, y, d;
        cin >> x >> y >> d;
        graph[x].push_back(make_pair(y, d));
        graph[y].push_back(make_pair(x, d));
    }
    dp[0][1] = 0, par[0][1] = 0, depth[1] = 0, cnt[0][1] = 0;
    dfs(1, 0);
    make_sparse();
    cin >> m;
    for(int i=0; i<m; i++) {
        int order, u, v, k;
        cin >> order;
        if(order == 1) {
            cin >> u >> v;
            cout << lca(u, v, 1) << '\n';
        }
        else {
            cin >> u >> v >> k;
            ll tp = lca(u, v, 0), now = depth[u] - depth[tp];
            if(now >= k) {
                cout << finding(u, k-1) << '\n';
            }
            else {
                cout << finding(v, (depth[v] - depth[tp]) - (k - now) + 1) << '\n';
            }
        }
    }
}

int main() {
    init();
}
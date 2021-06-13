#include <iostream>
#include <vector>
#include <algorithm>
#define LOG 20
#define X first
#define Y second
using namespace std;
typedef pair<int, int> pii;
int n, m, maxi[100001][LOG+10], mini[100001][LOG+10], par[100001][LOG+10], depth[100001];
vector<pii> graph[100001];

void lca(int x, int y) {
    if(depth[x] < depth[y]) swap(x, y);
    int pmax = maxi[x][0], pmin = mini[x][0];
    for(int i=LOG-1; i>=0; i--) {
        if((depth[x] - depth[y]) >= (1<<i)) {
            pmax = max(pmax, maxi[x][i]), pmin = min(pmin, mini[x][i]);
            x = par[x][i];
        }
    }
    if(x == y) {
        cout << pmin << " " << pmax << '\n';
        return;
    }
    for(int i=LOG-1; i>=0; i--) {
        if(par[x][i] != par[y][i]) {
            pmax = max({pmax, maxi[x][i], maxi[y][i]}), pmin = min({pmin, mini[x][i], mini[y][i]});
            x = par[x][i], y = par[y][i];
        }
    }
    pmax = max({pmax, maxi[x][0], maxi[y][0]});
    pmin = min({pmin, mini[x][0], mini[y][0]});
    cout << pmin << " " << pmax << '\n';
}

void dynamic() {
    for(int i=1; i<LOG; i++) {
        for(int j=1; j<=n; j++) {
            mini[j][i] = min(mini[j][i-1], mini[par[j][i-1]][i-1]);
            maxi[j][i] = max(maxi[j][i-1], maxi[par[j][i-1]][i-1]);
            par[j][i] = par[par[j][i-1]][i-1];
        }
    }
}

void dfs(int s, int e) {
    for(int i=0; i<graph[s].size(); i++) {
        int next = graph[s][i].X, cost = graph[s][i].Y;
        if(next == e) continue;
        depth[next] = depth[s] + 1;
        par[next][0] = s, maxi[next][0] = cost, mini[next][0] = cost;
        dfs(next, s);
    }
}

void init() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=1; i<n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        graph[x].push_back(make_pair(y, z));
        graph[y].push_back(make_pair(x, z));
    }
    depth[1] = 0;
    dfs(1, 0);
    dynamic();
    cin >> m;
    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        lca(x, y);
    }
}

int main() {
    init();
}
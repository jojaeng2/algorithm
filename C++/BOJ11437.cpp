#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n, m, depth[50001], par[50001];
vector<int> graph[50001];

void find(int x, int y) {
    while(depth[x] != depth[y]) {
        if(depth[x] > depth[y]) x = par[x];
        else y = par[y];
    }
    while(x != y) {
        x = par[x], y = par[y];
    }
    cout << x << "\n";
}


void dfs(int s, int e) {
    par[s] = e;
    for(int i=0; i<graph[s].size(); i++) {
        int next = graph[s][i];
        if(next == e) continue;
        depth[next] = depth[s] + 1;
        dfs(next, s);
    }
}

void init() {
    memset(depth, -1, sizeof(depth));
    cin >> n;
    for(int i=1; i<n; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1, 0);
    cin >> m;
    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        find(x, y);
    }
}

int main() {
    init();
}
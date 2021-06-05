#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n, m, q, DP[100001];
vector<int> graph[100001];

int dfs(int s, int e) {
    for(int i=0; i<graph[s].size(); i++) {
        int next = graph[s][i];
        if(e == next) continue;
        DP[s] += dfs(next, s) + 1;
    }
    return DP[s];
}

void init() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> q;
    for(int i=1; i<n; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    memset(DP, 0, sizeof(DP));
    dfs(m, 0);
    for(int i=1; i<=q; i++) {
        int x;
        cin >> x;
        cout << DP[x]+1 << '\n';
    }
}

int main() {
    init();
}
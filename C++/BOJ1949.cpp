#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int n, DP[10001][2], num[10001];
vector<int> graph[10001];


int dfs(int s, int e, int before) {
    if(DP[s][before] != -1) return DP[s][before];
    if(before == 1) DP[s][1] = num[s];
    else DP[s][0] = 0;
    for(int i=0; i<graph[s].size(); i++) {
        int next = graph[s][i];
        if(next == e) continue;
        if(before == 0) DP[s][0] += max(dfs(next, s, 0), dfs(next, s, 1));
        else DP[s][1] += dfs(next, s, 0);
    }
    return DP[s][before];
}

void init() {
    memset(DP, -1, sizeof(DP));
    cin >> n;
    for(int i=1; i<=n; i++) cin >> num[i];
    for(int i=1; i<n; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
}

int main() {
    init();
    cout << max(dfs(1, 0, 0), dfs(1, 0, 1)) << '\n';
}
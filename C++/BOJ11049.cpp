#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
int n, dp[501][501];
vector<pii> v;

int dfs(int s, int e) {
    if(s == e) return 0;
    if(dp[s][e] != -1) return dp[s][e];
    dp[s][e] = 1e9;
    if(s+1 == e) return dp[s][e] = v[s].first * v[s].second * v[e].second;
    for(int i=s; i<e; i++) {
        dp[s][e] = min(dp[s][e], dfs(s, i) + dfs(i+1, e) + v[s].first * v[i].second * v[e].second);
    }
    return dp[s][e];
}

void init() {
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i=0; i<n; i++) {
        int l, r;
        cin >> l >> r;
        v.push_back(make_pair(l, r));
    }
}

int main() {
    init();
    cout << dfs(0, n-1) << '\n';
}
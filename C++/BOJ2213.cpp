#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int n, arr[10010], dp[2][10010], answer;
vector<int> graph[10010], res;

void print() {
    cout << answer << '\n';
    sort(res.begin(), res.end());
    for(int i=0; i<res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << '\n';
}

void trace(int s, int e, int before) {
    if(e == 1) res.push_back(s);
    for(int i=0; i<graph[s].size(); i++) {
        int next = graph[s][i];
        if(next == before) continue;
        if(e == 1) trace(next, 0, s);
        else {
            if(dp[1][next] > dp[0][next]) trace(next, 1, s);
            else trace(next, 0, s);
        }
    }
}

int dfs(int s, int e, int before) {
    if(dp[e][s] != -1) return dp[e][s];
    dp[e][s] = 0;
    if(e == 1) dp[e][s] += arr[s];
    for(int i=0; i<graph[s].size(); i++) {
        int next = graph[s][i];
        if(next == before) continue;
        if(e == 1) dp[e][s] += dfs(next, 0, s);
        else dp[e][s] += max(dfs(next, 1, s), dfs(next, 0, s));
    }
    return dp[e][s];
}

void init() {
    memset(arr, 0, sizeof(arr));
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i=1; i<=n; i++) cin >> arr[i];
    for(int i=1; i<n; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    answer = max(dfs(1, 0, 0), dfs(1, 1, 0));
    if(dp[1][1] == answer) trace(1, 1, 0);
    else trace(1, 0, 0);
}

int main() {
    init();
    print();
}
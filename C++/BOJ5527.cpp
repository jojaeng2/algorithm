#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n, arr[100001], dp[3][100001], answer = 0;

int dfs(int s, int now) {
    if(dp[now][s] != -1) return dp[now][s];
    if(s == n) return dp[now][s] = 1;
    dp[now][s] = 1;
    dfs(s+1, 0), dfs(s+1, 1), dfs(s+1, 2);
    if(now == 2 && arr[s] != arr[s+1]) dp[now][s] = dp[2][s+1] + 1;
    if(now == 1) {
        if(arr[s] != arr[s+1]) dp[now][s] = max(dp[now][s], dp[1][s+1] + 1);
        else dp[now][s] = max(dp[now][s], dp[2][s+1] + 1);
    }
    if(now==0) {
        if(arr[s] != arr[s+1]) dp[now][s] = max(dp[now][s], dp[0][s+1] + 1);
        else dp[now][s] = max(dp[now][s], dp[1][s+1] + 1);
    }
    return dp[now][s];
}

void init() {
    memset(arr, -1, sizeof(arr));
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i=1; i<=n; i++) cin >> arr[i];
    dfs(1, 1), dfs(1, 0);
    for(int i=0; i<3; i++) {
        for(int j=0; j<=n; j++) {
            answer = max(answer, dp[i][j]);
        }
    }
}

int main() {
    init();
    cout << answer << '\n';
}
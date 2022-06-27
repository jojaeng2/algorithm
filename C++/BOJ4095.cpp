#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m, dp[1001][1001], maxi = 0;

void init() {
    while(true) {
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        memset(dp, 0, sizeof(dp));
        maxi = 0;
        for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin >> dp[i][j];
        for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) {
            if(dp[i][j] != 0) {
                dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]);
                dp[i][j] = min(dp[i][j], dp[i][j-1]) + 1;
                maxi = max(maxi, dp[i][j]);
            }
        }
        cout << maxi << '\n';
    }   
}

int main() {
    init();
}
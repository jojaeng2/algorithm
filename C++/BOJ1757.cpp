#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m, DP[10001][501], dist[10001];

void dynamic() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) DP[i][j] = DP[i-1][j-1] + dist[i];
        for(int j=1; j<=m; j++) {
            if(i-j<0) break; 
            DP[i][0] = max({DP[i][0], DP[i-j][j], DP[i-j][0]});
        }
    }
    cout << DP[n][0] << '\n';
}

void init() {
    memset(DP, 0, sizeof(DP));
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> dist[i];
    }
}

int main() {
    init();
    dynamic();
}
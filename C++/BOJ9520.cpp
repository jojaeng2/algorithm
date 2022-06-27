#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 1e6
using namespace std;
int n, dist[1501][1501], DP[1501][1501];

void print() {
    int answer = INF;
    for(int i=0; i<n; i++) answer = min({answer, DP[n][i], DP[i][n]});
    cout << answer << '\n';
}

void dynamic() {
    DP[1][1] = 0;
    for(int i=2; i<=n; i++) {
        for(int j=1; j<i; j++) {
            DP[i][j] = min(DP[i][j], DP[i-1][j] + dist[i][i-1]);
            DP[i-1][i] = min(DP[i-1][i], DP[i-1][j] + dist[j][i]);
            DP[i][i-1] = min(DP[i][i-1], DP[j][i-1] + dist[i][j]);
            DP[j][i] = min(DP[j][i], DP[j][i-1] + dist[i][i-1]);
        }
    }
}

void init() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(DP, INF, sizeof(DP));
    cin >> n;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin >> dist[i][j];
}

int main() {
    init();
    dynamic();
    print();
}
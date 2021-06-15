#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n, psum[501], DP[501][501];

int dfs(int s, int e) {
    if(s == e) return 0;
    if(DP[s][e] != -1) return DP[s][e];
    DP[s][e] = 1e9;
    if(s > n) return DP[s][e];
    for(int i=s; i<e; i++) {
        DP[s][e] = min(DP[s][e], dfs(s, i) + dfs(i+1, e) + psum[e]-psum[s-1]);
    }
    return DP[s][e];
}

void init() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while(t--) {
        memset(psum, 0, sizeof(psum));
        memset(DP, -1, sizeof(DP));
        cin >> n;
        for(int i=1; i<=n; i++) {
            cin >> psum[i];
            psum[i] += psum[i-1];
        }
        cout << dfs(1, n) << '\n';
    }   
}

int main() {
    init();
}

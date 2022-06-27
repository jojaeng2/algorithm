#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
long long cnt, DP[101][21][2];
string ans, devil, angel;

int dfs(int s, int e, int n) {
    if(DP[s][e][n] != -1) return DP[s][e][n];
    if(e == ans.size()-1) return DP[s][e][n] = 1;
    DP[s][e][n] = 0;
    for(int i=s+1; i<devil.size(); i++) {
        if(n == 0 && angel[i] == ans[e+1]) DP[s][e][n] += dfs(i, e+1, 1);
        if(n == 1 && devil[i] == ans[e+1]) DP[s][e][n] += dfs(i, e+1, 0);
    }
    return DP[s][e][n];
}

void init() {
    memset(DP, -1, sizeof(DP));
    cin >> ans >> devil >> angel;
    for(int i=0; i<devil.size(); i++) {
        if(devil[i] == ans[0]) {
            dfs(i, 0, 0);
            cnt += DP[i][0][0];
        }
        if(angel[i] == ans[0]) {
            dfs(i, 0, 1);
            cnt += DP[i][0][1];
        }
    }
    cout << cnt << '\n';
}

int main() {
    init();
}
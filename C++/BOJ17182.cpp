#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int n, s, dp[11][11], mini = 1e9;
bool visit[11] = {false};
vector<int> v;

void print() {
    int psum = 0;
    for(int i=1; i<n; i++) {
        int now = v[i], bef = v[i-1];
        psum += dp[bef][now];
    }
    mini = min(mini, psum);
}

void dfs(int cnt) { 
    if(cnt == n) {
        print();
        return;
    }
    for(int i=0; i<n; i++) {
        if(visit[i]) continue;
        visit[i] = true;
        v.push_back(i);
        dfs(cnt+1);
        v.pop_back();
        visit[i] = false;
    }
}

void floyd() {
    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i==j) continue;
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
}

void init() {
    memset(dp, 0, sizeof(dp));
    cin >> n >> s;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> dp[i][j];
        }
    }
    visit[s] = true;
    v.push_back(s);
    floyd();
}

int main() {
    init();
    dfs(1);
    cout << mini << '\n';
}
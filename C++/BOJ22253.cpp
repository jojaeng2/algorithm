#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MOD 1000000007
#define NUM 100010
using namespace std;
typedef long long ll;
ll n, num[NUM], dp[2][NUM];
vector<int> graph[NUM];

ll dfs(int s, int e, int bef, int on) {
    if(dp[on][s] != -1) return dp[on][s];
    dp[on][s] = 0;
    if(on == 1) dp[on][s] = 1;
    for(int i=0; i<graph[s].size(); i++) {
        int next = graph[s][i];
        if(next == bef) continue;
        if(num[next] >= e) {
            dp[on][s] += dfs(next, num[next], s, 1);
            dp[on][s] += dfs(next, e, s, 0);

        }
        else dp[on][s] += dfs(next, e, s, 0);
        dp[on][s] %= MOD;
    }
    return dp[on][s]%MOD;
} 

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i=1; i<=n; i++) {
        int x;
        cin >> x;
        num[i] = x+1;
    }
    for(int i=1; i<n; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    cout << (dfs(1, num[1], -1, 1) + dfs(1, 0, -1, 0))%MOD << '\n';

}
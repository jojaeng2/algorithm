#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n;
ll dp[10010], ans, cnt[10010];
bool visit[10010];
vector<pii> graph[10010];

void dynamic(int s, ll bef) {
    for(int i=0; i<graph[s].size(); i++) {
        int next = graph[s][i].first, dis = graph[s][i].second; 
        if(visit[next]) continue;
        visit[next] =  true;
        dp[next] = (dp[s]-(cnt[next]*dis))+(n-cnt[next])*dis;
        ans = min(ans, dp[next]);
        dynamic(next, dp[next]);
    }
}

ll dfs(int s, int e) {
    cnt[s] = 1;
    dp[s] = 0;
    for(int i=0; i<graph[s].size(); i++) {
        int next = graph[s][i].first, dist = graph[s][i].second;
        if(next == e) continue;
        dp[s] += dfs(next, s);
        cnt[s] += cnt[next];
        dp[s] += (cnt[next] * dist);
    }
    return dp[s];
}

void init() {
    while(true) {
        for(int i=0; i<10001; i++) graph[i].clear();
        memset(dp, 0, sizeof(dp));
        memset(cnt, 0, sizeof(cnt));
        memset(visit, false, sizeof(visit));
        cin >> n;
        if(n == 0) break;
        for(int i=1; i<n; i++) {
            int x, y, d;
            cin >> x >> y >> d;
            graph[x].push_back(make_pair(y, d));
            graph[y].push_back(make_pair(x, d));
        }
        dfs(0, -1);
        ans = dp[0];
        visit[0] = true;
        dynamic(0, 0);
        cout << ans << '\n';
    }
}

int main() {
    init();
}
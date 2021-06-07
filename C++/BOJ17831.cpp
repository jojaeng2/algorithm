#include <iostream>
#include <vector>
#include <cstring>
#define NUM 200001
using namespace std;
typedef long long ll;
int n, per[NUM], DP[NUM][2];
vector<int> graph[NUM];

int dfs(int s, int conn) {
    if(DP[s][conn] != -1) return DP[s][conn];
    DP[s][conn] = 0;
    for(int i=0; i<graph[s].size(); i++) {
        int next = graph[s][i];
        DP[s][conn] += max(dfs(next, 0), dfs(next, 1));
    }
    if(conn == 1) {
        int maxi = 0;
        for(int i=0; i<graph[s].size(); i++) {
            int cpy_dp = DP[s][conn], next = graph[s][i];
            if(dfs(next, 0) > dfs(next, 1)) cpy_dp = max(DP[s][conn], DP[s][conn] + per[next] * per[s]);
            else cpy_dp = max(DP[s][conn], DP[s][conn] - dfs(next, 1) + dfs(next, 0) + per[next] * per[s]);
            maxi = max(maxi, cpy_dp);
        }
        DP[s][conn] = maxi;
    }
    return DP[s][conn];
}

void init() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(DP, -1, sizeof(DP));
    cin >> n;
    for(int i=2; i<=n; i++) {
        int x;
        cin >> x;
        graph[x].push_back(i);
    }
    for(int i=1; i<=n; i++) cin >> per[i];
}

int main() {
    init();
    cout << max(dfs(1,0), dfs(1, 1)) << '\n';
}
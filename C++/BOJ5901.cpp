#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <map>
#define INF 1e9
#define X first
#define Y second
using namespace std;
typedef pair<int, int> pii;
int n, m, k, visit[6][10001], answer = INF;
bool selected[5] = {false}, market_visit[10001] = {false};
vector<int> market, com;
vector<pii> graph[10001];
map<int, int> mp;

void dfs(int cnt) {
    if(cnt == k) {
        int dist = 0, mini = INF;
        for(int i=0; i<k-1; i++) dist += visit[mp[com[i]]][com[i+1]];
        
        for(int i=1; i<=n; i++) {
            if(market_visit[i]) continue;
            mini = min(mini, visit[mp[com[0]]][i] + visit[mp[com[k-1]]][i]);
        }
        
        dist += mini;
        answer = min(answer, dist);
    }
    for(int i=0; i<k; i++) {
        if(selected[i]) continue;
        selected[i] = true;
        com.push_back(market[i]);
        dfs(cnt+1);
        selected[i] = false;
        com.pop_back();
    }
}

void dijkstra(int s) {
    visit[s][market[s]] = 0;
    priority_queue<pii> pq;
    pq.push(make_pair(0, market[s]));
    while(!pq.empty()) {
        int dist = -pq.top().X, now = pq.top().Y;
        pq.pop();
        if(visit[s][now] < dist) continue;
        for(int i=0; i<graph[now].size(); i++) {
            int next = graph[now][i].X, cost = dist + graph[now][i].Y;
            if(visit[s][next] <= cost) continue;
            visit[s][next] = cost;
            pq.push(make_pair(-cost, next));
        }
    }
}

void init() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(visit, 1e4, sizeof(visit));
    cin >> n >> m >> k;
    for(int i=0; i<k; i++) {
        int x;
        cin >> x;
        market.push_back(x);
        market_visit[x] = true;
        mp.insert(make_pair(x, i));
    }
    for(int i=0; i<m; i++) {
        int x, y, d;
        cin >> x >> y >> d;
        graph[x].push_back(make_pair(y, d));
        graph[y].push_back(make_pair(x, d));
    }
    for(int i=0; i<k; i++) dijkstra(i);
}

int main() {
    init();
    dfs(0);
    cout << answer << '\n';
}
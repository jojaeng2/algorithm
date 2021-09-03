#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#define INF 1e11
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int n, m, on[100001];
ll visit[100001];
vector<pll> graph[100001];

void dijkstra(int start) {
    priority_queue<pll> pq;
    visit[start] = 0;
    pq.push(make_pair(0, start));
    while(!pq.empty()) {
        ll dist = -pq.top().X, now = pq.top().Y;
        pq.pop();
        if(visit[now] < dist) continue;
        for(int i=0; i<graph[now].size(); i++) {
            ll next = graph[now][i].X, cost = dist + graph[now][i].Y;
            if(visit[next] <= cost || (on[next] && next != n-1)) continue;
            visit[next] = cost;
            pq.push(make_pair(-cost, next));
        }
    }
}

void init() {
    fill(visit, visit+100001, INF);
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> on[i];
    for(int i=1; i<=m; i++) {
        int x, y, d;
        cin >> x >> y >> d;
        graph[x].push_back(make_pair(y, d));
        graph[y].push_back(make_pair(x, d));
    }
    dijkstra(0);
    if(visit[n-1]==INF) cout << -1 << '\n';
    else cout << visit[n-1] << '\n';
}

int main() {
    init();
}
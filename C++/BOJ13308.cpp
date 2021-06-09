#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#define X first
#define Y second
#define INF 1e4
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii, ll> piii;
ll n, m, oil[2501], visit[2501][2501];
vector<pii> graph[2501];

void print() {
    ll ans = visit[n][1];
    for(int i=1; i<=n; i++) {
        ans = min(ans, visit[n][oil[i]]);
    }
    cout << ans << '\n';
}


void dijkstra(int start) {
    priority_queue<piii, vector<piii>, greater<piii> > pq;
    pq.push({{0, start}, oil[start]});
    visit[start][oil[start]] = 0;
    while(!pq.empty()) {
        ll dist = pq.top().X.X, now = pq.top().X.Y, mini = pq.top().Y;
        pq.pop();
        if(visit[now][mini] < dist) continue;
        for(int i=0; i<graph[now].size(); i++) {
            ll next = graph[now][i].X, cost = graph[now][i].Y;
            if(visit[next][mini] <= dist + cost * mini) continue;
            visit[next][mini] = dist + cost * mini;
            pq.push({{visit[next][mini], next}, min(mini, oil[next])});
        }
    }
}

void init() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(visit, INF, sizeof(visit));
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> oil[i];
    for(int i=0; i<m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        graph[x].push_back({y, z});
        graph[y].push_back({x, z});
    } 
}

int main() {
    init();
    dijkstra(1);
    print();
}
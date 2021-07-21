#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#define INF 1e13 + 10
#define NUM 100010
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int n, m, d, e, h[NUM];
ll btm_visit[NUM], top_visit[NUM];
vector<pll> graph[NUM];

void print() {
    ll maxi = -INF*NUM;
    for(int i=2; i<n; i++) {
        maxi = max(maxi, h[i]*e - (btm_visit[i] + top_visit[i]) * d);
    }
    if(maxi == -INF*NUM) cout << "Impossible" << '\n';
    else cout << maxi << '\n'; 
}

void dijkstra(int s, ll visit[NUM]) {
    priority_queue<pll> pq;
    pq.push(make_pair(0, s));
    visit[s] = 0;
    while(!pq.empty()) {
        ll dist = -pq.top().X, now = pq.top().Y;
        pq.pop();
        if(visit[now] < dist) continue;
        for(int i=0; i<graph[now].size(); i++) {
            ll next = graph[now][i].X, cost = dist + graph[now][i].Y;
            if(h[next] <= h[now] || visit[next] <= cost) continue;
            visit[next] = cost;
            pq.push(make_pair(-cost, next));
        }
    }
}

void init() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fill(btm_visit, btm_visit + NUM, INF);
    fill(top_visit, top_visit + NUM, INF);
    cin >> n >> m >> d >> e;
    for(int i=1; i<=n; i++) cin >> h[i];
    for(int i=0; i<m; i++) {
        int x, y, d;
        cin >> x >> y >> d;
        graph[x].push_back(make_pair(y, d));
        graph[y].push_back(make_pair(x, d));
    }
}

int main() {
    init();
    dijkstra(1, btm_visit);
    dijkstra(n, top_visit);
    print();
}
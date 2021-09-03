#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#define X first
#define Y second
#define INF 1e13
using namespace std;
typedef long long ll;
typedef pair<pair<ll, int>, int> pli;
typedef pair<int, int> pii;
int n, m, a, b, k;
ll visit[101][1001], ans = 1e13;
vector<ll> magic[101];
vector<pii> graph[1001];

void print() {
    for(int i=0; i<=k; i++) ans = min(ans, visit[i][b]);
    cout << ans << '\n';
}

void dijkstra(int start) {
    priority_queue<pli> pq;
    visit[0][start] = 0;
    pq.push(make_pair(make_pair(0, start), 0));
    while(!pq.empty()) {
        ll dist = -pq.top().X.X;
        int now = pq.top().X.Y, cnt = pq.top().Y;
        pq.pop();
        if(visit[cnt][now]<dist) continue;
        for(int i=0; i<graph[now].size(); i++) {
            int next = graph[now][i].X, road = graph[now][i].Y;
            if(visit[cnt][next] > dist + magic[cnt][road-1]) {
                visit[cnt][next] = dist + magic[cnt][road-1];
                pq.push(make_pair(make_pair(-visit[cnt][next], next), cnt));
            }
        }
        if(cnt+1 <= k && visit[cnt+1][now] > dist) {
            visit[cnt+1][now] = dist;
            pq.push(make_pair(make_pair(-visit[cnt+1][now], now), cnt+1));
        }
    }
}

void init() {
    for(int i=0; i<101; i++) for(int j=0; j<1001; j++) visit[i][j] = INF;
    cin >> n >> m >> a >> b;
    for(int i=1; i<=m; i++) {
        int x, y;
        ll d;
        cin >> x >> y >> d;
        graph[x].push_back(make_pair(y, i));
        graph[y].push_back(make_pair(x, i));
        magic[0].push_back(d);
    }
    cin >> k;
    for(int i=1; i<=k; i++) {
        for(int j=1; j<=m; j++) {
            ll x;
            cin >> x;
            magic[i].push_back(x);
        }
    }
    dijkstra(a);
    print();
}

int main() {
    init();
}
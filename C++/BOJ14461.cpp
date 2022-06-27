#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#define INF 1e10
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<pair<pair<ll, int>, int>, int> pliii;
int n, m, graph[101][101], dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
ll visit[3][101][101];

void print() {
    ll answer = visit[0][n][n];
    for(int i=1; i<3; i++) answer = min(answer, visit[i][n][n]);
    cout << answer << '\n';
}

void dijkstra() {
    priority_queue<pliii> pq;
    visit[0][1][1] = 0;
    pq.push({{{0, 1}, 1}, 1});
    while(!pq.empty()) {
        ll dist = -pq.top().X.X.X;
        int x = pq.top().X.X.Y, y = pq.top().X.Y, cnt = pq.top().Y;
        pq.pop();
        if(visit[cnt][x][y] < dist) continue;
        for(int i=0; i<4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx<1 || ny<1 || nx>n || ny>n) continue;
            ll cost = dist + m;
            if(cnt == 0) cost += graph[nx][ny];
            if(visit[(cnt+1)%3][nx][ny] <= cost) continue;
            visit[(cnt+1)%3][nx][ny] = cost;
            pq.push({{{-cost, nx}, ny}, (cnt+1)%3});
        }
    }
}

void init() {
    ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    memset(visit, 1e4, sizeof(visit));
    cin >> n >> m;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin >> graph[i][j];
    dijkstra();
}

int main() {
    init();
    print();
}
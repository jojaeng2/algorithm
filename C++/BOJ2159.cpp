#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
#define INF 1e13
#define X first
#define Y second
#define NUM 100000
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, pii> plii;
int n, sx, sy, dx[5] = {0, -1, 1, 0, 0}, dy[5] = {0, 0, 0, -1, 1};
ll visit[5][NUM+10], answer = INF;
vector<pii> graph[5][NUM+10];
priority_queue<plii> pq;

void print() {
    for(int i=0; i<5; i++) answer = min(answer, visit[i][n]);
    cout << answer << '\n';
}

void dijkstra(int start) {
    visit[0][start] = 0;
    while(!pq.empty()) {
        ll dist = -pq.top().X, dir = pq.top().Y.X, now = pq.top().Y.Y;
        pq.pop();
        if(visit[dir][now] < dist) continue;
        for(int i=0; i<graph[dir][now].size(); i++) {
            int ndir = graph[dir][now][i].X, cost = graph[dir][now][i].Y;
            if(visit[ndir][now+1] <= cost + dist) continue;
            visit[ndir][now+1] = cost + dist;
            pq.push(make_pair(-(cost+dist), make_pair(ndir, now+1))); 
        }
    }
}

void init() {
    ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    for(int i=0; i<5; i++) fill(visit[i], visit[i]+100001, INF);
    cin >> n >> sx >> sy;
    for(int i=1; i<=n; i++) {
        int ex, ey;
        cin >> ex >> ey;
        if(i == 1) {
            for(int j=0; j<5; j++) {
                int nx = ex + dx[j], ny = ey + dy[j];
                if(nx<1 || ny<1 || nx>NUM || ny>NUM) continue;
                pq.push(make_pair(-(abs(sx-nx) + abs(sy-ny)), make_pair(j, i)));
                visit[j][i] = abs(sx-nx) + abs(sy-ny);
            }
            sx = ex, sy = ey;
        }
        else {
            for(int j=0; j<5; j++) {
                int ssx = sx + dx[j], ssy = sy + dy[j];
                if(ssx<1 || ssy<1 || ssx>NUM || ssy>NUM) continue;
                for(int k=0; k<5; k++) {
                    int nx = ex + dx[k], ny = ey + dy[k];                
                    if(nx<1 || ny<1 || nx>NUM || ny>NUM) continue;
                    graph[j][i-1].push_back(make_pair(k, abs(ssx-nx) + abs(ssy - ny)));
                }
            }
            sx = ex, sy = ey;
        }
    }
}

int main() {
    init();
    dijkstra(0);
    print();
}
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 1e9
#define X first
#define Y second
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int n, m, visit[110][110], f, t;
ll ans = 3*INF;
vector<int> graph[110];


void dijkstra(int start) {
    priority_queue<pii> pq;
    pq.push(make_pair(0, start));
    visit[start][start] = 0;
    while(!pq.empty()) {
        int dist = -pq.top().X, now = pq.top().Y;
        pq.pop();
        if(visit[start][now] < dist) continue;
        for(int i=0; i<graph[now].size(); i++) {
            int next = graph[now][i];
            if(visit[start][next] <= dist+1) continue;
            visit[start][next] = dist + 1;
            pq.push(make_pair(-visit[start][next], next));
        }
    }
}

void init() {
    cin >> n >> m;
    for(int i=0; i<110; i++) for(int j=0; j<110; j++) visit[i][j] = INF;
    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(int i=1; i<=n; i++) dijkstra(i);
    for(int i=1; i<n; i++) {
        for(int j=i+1; j<=n; j++) {
            int psum = 0;
            for(int k=1; k<=n; k++) {
                if(k == i || k == j) continue;
                psum += min(visit[i][k], visit[j][k]);
            }
            if(ans>psum) {
                ans = psum;
                f = i, t = j;
            }
        }
    }
    cout << f << " " << t << " " << ans*2 << '\n';
}

int main() {
    init();
}
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> pii;
int n, m, s, e, res, conn[10001], maxi[10001], cnt = 0;
vector<pii> graph[10001], back[10001];
bool visit[10001] = {false};

void dfs(int start, int psum) {
    visit[start] = true;
    for(int i=0; i<back[start].size(); i++) {
        int next = back[start][i].X, cost = back[start][i].Y;
        if(maxi[next] + psum + cost == res) {
            cnt++;
            if(visit[next]) continue;
            dfs(next, psum + cost);
        }
    }
}

void topo() {
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(int i=0; i<graph[now].size(); i++) {
            int next = graph[now][i].X, cost = graph[now][i].Y;
            maxi[next] = max(maxi[next], maxi[now] + cost);
            conn[next]--;
            if(conn[next] == 0) q.push(next);
        }
    }
    res = maxi[e];
}

void init() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(conn, 0, sizeof(conn));
    memset(maxi, 0, sizeof(maxi));
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int x, y, dist;
        cin >> x >> y >> dist;
        conn[y]++;
        graph[x].push_back(make_pair(y, dist));
        back[y].push_back(make_pair(x, dist));
    }
    cin >> s >> e;
}

int main() {
    init();
    topo();
    cout << res << '\n';
    dfs(e, 0);
    cout << cnt << '\n';
}
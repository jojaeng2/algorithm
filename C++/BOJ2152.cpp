#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int n, m, s, e;
int dfsn[10001], sccn[10001], sccnt, cnt, cycle[10001], answer[10001], conn[10001];
bool visit[10001], start_visit[10001];
vector<int> graph[10001], topo[10001];
stack<int> stak;
queue<int> q;

void topolo() {
    for(int i=1; i<=n; i++) {
        for(int j=0; j<graph[i].size(); j++) {
            int u = graph[i][j];
            if(sccn[i] != sccn[u]) {
                conn[sccn[u]]++;
                topo[sccn[i]].push_back(sccn[u]);
            }
        }
    }
    for(int i=1; i<sccnt; i++) {
        if(conn[i] == 0) {
            q.push(i);
            answer[i] = cycle[i];
            if(i == sccn[s]) start_visit[i] = true;
        }
    }
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(int i=0; i<topo[now].size(); i++) {
            int next = topo[now][i];
            conn[next]--;
            if(start_visit[now]) {
                answer[next] = max(answer[next], answer[now]);
                start_visit[next] = true;
            }
            if(next == sccn[s]) {
                answer[next] = cycle[next];
                start_visit[next] = true;
            }
            if(conn[next] == 0) {
                q.push(next);
                answer[next] += cycle[next];
            }

        }
    }
    if(!start_visit[sccn[e]]) cout << 0 << '\n';
    else cout << answer[sccn[e]] - answer[sccn[s]] + cycle[sccn[s]] << '\n';
}

int dfs(int start) {
    dfsn[start] = cnt++;
    int res = dfsn[start];
    stak.push(start);
    for(int i=0; i<graph[start].size(); i++) {
        int next = graph[start][i];
        if(dfsn[next] == 0) res = min(res, dfs(next));
        else if(!visit[next]) res = min(res, dfsn[next]);
    }
    if(res == dfsn[start]) {
        while(true) {
            int now = stak.top();
            stak.pop();
            visit[now] = true;
            sccn[now] = sccnt;
            cycle[sccnt]++;
            if(now == start) break;
        }
        sccnt++;
    }
    return res;
}

void reset() {
    memset(dfsn, 0, sizeof(dfsn));
    memset(sccn, 0, sizeof(sccn));
    memset(visit, false, sizeof(visit));
    memset(cycle, 0, sizeof(cycle));
    memset(answer, 0, sizeof(answer));
    memset(conn, 0, sizeof(conn));
    memset(start_visit, false, sizeof(start_visit));
    cnt = 1, sccnt = 1;
}

void init() {
    ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    reset();
    cin >> n >> m >> s >> e;
    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }
    for(int i=1; i<=n; i++) {
        if(dfsn[i] == 0) dfs(i);
    }
}   

int main() {
    init();
    topolo();
}
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stack>
#define NUM 100010
using namespace std;
int n, m, cnt, dfsn[NUM], scc[NUM], sccnt, conn[NUM], answer = 0;
bool visit[NUM] = {false};
vector<int> graph[NUM];
stack<int> stak;

void topo() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<graph[i].size(); j++) {
            int next = graph[i][j];
            if(scc[i] != scc[next]) conn[scc[next]]++;
        }
    }
    for(int i=1; i<sccnt; i++) if(conn[i] == 0) answer++;
    cout << answer << '\n';
}

int dfs(int s) {
    dfsn[s] = cnt++;
    int res = dfsn[s];
    stak.push(s);

    for(int i=0; i<graph[s].size(); i++) {
        int next = graph[s][i];
        if(dfsn[next] == 0) res = min(res, dfs(next));
        else if(!visit[next]) res = min(res, dfsn[next]);
    }
    if(res == dfsn[s]) {
        while(true) {
            int now = stak.top();
            stak.pop();
            visit[now] = true;
            scc[now] = sccnt;
            if(now == s) break;
        }
        sccnt++;
    }
    return res;
}

void reset() {
    cnt = 1, sccnt = 1;
    memset(dfsn, 0, sizeof(dfsn));
    memset(scc, 0, sizeof(scc));
    memset(conn, 0, sizeof(conn));
}

void init() {
    ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    reset();
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int s, e;
        cin >> s >> e;
        graph[s].push_back(e);
    }
    for(int i=0; i<n; i++) if(dfsn[i] == 0) dfs(i);
}

int main() {
    init();
    topo();
}
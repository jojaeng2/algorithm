#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#define NUM 500010
using namespace std;
int n, m, cost[NUM], start, k, dfsn[NUM], cnt = 1, sccnt = 1, scc[NUM], conn[NUM], scc_cost[NUM], result[NUM];
bool visit[NUM] = {false}, conn_visit[NUM] = {false};
vector<int> graph[NUM], topo[NUM], dat;
stack<int> stak;
queue<int> q;

void reset() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(cost, 0, sizeof(cost));
    memset(dfsn, 0, sizeof(dfsn));
    memset(scc, 0, sizeof(scc));
    memset(conn, 0, sizeof(conn));
    memset(scc_cost, 0, sizeof(scc_cost));
    memset(result, 0, sizeof(result));
}

void print() {
    int answer = 0;
    for(int i=0; i<k; i++) {
        int x;
        cin >> x;
        answer = max(answer, result[scc[x]]);
    }
    cout << answer << '\n';
}

void conn_dfs(int s) {
    if(conn_visit[s]) return;
    conn_visit[s] = true;
    for(int i=0; i<graph[s].size(); i++) {
        int next = graph[s][i];
        if(scc[next] != scc[s]) {
            conn[scc[next]]++;
            topo[scc[s]].push_back(scc[next]);
        }
        conn_dfs(next);
    }
}

void solve() {
    conn_dfs(start);
    q.push(scc[start]);
    result[scc[start]] = scc_cost[scc[start]];
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(int i=0; i<topo[now].size(); i++) {
            int next = topo[now][i];
            conn[next]--;
            result[next] = max(result[next], result[now] + scc_cost[next]);
            if(conn[next] == 0) q.push(next);
        }
    }
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
            scc_cost[sccnt] += cost[now];
            if(now == s) break;
        } 
        sccnt++;
    }
    return res;
}


void init() {
    reset();
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }
    for(int i=1; i<=n; i++) cin >> cost[i]; 
    for(int i=1; i<=n; i++) if(dfsn[i] == 0) dfs(i);
    cin >> start >> k;
}

int main() {
    init();
    solve();
    print();
}

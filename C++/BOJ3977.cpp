#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;
vector<int> graph[100001], answer;
int t, n, m, dfsn[100001], cnt, scc[100001], sccnt, conn[100001];
bool visit[100001], conn_visit[100001];
stack<int> stak;

void reset() {
    for(int i=0; i<100001; i++) graph[i].clear();
    memset(dfsn, 0, sizeof(dfsn));
    memset(scc, 0, sizeof(scc));
    memset(conn, 0, sizeof(conn));
    memset(visit, false, sizeof(visit));
    memset(conn_visit, false, sizeof(conn_visit));
    answer.clear();
    cnt = 1, sccnt = 1;
    while(!stak.empty()) {
        stak.pop();
    }
}

int dfs(int s) {
    dfsn[s] = cnt++;
    stak.push(s);
    int res = dfsn[s];

    for(int i=0; i<graph[s].size(); i++) {
        int next = graph[s][i];
        if(dfsn[next] == 0) res = min(res, dfs(next));
        else if(!visit[next])res = min(res, dfsn[next]);
    }
    if(res == dfsn[s]) {
        while(true) {
            int now = stak.top();
            stak.pop();
            scc[now] = sccnt;
            visit[now] = true;
            if(now == s) break;
        }
        sccnt++;
    }
    return res;
}

void init() {
    ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> t;
    while(t--) {
        reset();
        cin >> n >> m;
        for(int i=0; i<m; i++) {
            int s, e;
            cin >> s >> e;
            graph[s].push_back(e);
        }
        for(int i=0; i<n; i++) {
            if(dfsn[i] == 0) dfs(i);
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<graph[i].size(); j++) {
                int u = graph[i][j];
                if(scc[i] != scc[u]) conn[scc[u]]++;
            }
        }
        int isans = 0, log;
        for(int i=1; i<sccnt; i++) {
            if(conn[i] == 0 && !conn_visit[i]) {
                conn_visit[i] = true;
                log = i;
                isans++;
            }
        }
        if(isans > 1) cout << "Confused" << '\n';
        else {
            for(int i=0; i<n; i++) {
                if(scc[i] == log) answer.push_back(i);
            }
            sort(answer.begin(), answer.end());
            for(int i=0; i<answer.size(); i++) {
                cout << answer[i] << '\n';
            }
        }
        cout << '\n';
    }
}

int main() {
    init();
}
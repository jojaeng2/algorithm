#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;
int n, dfsn[2510], scc[2510], cnt, sccnt, node_cnt, conn[2510];
ll answer[2510];
bool visit[2510];
vector<int> graph[2510];
map<string, int> m;
stack<int> stak;
queue<int> q;

void print() {
    string s;
    cin >> s;
    cout << answer[m[s]] << '\n';
}

void solve() {
    for(int i=1; i<node_cnt; i++) {
        for(int j=0; j<graph[i].size(); j++) {
            int next = graph[i][j];
            if(scc[i] != scc[next]) conn[next]++;
        }
    }
    for(int i=1; i<node_cnt; i++) {
        if(conn[i] == 0) q.push(i);
    }
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(int i=0; i<graph[now].size(); i++) {
            int next = graph[now][i];
            if(scc[now] != scc[next]) {
                answer[next] += answer[now];
                conn[next]--;
                if(conn[next] == 0) q.push(next);
            }
        }
    }
}

void reset() {
    memset(dfsn, 0, sizeof(dfsn));
    memset(scc, 0, sizeof(scc));
    memset(conn, 0, sizeof(conn));
    fill(answer, answer+2500, 1);
    memset(visit, false, sizeof(visit));
    cnt = 1, sccnt = 1, node_cnt = 1;
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
            scc[now] = sccnt;
            if(now == start) break;
        }
        sccnt++;
    }
    return res;
}

void init() {
    ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    reset();
    cin >> n;
    for(int i=0; i<n; i++) {
        string s;
        int num;
        cin >> s >> num;
        if(m.find(s) == m.end()) m.insert(make_pair(s, node_cnt++));
        for(int j=0; j<num; j++) {
            string k;
            cin >> k;
            if(m.find(k) == m.end()) m.insert(make_pair(k, node_cnt++));
            graph[m[k]].push_back(m[s]);
        }
    }
    for(int i=1; i<node_cnt; i++) {
        if(dfsn[i] == 0) dfs(i);
    }
}

int main() {
    init();
    solve();
    print();
}
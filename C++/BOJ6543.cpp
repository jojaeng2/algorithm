#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
int n, m, dfsn[5001], scc[5001], cnt, sccnt, conn[5001], ans;
bool visit[5001];
vector<int> graph[5001], answer;
stack<int> st;

void print() {
    for(int i=0; i<answer.size(); i++) {
        cout << answer[i] << ' ';
    }
    cout << '\n';
}

void topo() {
    for(int i=1; i<=n; i++) for(int j=0; j<graph[i].size(); j++) {
        int next = graph[i][j];
        if(scc[i] == scc[next]) continue;
        conn[scc[i]]++;
    }
    for(int i=1; i<sccnt; i++) {
        if(conn[i] != 0) continue;
        for(int j=1; j<=n; j++) {
            if(scc[j] == i) answer.push_back(j);
        }
    }
    sort(answer.begin(), answer.end());
}

int dfs(int s) {
    dfsn[s] = cnt++;
    int res = dfsn[s];
    st.push(s);
    for(int i=0; i<graph[s].size(); i++) {
        int next = graph[s][i];
        if(dfsn[next] == 0) res = min(res, dfs(next));
        else if(!visit[next]) res = min(res, dfsn[next]);
    }
    if(dfsn[s] == res) {
        while(true) {
            int now = st.top();
            st.pop();
            visit[now] = true;
            scc[now] = sccnt;
            if(now == s) break;
        }
        sccnt++;
    }   
    return res;
}

void reset() {
    memset(dfsn, 0, sizeof(dfsn));
    memset(scc, 0, sizeof(scc));
    memset(conn, 0, sizeof(conn));
    memset(visit, false, sizeof(visit));
    for(int i=0; i<5001; i++) graph[i].clear();
    answer.clear();
    cnt = 1, sccnt = 1, ans = 0;
}

void init() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(true) {
        cin >> n;
        if(n==0) break;
        cin >> m;
        reset();
        for(int i=0; i<m; i++) {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
        }
        for(int i=1; i<=n; i++) if(dfsn[i] == 0) dfs(i);
        topo();
        print();
    }
}

int main() {
    init();
}
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
using namespace std;
int n, cost[101], dfsn[101], cnt = 1, sccn[101], sccnt = 1, mini[101], answer = 0;
bool visit[101] = {false};
vector<int> graph[101];
stack<int> stak;

void print() {
    for(int i=1; i<=n; i++) mini[sccn[i]] = min(mini[sccn[i]], cost[i]);
    for(int i=1; i<sccnt; i++) answer += mini[i];
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
        while(!stak.empty()) {
            int now = stak.top();
            stak.pop();
            sccn[now] = sccnt;
            visit[now] = true;
            if(now == s) break;
        }
        sccnt++;
    }
    return res;
}

void reset() {
    memset(mini, 1e4, sizeof(mini));
    memset(sccn, 0, sizeof(sccn));
    memset(cost, 0, sizeof(cost));
    memset(dfsn, 0, sizeof(dfsn));
}

void init() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    reset();
    cin >> n;
    for(int i=1; i<=n; i++) cin >> cost[i];
    for(int i=1; i<=n; i++) {
        string s;
        cin >> s;
        for(int j=0; j<n; j++) {
            if(s[j] == '1') graph[i].push_back(j+1);
        }
    }
    for(int i=1; i<=n; i++) {
        if(dfsn[i] == 0) dfs(i);
    }
}

int main() {
    init();
    print();
}
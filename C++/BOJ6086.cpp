#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAX_V 52
#define INF 1e9
using namespace std;
int n, full[MAX_V][MAX_V], now_full[MAX_V][MAX_V], answer = 0;
vector<int> graph[MAX_V];

int alpha(char a) {
    if(a <= 'Z') return a - 'A';
    return a - 'a' + 26;
}

void bfs() {
    int s = alpha('A'), e = alpha('Z');
    while(true) {
        int prev[MAX_V];
        memset(prev, -1, sizeof(prev));
        queue<int> q;
        q.push(s);
        while(!q.empty() && prev[e] == -1) {
            int now = q.front();
            q.pop();
            for(int i=0; i<graph[now].size(); i++) {
                int next = graph[now][i];
                if(full[now][next] - now_full[now][next] > 0 && prev[next] == -1) {
                    q.push(next);
                    prev[next] = now;
                    if(next == e) break;
                }
            }
        }
        if(prev[e] == -1) break;
        
        int flow = INF;
        for(int i=e; i!=s; i=prev[i]) flow = min(flow, full[prev[i]][i] - now_full[prev[i]][i]);
        for(int i=e; i!=s; i=prev[i]) {
            now_full[prev[i]][i] += flow;
            now_full[i][prev[i]] -= flow;
        }
        answer += flow;
    }
}

void init() {
    ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    memset(full, 0, sizeof(full));
    memset(now_full, 0, sizeof(now_full));
    cin >> n;
    for(int i=0; i<n; i++) {
        char u, v;
        int d;
        cin >> u >> v >> d;
        int nu = alpha(u), nv = alpha(v);
        full[nu][nv] += d;
        full[nv][nu] += d;
        graph[nu].push_back(nv);
        graph[nv].push_back(nu);
    }
}

int main() {
    init();
    bfs();
    cout << answer << '\n';
}
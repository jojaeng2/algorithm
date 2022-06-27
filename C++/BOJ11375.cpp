#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 1e9
#define NUM 2010
using namespace std;
int n, m, c[NUM][NUM], f[NUM][NUM], s = 0, e = 2001, answer = 0;
vector<int> graph[NUM];

void bfs() {
    while(true) {
        int prev[NUM];
        memset(prev, -1, sizeof(prev));
        queue<int> q;
        q.push(s);
        while(!q.empty() && prev[e] == -1) {
            int now = q.front();
            q.pop();
            for(int i=0; i<graph[now].size(); i++) {
                int next = graph[now][i];
                if(c[now][next] - f[now][next] > 0 && prev[next] == -1) {
                    q.push(next);
                    prev[next] = now;
                    if(next == e) break;
                }
            }
        }
        if(prev[e] == -1) break;
        int flow = INF;
        for(int i=e; i!=s; i=prev[i]) flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
        for(int i=e; i!=s; i=prev[i]) {
            f[prev[i]][i] += flow;
            f[i][prev[i]] -= flow;
        }
        answer += flow;
    }
}

void init() {
    ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    memset(c, 0, sizeof(c));
    memset(f, 0, sizeof(f));
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        int x;
        cin >> x;
        graph[s].push_back(i);
        graph[i].push_back(s);
        c[s][i]++;
        for(int j=0; j<x; j++) {
            int y;
            cin >> y;
            graph[i].push_back(y+1000);
            graph[y+1000].push_back(i);
            c[i][y+1000]++;
        }
    }
    for(int i=1; i<=m; i++) {
        graph[i+1000].push_back(e);
        graph[e].push_back(i+1000);
        c[i+1000][e]++;
    }
}

int main() {
    init();
    bfs();
    cout << answer << '\n';
}
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define NUM 2000
using namespace std;
int n, m, k, c[NUM+10][NUM+10], f[NUM+10][NUM+10], s = NUM+1, mid = NUM+2, e = NUM+3, answer =0 ;
vector<int> graph[NUM+10];

void bfs() {
    while(true) {
        int prev[NUM+10];
        memset(prev, -1, sizeof(prev));
        queue<int> q;
        q.push(s);
        while(!q.empty() && prev[e] == -1) {
            int now = q.front();
            q.pop();
            for(int i=0; i<graph[now].size(); i++) {
                int next = graph[now][i];
                if((c[now][next] - f[now][next]) > 0 && prev[next] == -1) {
                    q.push(next);
                    prev[next] = now;
                    if(next == e) break;
                }
            }
        }
        if(prev[e] == -1) break;
        int flow = 1e9;
        for(int i=e; i!=s; i=prev[i]) flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
        for(int i=e; i!=s; i=prev[i]) {
            f[prev[i]][i] += flow;
            f[i][prev[i]] -= flow;
        }
        answer += flow;
    }
}

void init() {
    memset(c, 0, sizeof(c));
    memset(f, 0, sizeof(f));
    cin >> n >> m >> k;
    graph[s].push_back(mid);
    graph[mid].push_back(s);
    c[s][mid] = k;
    for(int i=1; i<=n; i++) {
        int x; 
        cin >> x;
        graph[s].push_back(x);
        graph[x].push_back(s);
        graph[mid].push_back(x);
        graph[x].push_back(mid);
        c[mid][x] += k;
        c[s][x]++;
        for(int j=0; j<x; j++) {
            int y;
            cin >> y;
            graph[x].push_back(y+NUM/2);
            graph[y+NUM/2].push_back(x);
            c[x][y+NUM/2]++;
        }
    }
    for(int i=1; i<=m; i++) {
        graph[i+NUM/2].push_back(e);
        graph[e].push_back(i+NUM/2);
        c[i+NUM/2][e]++;
    }
}

int main() {
    init();
    bfs();
    cout << answer << '\n';
}
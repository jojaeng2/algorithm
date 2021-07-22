#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9
using namespace std;
int n, m, ldir[410][410], rdir[410][410], answer = 0, s = 0, e = 401;
vector<int> graph[410];

void bfs() {
    while(true) {
        int prev[410];
        memset(prev, -1, sizeof(prev));
        queue<int> q;
        q.push(s);
        while(!q.empty() && prev[e] == -1) {
            int now = q.front();
            q.pop();
            for(int i=0; i<graph[now].size(); i++) {
                int next = graph[now][i];
                if(ldir[now][next] - rdir[now][next] > 0 && prev[next] == -1) {
                    q.push(next);
                    prev[next] = now;
                    if(next == e) break;
                }
            }
        }
        if(prev[e] == -1) break;

        for(int i=e; i!=s; i=prev[i]) {
            rdir[prev[i]][i]++;
            rdir[i][prev[i]]--;
            cout << i << " " << prev[i] << " " << rdir[prev[i]][i] << " " << rdir[i][prev[i]] << '\n';
        }
        answer++;
    }
    cout << answer << '\n';
}

void init() {
    memset(ldir, 0, sizeof(ldir));
    memset(rdir, 0, sizeof(rdir));
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        int x;
        cin >> x;
        graph[s].push_back(i), graph[i].push_back(s);
        ldir[s][i]++;
        for(int j=0; j<x; j++) {
            int y;
            cin >> y;
            ldir[i][y+200]++;
            ldir[y+200][e] = 1;
            graph[i].push_back(y+200), graph[y+200].push_back(i);
        }
    }
    for(int i=1; i<=m; i++) {
        graph[e].push_back(i+200);
        graph[i+200].push_back(e);
    }
}

int main() {
    init();
    bfs();
}
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <vector>
#include <string>
#define INF 1e9
#define X first
#define Y second
using namespace std;
typedef pair<int, int> pii;
int n, k, par[1001], visit[1001], s, e;
string st[1001];
vector<int> graph[1001], ans;

void print() {
    if(visit[e] == INF) ans.push_back(-1);
    else {
        for(int i=e; i!=s; i=par[i]) {
            ans.push_back(i);
        }
        ans.push_back(s);
    }
    for(int i=ans.size()-1; i>=0; i--) {
        cout << ans[i] << ' ';
    }
}

void dijkstra(int start) {
    priority_queue<pii> pq;
    pq.push(make_pair(0, start));
    visit[start] = 0;
    while(!pq.empty()) {
        int dist = -pq.top().X, now = pq.top().Y;
        pq.pop();
        if(visit[now] < dist) continue;
        for(int i=0; i<graph[now].size(); i++) {
            int next = graph[now][i];
            if(visit[next] <= visit[now]+1) continue;
            visit[next] = visit[now] + 1;
            par[next] = now;
            pq.push(make_pair(-visit[next], next));
        }
    }
}

void init() {
    fill(visit, visit+1000, INF);
    cin >> n >> k;
    for(int i=1; i<=n; i++) {
        cin >> st[i];
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i==j) continue;
            int cnt = 0;
            for(int p=0; p<k; p++) if(st[i][p] != st[j][p]) cnt++;
            if(cnt == 1) {
                graph[j].push_back(i);
                graph[i].push_back(j);
            }
        }
    }
    cin >> s >> e;
    dijkstra(s);
    print();
}

int main() {
    init();
}


